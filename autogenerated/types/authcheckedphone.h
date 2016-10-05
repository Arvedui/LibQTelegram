#ifndef AUTHCHECKEDPHONE_H
#define AUTHCHECKEDPHONE_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class AuthCheckedPhone: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLBool isPhoneRegistered READ isPhoneRegistered WRITE setIsPhoneRegistered NOTIFY isPhoneRegisteredChanged)

	public:
		enum Constructors {
			ctorAuthCheckedPhone = 0x811ea28e,
		};

	public:
		explicit AuthCheckedPhone(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLBool isPhoneRegistered() const;
		void setIsPhoneRegistered(TLBool is_phone_registered);

	signals:
		void isPhoneRegisteredChanged();

	private:
		TLBool _is_phone_registered;

};

#endif // AUTHCHECKEDPHONE_H
