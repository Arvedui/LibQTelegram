#ifndef MTPROTOSERVICEHANDLER_H
#define MTPROTOSERVICEHANDLER_H

#include <QObject>
#include "mtprotoreply.h"
#include "../autogenerated/types/types.h"

class MTProtoServiceHandler : public QObject
{
    Q_OBJECT

    public:
        explicit MTProtoServiceHandler(int dcid, QObject *parent = 0);
        bool handle(MTProtoReply* mtreply);

    signals:
        void ackRequest(TLLong reqmsgid);
        void ack(const TLVector<TLLong>& msgids);
        void serviceHandled(MTProtoReply* mtreply);
        void migrateDC(int fromdcid, int todcid);
        void saltChanged(TLLong reqmsgid);
        void unauthorized();
        void floodWait(int seconds);
        void invalidPassword();
        void sessionPasswordNeeded();
        void phoneCodeError(QString errormessage);

    private:
        void handleMsgContainer(MTProtoReply* mtreply);
        void handleRpcResult(MTProtoReply* mtreply);
        void handleRpcError(MTProtoReply* mtreply);
        void handleBadMsgNotification(MTProtoReply* mtreply);
        void handleGzipPacked(MTProtoReply* mtreply);
        void handleNewSessionCreated(MTProtoReply* mtreply);
        void handleMsgAck(MTProtoReply* mtreply);

    private:
        int _dcid;
};

#endif // MTPROTOSERVICEHANDLER_H
