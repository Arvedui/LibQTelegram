#ifndef ACCOUNTPASSWORDSETTINGS_H
#define ACCOUNTPASSWORDSETTINGS_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class AccountPasswordSettings: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLString email READ email WRITE setEmail NOTIFY emailChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorAccountPasswordSettings = 0xb7b72ab3,
		};

	public:
		explicit AccountPasswordSettings(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLString email() const;
		void setEmail(TLString email);

	signals:
		void emailChanged();

	private:
		TLString _email;

};

#endif // ACCOUNTPASSWORDSETTINGS_H
