#ifndef ENCRYPTEDMESSAGE_H
#define ENCRYPTEDMESSAGE_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "encryptedfile.h"
#include "../../types/telegramobject.h"

class EncryptedMessage: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLLong randomId READ randomId WRITE setRandomId NOTIFY randomIdChanged)
	Q_PROPERTY(TLInt chatId READ chatId WRITE setChatId NOTIFY chatIdChanged)
	Q_PROPERTY(TLInt date READ date WRITE setDate NOTIFY dateChanged)
	Q_PROPERTY(TLBytes bytes READ bytes WRITE setBytes NOTIFY bytesChanged)
	Q_PROPERTY(EncryptedFile* file READ file WRITE setFile NOTIFY fileChanged)

	public:
		enum Constructors {
			ctorEncryptedMessage = 0xed18c118,
			ctorEncryptedMessageService = 0x23734b06,
		};

	public:
		explicit EncryptedMessage(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLLong randomId() const;
		void setRandomId(TLLong random_id);
		TLInt chatId() const;
		void setChatId(TLInt chat_id);
		TLInt date() const;
		void setDate(TLInt date);
		TLBytes bytes() const;
		void setBytes(TLBytes bytes);
		EncryptedFile* file() const;
		void setFile(EncryptedFile* file);

	signals:
		void randomIdChanged();
		void chatIdChanged();
		void dateChanged();
		void bytesChanged();
		void fileChanged();

	private:
		TLLong _random_id;
		TLInt _chat_id;
		TLInt _date;
		TLBytes _bytes;
		EncryptedFile* _file;

};

#endif // ENCRYPTEDMESSAGE_H
