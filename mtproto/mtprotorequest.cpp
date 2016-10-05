#include "mtprotorequest.h"
#include "../config/telegramconfig.h"
#include "../autogenerated/tltypes.h"
#include "../crypto/sha1.h"
#include "../crypto/aes.h"

QHash<int, bool> MTProtoRequest::_firstmap;

MTProtoRequest::MTProtoRequest(TLLong &lastmsgid, int dcid, QObject *parent) : QObject(parent), _lastmsgid(lastmsgid), _dcid(dcid), _constructorid(0), _sessionid(0), _mainmsgid(0), _msgid(0), _seqno(0), _body(NULL)
{
    TRY_INIT_FIRST(dcid);
    this->generateMessageId(); // Preparate a messageId
}

TLConstructor MTProtoRequest::constructorId() const
{
    return this->_constructorid;
}

TLLong MTProtoRequest::mainMessageId() const
{
    return this->_mainmsgid;
}

TLLong MTProtoRequest::messageId() const
{
    return this->_msgid;
}

bool MTProtoRequest::encrypted() const
{
    return this->_sessionid != 0;
}

const QByteArray &MTProtoRequest::body() const
{
    return this->_body->data();
}

void MTProtoRequest::setSessionId(TLLong sessionid)
{
    this->_sessionid = sessionid;
}

void MTProtoRequest::setSeqNo(TLInt seqno)
{
    this->_seqno = seqno;
}

void MTProtoRequest::setBody(MTProtoStream *body)
{
    this->_constructorid = body->peekTLConstructor();
    this->_body = body;
}

QByteArray MTProtoRequest::build()
{
    QByteArray request, requestbody;

    if(this->encrypted())
        requestbody = this->buildEncrypted();
    else
        requestbody = this->buildPlain();

    this->build(request, requestbody);
    return request;
}

TLLong MTProtoRequest::generateMessageId()
{
    Q_ASSERT(this->_dcid > 0);

    DCConfig& dcconfig = GET_DC_CONFIG_FROM_DCID(this->_dcid);
    TLLong unixtime = (static_cast<TLLong>(QDateTime::currentDateTime().toTime_t()) << 32) + dcconfig.deltaTime();
    TLLong ticks = 4 - (unixtime % 4);

    if(!(unixtime % 4))
        this->_msgid = unixtime;
    else
        this->_msgid = unixtime + ticks;

    this->_lastmsgid = this->_msgid = qMax(this->_msgid, this->_lastmsgid + 4);

    Q_ASSERT((this->_msgid % 2) == 0);
    return this->_msgid;
}

void MTProtoRequest::initConnection(MTProtoStream &mtstream) const
{
    TelegramConfig* config = TelegramConfig::config();

    mtstream.writeTLConstructor(TLTypes::InvokeWithLayer);
    mtstream.writeTLInt(config->layerNum());

    mtstream.writeTLConstructor(TLTypes::initConnection);
    mtstream.writeTLInt(config->apiId());
    mtstream.writeTLString(config->deviceModel());
    mtstream.writeTLString(config->osVersion());
    mtstream.writeTLString(config->applicationVersion());
    mtstream.writeTLString(QLocale::system().name());
}

void MTProtoRequest::build(QByteArray &request, const QByteArray &requestbody)
{
    if(IS_FIRST(this->_dcid))
    {
        request.append(0xEF); // Use Abridged version
        UNSET_FIRST(this->_dcid);
    }

    TLInt len = requestbody.length() / 4;

    if(len > 0x7E)
    {
        len |= 0x7F000000;
        request.append(reinterpret_cast<const char*>(&len), sizeof(TLInt));
    }
    else
        request.append(static_cast<qint8>(len));

    request.append(requestbody);
}

QByteArray MTProtoRequest::buildPlain()
{
    MTProtoStream mtstream;

    mtstream.writeTLLong(0);
    mtstream.writeTLLong(this->generateMessageId());
    mtstream.writeRaw(this->_body);

    return mtstream.data();
}

QByteArray MTProtoRequest::buildEncrypted()
{
    Q_ASSERT(this->_dcid > 0);
    Q_ASSERT(this->_sessionid != 0);
    Q_ASSERT(this->_seqno > 0);

    DCConfig& dcconfig = GET_DC_CONFIG_FROM_DCID(this->_dcid);
    MTProtoStream mtproto;

    mtproto.writeTLLong(dcconfig.serverSalt());
    mtproto.writeTLLong(this->_sessionid);
    mtproto.writeTLLong(this->generateMessageId());
    mtproto.writeTLInt(this->_seqno);

    if(this->_seqno == 1)
    {
        MTProtoStream header;
        this->initConnection(header);

        mtproto.writeTLInt(header.length() + this->_body->length());
        mtproto.writeRaw(&header, false);
        mtproto.writeRaw(this->_body, false);
    }
    else
        mtproto.writeRaw(this->_body);

    QByteArray aeskey, aesiv, msgkey = Sha1::hash(mtproto.data()).right(16);
    Aes::calculateAesKeys(dcconfig.authorizationKey(), msgkey, false, aeskey, aesiv);
    mtproto.randPad(16);
    QByteArray encryptedmtproto = Aes::encrypt(mtproto.data(), aeskey, aesiv);

    MTProtoStream encryptedmessage;
    encryptedmessage.writeTLLong(dcconfig.authorizationKeyId());
    encryptedmessage.writeRaw(msgkey, false);
    encryptedmessage.writeRaw(encryptedmtproto, false);

    return encryptedmessage.data();
}
