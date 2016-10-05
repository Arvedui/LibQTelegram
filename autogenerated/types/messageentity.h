#ifndef MESSAGEENTITY_H
#define MESSAGEENTITY_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"
#include "inputuser.h"

class MessageEntity: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt offset READ offset WRITE setOffset NOTIFY offsetChanged)
	Q_PROPERTY(TLInt length READ length WRITE setLength NOTIFY lengthChanged)
	Q_PROPERTY(TLString language READ language WRITE setLanguage NOTIFY languageChanged)
	Q_PROPERTY(TLString url READ url WRITE setUrl NOTIFY urlChanged)
	Q_PROPERTY(TLInt userIdMessageentitymentionname READ userIdMessageentitymentionname WRITE setUserIdMessageentitymentionname NOTIFY userIdMessageentitymentionnameChanged)
	Q_PROPERTY(InputUser* userIdInputmessageentitymentionname READ userIdInputmessageentitymentionname WRITE setUserIdInputmessageentitymentionname NOTIFY userIdInputmessageentitymentionnameChanged)

	public:
		enum Constructors {
			ctorMessageEntityUnknown = 0xbb92ba95,
			ctorMessageEntityMention = 0xfa04579d,
			ctorMessageEntityHashtag = 0x6f635b0d,
			ctorMessageEntityBotCommand = 0x6cef8ac7,
			ctorMessageEntityUrl = 0x6ed02538,
			ctorMessageEntityEmail = 0x64e475c2,
			ctorMessageEntityBold = 0xbd610bc9,
			ctorMessageEntityItalic = 0x826f8b60,
			ctorMessageEntityCode = 0x28a20571,
			ctorMessageEntityPre = 0x73924be0,
			ctorMessageEntityTextUrl = 0x76a6d327,
			ctorMessageEntityMentionName = 0x352dca58,
			ctorInputMessageEntityMentionName = 0x208e68c9,
		};

	public:
		explicit MessageEntity(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt offset() const;
		void setOffset(TLInt offset);
		TLInt length() const;
		void setLength(TLInt length);
		TLString language() const;
		void setLanguage(TLString language);
		TLString url() const;
		void setUrl(TLString url);
		TLInt userIdMessageentitymentionname() const;
		void setUserIdMessageentitymentionname(TLInt user_id_messageentitymentionname);
		InputUser* userIdInputmessageentitymentionname() const;
		void setUserIdInputmessageentitymentionname(InputUser* user_id_inputmessageentitymentionname);

	signals:
		void offsetChanged();
		void lengthChanged();
		void languageChanged();
		void urlChanged();
		void userIdMessageentitymentionnameChanged();
		void userIdInputmessageentitymentionnameChanged();

	private:
		TLInt _offset;
		TLInt _length;
		TLString _language;
		TLString _url;
		TLInt _user_id_messageentitymentionname;
		InputUser* _user_id_inputmessageentitymentionname;

};

#endif // MESSAGEENTITY_H
