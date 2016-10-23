#ifndef MTPROTOUPDATEHANDLER_H
#define MTPROTOUPDATEHANDLER_H

#define UpdateHandler_instance MTProtoUpdateHandler::instance()
#define UpdateHandler_sync MTProtoUpdateHandler::instance()->sync()

#include <QObject>
#include "mtprotoreply.h"
#include "../autogenerated/types/types.h"

class MTProtoUpdateHandler : public QObject
{
    Q_OBJECT

    private:
        explicit MTProtoUpdateHandler(QObject *parent = 0);

    public:
        static MTProtoUpdateHandler* instance();
        bool handle(MTProtoReply* mtreply);
        void sync();

    private:
        void handleUpdates(MTProtoReply* mtreply);
        void handleUpdatesDifference(MTProtoReply* mtreply);

    private:
        void handleUpdates(TLVector<Update*> updatelist);
        void handleUpdate(Update* update);

    signals:
        void newMessages(const TLVector<Message*>& messages);
        void newUsers(const TLVector<User*>& users);
        void newChats(const TLVector<Chat*>& chats);
        void newMessage(Message* message);
        void editMessage(Message* message);
        void deleteMessages(const TLVector<TLInt>& messageids);
        void newUser(User* user);
        void newChat(Chat* chat);
        void newUserStatus(Update* update);
        void newDraftMessage(Update* update);
        void readHistory(Update* update);
        void typing(Update* update);

    private:
        static MTProtoUpdateHandler* _instance;
};

#endif // MTPROTOUPDATEHANDLER_H
