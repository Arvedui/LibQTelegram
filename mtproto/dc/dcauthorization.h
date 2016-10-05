#ifndef DCAUTHORIZATION_H
#define DCAUTHORIZATION_H

#include <QObject>
#include "dcsession.h"
#include "../../autogenerated/mtprotoapi.h"
#include "../../autogenerated/telegramapi.h"
#include "../mtprotoreply.h"

class DCAuthorization : public QObject
{
    Q_OBJECT

    public:
        explicit DCAuthorization(DCSession *dcsession, QObject *parent = 0);
        void authorize();
        void authorizeReply(MTProtoReply *mtreply);

    private:
        void encryptPQInnerData(PQInnerData* pqinnerdata, TLBytes& encinnerdata);
        void encryptClientDHInnerData(ClientDHInnerData *clientdhinnerdata, const TLBytes& tmpaeskey, const TLBytes& tmpaesiv, TLBytes &encinnerdata);
        void handleNotAuthorized();
        void handlePQReceived();
        void handleDHParamsFail();
        void handleDHParamsOk();
        void handleDHGenFail();
        void handleDHGenRetry();
        void handleDHGenOk();
        void handleAuthorized();

    private slots:
        void onPQReceived(MTProtoStream* mtstream);
        void onServerDHParamsOkReceived(MTProtoStream* mtstream);
        void onServerDHParamsFailReceived(MTProtoStream* mtstream);
        void onServerDhGenFail(MTProtoStream* mtstream);
        void onServerDhGenRetry(MTProtoStream* mtstream);
        void onServerDhGenOk(MTProtoStream* mtstream);
        void onConfigurationReceived(Config* config);

    signals:
        void authorized(DC* dc);

    private:
        TLBytes _tmpaeskey;
        TLBytes _tmpaesiv;
        TLBytes _g_b;
        DCSession* _dcsession;
        ResPQ* _respq;
        TLInt128 _nonce;
        TLInt256 _newnonce;
        TLInt128 _dhnonce;
        TLInt128 _dhservernonce;
        TLInt _retryid;

    private:
        static const int ENCRYPTED_PQINNERDATA_LENGTH;
};

#endif // DCAUTHORIZATION_H
