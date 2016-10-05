#ifndef EXPORTEDCHATINVITE_H
#define EXPORTEDCHATINVITE_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class ExportedChatInvite: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLString link READ link WRITE setLink NOTIFY linkChanged)

	public:
		enum Constructors {
			ctorChatInviteEmpty = 0x69df3769,
			ctorChatInviteExported = 0xfc2e05bc,
		};

	public:
		explicit ExportedChatInvite(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLString link() const;
		void setLink(TLString link);

	signals:
		void linkChanged();

	private:
		TLString _link;

};

#endif // EXPORTEDCHATINVITE_H
