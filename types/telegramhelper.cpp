#include "telegramhelper.h"
#include <QDateTime>

#define CurrentTimeStamp QDateTime::currentDateTime().toTime_t()

TelegramHelper::TelegramHelper()
{

}

Message *TelegramHelper::createMessage(Updates *updates, User* me)
{
    Q_ASSERT((updates->constructorId() == TLTypes::UpdateShortMessage) ||
             (updates->constructorId() == TLTypes::UpdateShortChatMessage));

    Message* message = new Message();
    message->setConstructorId(Message::CtorMessage);
    message->setFlags(updates->flags());
    message->setIsOut(updates->isOut());
    message->setIsMentioned(updates->isMentioned());
    message->setIsMediaUnread(updates->isMediaUnread());
    message->setIsSilent(updates->isSilent());
    message->setId(updates->id());
    message->setMessage(updates->message());
    message->setDate(updates->date());
    message->setFwdFrom(updates->fwdFrom());
    message->setViaBotId(updates->viaBotId());
    message->setReplyToMsgId(updates->replyToMsgId());
    message->setEntities(updates->entities());

    if(updates->constructorId() == TLTypes::UpdateShortMessage)
    {
        Peer* topeer = new Peer();
        topeer->setConstructorId(Peer::CtorPeerUser);
        topeer->setUserId(updates->isOut() ? updates->userId() : me->id());

        message->setFromId(updates->isOut() ? me->id() : updates->userId());
        message->setToId(topeer);
    }
    else if(updates->constructorId() == TLTypes::UpdateShortChatMessage)
    {
        Peer* topeer = new Peer();
        topeer->setConstructorId(Peer::CtorPeerChat);
        topeer->setChatId(updates->chatId());

        message->setFromId(updates->fromId());
        message->setToId(topeer);
    }

    return message;
}

Message *TelegramHelper::createMessage(const QString &text, User* me, Peer* peer)
{
    Message* message = new Message();
    message->setConstructorId(Message::CtorMessage);
    message->setMessage(text);
    message->setDate(QDateTime::currentDateTime().toTime_t());
    message->setFromId(me->id());
    message->setIsOut(true);
    message->setToId(peer);

    return message;
}

InputFileLocation *TelegramHelper::inputFileLocation(FileLocation *filelocation)
{
    InputFileLocation* inputfilelocation = new InputFileLocation();

    inputfilelocation->setConstructorId(TLTypes::InputFileLocation);
    inputfilelocation->setVolumeId(filelocation->volumeId());
    inputfilelocation->setLocalId(filelocation->localId());
    inputfilelocation->setSecret(filelocation->secret());

    return inputfilelocation;
}

InputFileLocation *TelegramHelper::inputFileLocation(Document *document)
{
    InputFileLocation* inputfilelocation = new InputFileLocation();

    inputfilelocation->setConstructorId(TLTypes::InputDocumentFileLocation);
    inputfilelocation->setId(document->id());
    inputfilelocation->setAccessHash(document->accessHash());
    inputfilelocation->setVersion(document->version());

    return inputfilelocation;
}

InputPeer *TelegramHelper::inputPeer(Peer *peer, TLLong accesshash, QObject *parent)
{
    InputPeer* inputpeer = new InputPeer(parent);
    inputpeer->setAccessHash(accesshash);

    if(peer->constructorId() == TLTypes::PeerUser)
    {
        inputpeer->setConstructorId(TLTypes::InputPeerUser);
        inputpeer->setUserId(peer->userId());
    }
    else if(peer->constructorId() == TLTypes::PeerChat)
    {
        inputpeer->setConstructorId(TLTypes::InputPeerChat);
        inputpeer->setChatId(peer->chatId());
    }
    else if(peer->constructorId() == TLTypes::PeerChannel)
    {
        inputpeer->setConstructorId(TLTypes::InputPeerChannel);
        inputpeer->setChannelId(peer->channelId());
    }
    else
        Q_ASSERT(false);

    return inputpeer;
}

InputPeer *TelegramHelper::inputPeer(Message *message, QObject *parent)
{
    InputPeer* inputpeer = new InputPeer(parent);
    TLInt dialogid = TelegramHelper::messageToDialog(message);

    if(TelegramHelper::isChannel(message->toId()))
    {
        inputpeer->setConstructorId(TLTypes::InputPeerChannel);
        inputpeer->setChannelId(dialogid);
    }
    else if(TelegramHelper::isChat(message->toId()))
    {
        inputpeer->setConstructorId(TLTypes::InputPeerChat);
        inputpeer->setChatId(dialogid);
    }
    else
    {
        inputpeer->setConstructorId(TLTypes::InputPeerUser);
        inputpeer->setUserId(dialogid);
    }

    return inputpeer;
}

InputUser *TelegramHelper::inputUser(User *user, QObject *parent)
{
    InputUser* inputuser = new InputUser(parent);
    inputuser->setConstructorId(TLTypes::InputUser);
    inputuser->setUserId(user->id());
    inputuser->setAccessHash(user->accessHash());
    return inputuser;
}

QString TelegramHelper::dateString(TLInt timestamp)
{
    QDateTime datetime = QDateTime::fromTime_t(timestamp);
    const QDateTime& currentdatetime = QDateTime::currentDateTime();
    qint64 seconds = datetime.secsTo(currentdatetime);
    int days = datetime.daysTo(currentdatetime);

    if(seconds < 24 * 60 * 60)
        return days ? QObject::tr("Yesterday %1").arg(datetime.toString("HH:mm")) : datetime.toString("HH:mm");

    return datetime.toString("MMM dd, HH:mm");
}

QString TelegramHelper::fileSize(TLDouble size)
{
    int unit = 0;

    while(size > 1024)
    {
        size /= 1024;
        unit++;
    }

    QString filesize = QString::number(size, 'g', 2);

    if(unit == 0)
        filesize += "B";
    else if(unit == 1)
        filesize += "KB";
    else if(unit == 2)
        filesize += "MB";
    else if(unit == 3)
        filesize += "GB";

    return filesize;
}

QString TelegramHelper::fullName(User *user)
{
    if(!user)
        return QString();

    if(user->lastName().isEmpty())
        return user->firstName();

    return user->firstName() + " " + user->lastName();
}

QString TelegramHelper::statusText(User *user)
{
    if(user->status())
    {
        if(user->status()->constructorId() == TLTypes::UserStatusLastMonth)
            return QObject::tr("Last month");

        if(user->status()->constructorId() == TLTypes::UserStatusLastWeek)
            return QObject::tr("Last week");

        if(user->status()->constructorId() == TLTypes::UserStatusOffline)
            return QObject::tr("Last seen %1").arg(TelegramHelper::dateString(user->status()->wasOnline()));

        if(user->status()->constructorId() == TLTypes::UserStatusOnline)
        {
            if(CurrentTimeStamp >= static_cast<uint>(user->status()->expires()))
                return QObject::tr("Last seen %1").arg(TelegramHelper::dateString(user->status()->expires()));

            return QObject::tr("Online");
        }

        if(user->status()->constructorId() == TLTypes::UserStatusRecently)
            return QObject::tr("Recently");
    }

    return QObject::tr("Long time ago");
}

DocumentAttribute *TelegramHelper::documentHas(Document *document, TLConstructor attributector)
{
    foreach(DocumentAttribute* attribute, document->attributes())
    {
        if(attribute->constructorId() == attributector)
            return attribute;
    }

    return NULL;
}

bool TelegramHelper::isSticker(Document *document)
{
    return TelegramHelper::documentHas(document, TLTypes::DocumentAttributeSticker) != NULL;
}

bool TelegramHelper::isAnimated(Document *document)
{
    return TelegramHelper::documentHas(document, TLTypes::DocumentAttributeAnimated) != NULL;
}

bool TelegramHelper::isFile(Document *document)
{
    return TelegramHelper::documentHas(document, TLTypes::DocumentAttributeFilename) != NULL;
}

bool TelegramHelper::isChat(Dialog *dialog)
{
    return TelegramHelper::isChat(dialog->peer());
}

bool TelegramHelper::isChannel(Dialog *dialog)
{
    return TelegramHelper::isChannel(dialog->peer());
}

bool TelegramHelper::isChat(Peer *peer)
{
    return peer->constructorId() == TLTypes::PeerChat;
}

bool TelegramHelper::isChannel(Peer *peer)
{
    return peer->constructorId() == TLTypes::PeerChannel;
}

MessageId TelegramHelper::identifier(TLInt messageid, TLInt channelid)
{
    return (static_cast<MessageId>(channelid) << 32u) + messageid;
}

MessageId TelegramHelper::identifier(TLInt messageid, Dialog *dialog)
{
    if(TelegramHelper::isChannel(dialog))
        return TelegramHelper::identifier(messageid, TelegramHelper::identifier(dialog));

    return messageid;
}

MessageId TelegramHelper::identifier(Message *message)
{
    if(TelegramHelper::isChannel(message->toId()))
        return TelegramHelper::identifier(message->id(), TelegramHelper::messageToDialog(message));

    return message->id();
}

TLInt TelegramHelper::identifier(User *user)
{
    return user->id();
}

TLInt TelegramHelper::identifier(Chat *chat)
{
    return chat->id();
}

TLInt TelegramHelper::identifier(Peer *peer)
{
    if(peer->constructorId() == TLTypes::PeerChannel)
        return peer->channelId();

    if(peer->constructorId() == TLTypes::PeerChat)
        return peer->chatId();

    if(peer->constructorId() == TLTypes::PeerUser)
        return peer->userId();

    Q_ASSERT(false);
    return -1;
}

TLInt TelegramHelper::identifier(Dialog *dialog)
{
    return TelegramHelper::identifier(dialog->peer());
}

TLInt TelegramHelper::messageToDialog(Message *message)
{
    if(message->isOut() || TelegramHelper::isChat(message->toId()) || TelegramHelper::isChannel(message->toId()))
        return TelegramHelper::identifier(message->toId());

    return message->fromId();
}
