#include "fileuploader.h"
#include "../../autogenerated/telegramapi.h"
#include "../../types/telegramhelper.h"
#include "../../crypto/hash.h"
#include "../../crypto/math.h"
#include <QImageReader>
#include <QFileInfo>
#include <QImage>
#include <QDir>
#include <QFile>

#define MaxParts                   3000
#define MaxPartIndex               2999
#define BlockSize                  (32 * 1024)
#define TenMegaBytes               (10 * 1024 * 1024)
#define ImageMaxResolution         1280               // Max returned resolution: 1280x1280
//#define ImageCompressionTreshold 5000               // Telegram needs max 5000x5000

QMimeDatabase FileUploader::_mimedb;

FileUploader::FileUploader(const QString& filepath, MediaType mediatype, const QString &storagepath, QObject *parent) : QObject(parent), _storagepath(storagepath)
{
    this->_dcsession = NULL;

    this->_partsize = BlockSize;
    this->_partscount = 0;
    this->_partnum = 0;
    this->_filesize = 0;

    this->_isbigfile = false;
    this->_deleteoncompleted = false;

    this->_filepath = filepath;
    this->_mediatype = mediatype;
    this->_localfileid = Math::randomize<TLLong>();

    this->analyzeFile(filepath);
}

FileUploader::~FileUploader()
{
    if(this->_dcsession)
    {
        DC_CloseSession(this->_dcsession);
        this->_dcsession = NULL;
    }

    if(this->_file.isOpen())
        this->_file.close();
}

TLLong FileUploader::localFileId() const
{
    return this->_localfileid;
}

const QString &FileUploader::filePath() const
{
    return this->_filepath;
}

const QString &FileUploader::fileName() const
{
    return this->_filename;
}

const QSize &FileUploader::imageSize() const
{
    return this->_imagesize;
}

InputMedia *FileUploader::createInputMedia() const
{
    if(this->_mediatype == FileUploader::MediaPhoto)
        return this->createInputMediaPhoto();
    else if(this->_mediatype == FileUploader::MediaDocument)
        return this->createInputMediaDocument();

    qWarning("FileUploader: Unknown media type: %d", this->_mediatype);
    return NULL;
}

Photo *FileUploader::createPhoto() const
{
    Photo* photo = new Photo();
    photo->setConstructorId(TLTypes::PhotoEmpty);
    photo->setId(this->_localfileid);

    return photo;
}

Document *FileUploader::createDocument() const
{
    Document* document = new Document();
    document->setConstructorId(TLTypes::Document);
    document->setId(this->_localfileid);
    document->setDate(CurrentTimeStamp);
    document->setMimeType(this->_mimetype);
    document->setSize(this->_filesize);

    TLVector<DocumentAttribute*> attributes;
    this->createDocumentAttributes(attributes, document);
    document->setAttributes(attributes);

    return document;
}

InputFile *FileUploader::createInputFile() const
{
    InputFile* inputfile = new InputFile();
    inputfile->setId(this->_localfileid);
    inputfile->setParts(this->_partscount);
    inputfile->setName(this->_filename);

    if(!this->_isbigfile)
    {
        inputfile->setConstructorId(TLTypes::InputFile);
        inputfile->setMd5Checksum(this->_md5hash);
    }
    else
        inputfile->setConstructorId(TLTypes::InputFileBig);

    return inputfile;
}

InputMedia *FileUploader::createInputMediaPhoto() const
{
    InputMedia* inputmedia = new InputMedia();
    inputmedia->setConstructorId(TLTypes::InputMediaUploadedPhoto);
    inputmedia->setCaption(this->_caption);
    inputmedia->setFile(this->createInputFile());

    return inputmedia;
}

InputMedia *FileUploader::createInputMediaDocument() const
{
    InputMedia* inputmedia = new InputMedia();
    inputmedia->setConstructorId(TLTypes::InputMediaUploadedDocument);
    inputmedia->setFile(this->createInputFile());
    inputmedia->setMimeType(this->_mimetype);
    inputmedia->setCaption(this->_caption);

    TLVector<DocumentAttribute*> attributes;
    this->createDocumentAttributes(attributes, inputmedia);
    inputmedia->setAttributes(attributes);

    return inputmedia;
}

void FileUploader::createDocumentAttributes(TLVector<DocumentAttribute *> &attributes, QObject* parent) const
{
    attributes << TelegramHelper::createDocumentAttribute(this->_filename, parent);

    if(!this->_imagesize.isEmpty())
        attributes << TelegramHelper::createDocumentAttribute(this->_imagesize, parent);
}

qreal FileUploader::progress() const
{
    return this->_partnum / static_cast<qreal>(this->_partscount);
}

bool FileUploader::uploading() const
{
    return (this->_partnum > 0) && (this->_partnum < this->_partscount);
}

void FileUploader::setCaption(const QString &caption)
{
    this->_caption = caption;
}

void FileUploader::upload()
{
    if((this->_mediatype == FileUploader::MediaPhoto))
        this->scaleImageIfNeeded();

    if(!this->calculatePartsLength())
        return;

    this->calculatePartsCount();
    this->_file.setFileName(this->_filepath);

    if(!this->_file.open(QFile::ReadWrite))
    {
        qWarning("UPLOAD Cannot open %s", qUtf8Printable(this->_filepath));
        emit failed();
        return;
    }

    if(!this->_isbigfile)
    {
        this->_md5hash = md5_hash_hex(this->_file.readAll());
        this->_file.reset();
    }

    this->_dcsession = DC_CreateFileSession(DCConfig_mainConfig);
    connect(this->_dcsession, &DCSession::ready, this, &FileUploader::uploadPart);
    DC_InitializeSession(this->_dcsession);
}

bool FileUploader::calculatePartsLength()
{
    TLInt val = (this->_filesize + MaxPartIndex) / MaxParts;

    while(this->_partsize < val)
        this->_partsize *= 2;

    if(this->_partsize > (512 << 10))
    {
        qWarning("UPLOAD File too big");
        emit failed();
        return false;
    }

    return true;
}

void FileUploader::calculatePartsCount()
{
    this->_partscount = this->_filesize / this->_partsize;

    if((this->_partscount * this->_partsize) < this->_filesize)
        this->_partscount++;
}

void FileUploader::analyzeFile(const QString& filepath)
{
    QFileInfo fileinfo(filepath);

    this->_filename = fileinfo.fileName();
    this->_filesize = fileinfo.size();
    this->_isbigfile = (fileinfo.size() > TenMegaBytes);
    this->_mimetype = FileUploader::_mimedb.mimeTypeForFile(filepath).name();

    if(!QImageReader::imageFormat(filepath).isEmpty())
        this->_imagesize = QImageReader(filepath).size();
}

void FileUploader::scaleImageIfNeeded()
{
    if(qMax(this->_imagesize.width(), this->_imagesize.height()) <= ImageMaxResolution)
        return;

    QImage image(this->_filepath);

    if(image.width() > image.height())
        image = image.scaledToWidth(ImageMaxResolution, Qt::SmoothTransformation);
    else
        image = image.scaledToHeight(ImageMaxResolution, Qt::SmoothTransformation);

    QFileInfo fileinfo(this->_filepath);
    QDir dir(this->_storagepath);
    this->_filepath = dir.absoluteFilePath(md5_hash_hex(this->_filepath.toUtf8())) + "." + fileinfo.suffix();
    image.save(this->_filepath);

    this->analyzeFile(this->_filepath); // Repeat analysis
    this->_deleteoncompleted = true;
}

void FileUploader::getNextPart(TLBytes &data)
{
    this->_file.seek(this->_partnum * this->_partsize);
    data = this->_file.read(this->_partsize);
}

void FileUploader::uploadPart()
{
    TLBytes partdata;
    this->getNextPart(partdata);

    MTProtoRequest* req = NULL;

    if(!this->_isbigfile)
        req = TelegramAPI::uploadSaveFilePart(this->_dcsession, this->_localfileid, this->_partnum, partdata);
    else
        req = TelegramAPI::uploadSaveBigFilePart(this->_dcsession, this->_localfileid, this->_partnum, this->_partscount, partdata);

    connect(req, &MTProtoRequest::replied, this, &FileUploader::onSaveFilePartReplied);
    emit uploadingChanged();
}

void FileUploader::onSaveFilePartReplied(MTProtoReply *mtreply)
{
    TLConstructor result = mtreply->readTLConstructor();

    if(result == TLTypes::BoolFalse)
    {
        qWarning("UPLOAD File transfer failed (part: %d/%d)", this->_partnum, this->_partscount);
        emit failed();
        return;
    }

    this->_partnum++;
    emit progressChanged();

    if(this->_partnum >= this->_partscount)
    {
        emit uploadingChanged();
        emit completed();

        if(this->_deleteoncompleted)
            this->_file.remove();
        else
            this->_file.close();

        return;
    }

    this->uploadPart();
}
