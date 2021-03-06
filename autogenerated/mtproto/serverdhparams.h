#ifndef SERVERDHPARAMS_H
#define SERVERDHPARAMS_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class ServerDHParams: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt128 nonce READ nonce WRITE setNonce NOTIFY nonceChanged)
	Q_PROPERTY(TLInt128 serverNonce READ serverNonce WRITE setServerNonce NOTIFY serverNonceChanged)
	Q_PROPERTY(TLInt128 newNonceHash READ newNonceHash WRITE setNewNonceHash NOTIFY newNonceHashChanged)
	Q_PROPERTY(TLBytes encryptedAnswer READ encryptedAnswer WRITE setEncryptedAnswer NOTIFY encryptedAnswerChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorServerDHParamsFail = 0x79cb045d,
			CtorServerDHParamsOk = 0xd0e8075c,
		};

	public:
		explicit ServerDHParams(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt128 nonce() const;
		void setNonce(TLInt128 nonce);
		TLInt128 serverNonce() const;
		void setServerNonce(TLInt128 server_nonce);
		TLInt128 newNonceHash() const;
		void setNewNonceHash(TLInt128 new_nonce_hash);
		TLBytes encryptedAnswer() const;
		void setEncryptedAnswer(TLBytes encrypted_answer);

	signals:
		void nonceChanged();
		void serverNonceChanged();
		void newNonceHashChanged();
		void encryptedAnswerChanged();

	private:
		TLInt128 _nonce;
		TLInt128 _server_nonce;
		TLInt128 _new_nonce_hash;
		TLBytes _encrypted_answer;

};

#endif // SERVERDHPARAMS_H
