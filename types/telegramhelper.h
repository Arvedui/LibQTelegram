#ifndef TELEGRAMHELPER_H
#define TELEGRAMHELPER_H

#include "basic.h"
#include "../autogenerated/types/types.h"
#include "../config/cache/fileuploader.h"
#include "../types/time.h"

class TelegramHelper
{
    private:
        TelegramHelper();

    public:
        static Message* createMessage(Updates *updates, User *me);
        static Message* createMessage(const QString& text, User *me, Peer *peer);
        static Dialog* createDialog(User* user, QObject* parent = 0);
        static Dialog* createDialog(Message* message, QObject* parent = 0);
        static InputFileLocation* inputFileLocation(FileLocation *filelocation);
        static InputFileLocation* inputFileLocation(Document* document);
        static InputNotifyPeer* inputNotifyPeer(Dialog* dialog, TLLong accesshash = 0, QObject* parent = 0);
        static InputPeerNotifySettings* inputPeerNotifySettings(PeerNotifySettings* notifysettings, QObject* parent = 0);
        static InputPeer* inputPeer(Dialog* dialog, TLLong accesshash = 0, QObject* parent = 0);
        static InputPeer* inputPeer(Peer* peer, TLLong accesshash = 0, QObject* parent = 0);
        static InputPeer* inputPeer(Message* message, QObject* parent = 0);
        static Peer* peer(User* user, QObject* parent = 0);
        static Peer* peer(Message* message, QObject* parent = 0);
        static InputChannel* inputChannel(Dialog* dialog, TLLong accesshash = 0, QObject* parent = 0);
        static InputChannel* inputChannel(Chat* chat, QObject* parent = 0);
        static InputMedia* inputMediaFile(FileUploader* fileuploader, QObject* parent = 0);
        static InputMedia* inputMediaPhoto(FileUploader* fileuploader, QObject* parent = 0);
        static InputMedia* inputMediaGeoPoint(TLDouble latitude, TLDouble longitude, QObject* parent = 0);
        static InputFile* inputFile(FileUploader* fileuploader, QObject* parent = 0);
        static InputUser* inputUser(User* user, QObject* parent = 0);
        static PhotoSize* photoSmall(Photo* photo);
        static PhotoSize* photoBig(Photo* photo);
        static ChatPhoto* chatPhoto(Photo* photo, QObject *parent = 0);
        static QString duration(TLInt seconds);
        static QString dateString(TLInt timestamp);
        static QString fileSize(TLDouble size);
        static QString fullName(User* user);
        static QString statusText(User* user);
        static DocumentAttribute* createDocumentAttribute(const QString& filename, QObject *parent = 0);
        static DocumentAttribute* documentHas(Document* document, TLConstructor attributector);
        static bool isSticker(Document* document);
        static bool isAnimated(Document* document);
        static bool isVideo(Document* document);
        static bool isAudio(Document* document);
        static bool isFile(Document* document);
        static bool isMuted(Dialog* dialog);
        static bool isCloud(Dialog* dialog);
        static bool isChat(Dialog* dialog);
        static bool isChannel(Dialog* dialog);
        static bool isChat(Peer* peer);
        static bool isChannel(Peer* peer);
        static bool isChannel(Chat* chat);
        static bool messageIsWebPagePending(Message* message);
        static bool messageIsAction(Message* message);
        static MessageId identifier(TLInt messageid, TLInt channelid);
        static MessageId identifier(TLInt messageid, Dialog* dialog);
        static MessageId identifier(Message* message);
        static TLInt identifier(User* user);
        static TLInt identifier(Chat* chat);
        static TLInt identifier(Peer* peer);
        static TLInt identifier(Dialog* dialog);
        static TLInt messageToDialog(Message* message);
        static TLInt messageIdentifier(MessageId messageid);
        static TLBytes createPasswordHash(const QString& password, const AccountPassword *accountpassword);
};

#endif // TELEGRAMHELPER_H
