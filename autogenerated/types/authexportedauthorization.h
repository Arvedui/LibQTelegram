#ifndef AUTHEXPORTEDAUTHORIZATION_H
#define AUTHEXPORTEDAUTHORIZATION_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class AuthExportedAuthorization: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt id READ id WRITE setId NOTIFY idChanged)
	Q_PROPERTY(TLBytes bytes READ bytes WRITE setBytes NOTIFY bytesChanged)

	public:
		enum Constructors {
			ctorAuthExportedAuthorization = 0xdf969c2d,
		};

	public:
		explicit AuthExportedAuthorization(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt id() const;
		void setId(TLInt id);
		TLBytes bytes() const;
		void setBytes(TLBytes bytes);

	signals:
		void idChanged();
		void bytesChanged();

	private:
		TLInt _id;
		TLBytes _bytes;

};

#endif // AUTHEXPORTEDAUTHORIZATION_H
