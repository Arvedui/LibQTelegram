#ifndef FILECACHE_H
#define FILECACHE_H

#define FileCache_instance FileCache::instance()
#define FileCache_fileObject(obj) FileCache::instance()->fileObject(obj)
#define FileCache_removeObject(obj) FileCache::instance()->removeObject(obj)
#define FileCache_upload(mediatype, filepath, caption) FileCache::instance()->upload(mediatype, filepath, caption)

#include <QObject>
#include <QMimeDatabase>
#include "../../autogenerated/types/types.h"
#include "../../objects/fileobject.h"
#include "fileuploader.h"

class FileCache : public QObject
{
    Q_OBJECT

    private:
        explicit FileCache(QObject *parent = 0);

    public:
        static FileCache* instance();
        FileObject* fileObject(TelegramObject* tgobj);
        FileObject* upload(FileUploader::MediaType mediatype, const QString& filepath, const QString& caption);
        void removeObject(TelegramObject* tgobj);

    private:
        QString createFileId(TelegramObject* locationobj);
        FileObject* localFileObject(TelegramObject* tgobj);
        FileObject* fileObject(TelegramObject* tgobj, bool ismovable, bool autodownload);
        FileObject* fileObject(TelegramObject *locationobj, FileLocation *locthumbnail, bool ismovable, bool autodownload);
        void enqueue(FileObject* fileobject);
        void dequeue(FileObject* fileobject);

    private slots:
        void processQueue();
        void onDownloadCompleted();

    private:
        QString _cachepath;
        QString _downloadspath;
        QHash<QString, FileObject*> _filemap;
        QList<FileObject*> _queue;
        FileObject* _currentobject;
        QMimeDatabase _mimedb;

    private:
        static FileCache* _instance;
};

#endif // FILECACHE_H
