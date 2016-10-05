#ifndef MESSAGESAFFECTEDMESSAGES_H
#define MESSAGESAFFECTEDMESSAGES_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class MessagesAffectedMessages: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt pts READ pts WRITE setPts NOTIFY ptsChanged)
	Q_PROPERTY(TLInt ptsCount READ ptsCount WRITE setPtsCount NOTIFY ptsCountChanged)

	public:
		enum Constructors {
			ctorMessagesAffectedMessages = 0x84d19185,
		};

	public:
		explicit MessagesAffectedMessages(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt pts() const;
		void setPts(TLInt pts);
		TLInt ptsCount() const;
		void setPtsCount(TLInt pts_count);

	signals:
		void ptsChanged();
		void ptsCountChanged();

	private:
		TLInt _pts;
		TLInt _pts_count;

};

#endif // MESSAGESAFFECTEDMESSAGES_H
