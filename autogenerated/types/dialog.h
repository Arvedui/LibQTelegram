#ifndef DIALOG_H
#define DIALOG_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "peernotifysettings.h"
#include "peer.h"
#include "../../types/telegramobject.h"
#include "draftmessage.h"

class Dialog: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt flags READ flags WRITE setFlags NOTIFY flagsChanged)
	Q_PROPERTY(Peer* peer READ peer WRITE setPeer NOTIFY peerChanged)
	Q_PROPERTY(TLInt topMessage READ topMessage WRITE setTopMessage NOTIFY topMessageChanged)
	Q_PROPERTY(TLInt readInboxMaxId READ readInboxMaxId WRITE setReadInboxMaxId NOTIFY readInboxMaxIdChanged)
	Q_PROPERTY(TLInt readOutboxMaxId READ readOutboxMaxId WRITE setReadOutboxMaxId NOTIFY readOutboxMaxIdChanged)
	Q_PROPERTY(TLInt unreadCount READ unreadCount WRITE setUnreadCount NOTIFY unreadCountChanged)
	Q_PROPERTY(PeerNotifySettings* notifySettings READ notifySettings WRITE setNotifySettings NOTIFY notifySettingsChanged)
	Q_PROPERTY(TLInt pts READ pts WRITE setPts NOTIFY ptsChanged)
	Q_PROPERTY(DraftMessage* draft READ draft WRITE setDraft NOTIFY draftChanged)

	public:
		enum Constructors {
			ctorDialog = 0x66ffba14,
		};

	public:
		explicit Dialog(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt flags() const;
		void setFlags(TLInt flags);
		Peer* peer() const;
		void setPeer(Peer* peer);
		TLInt topMessage() const;
		void setTopMessage(TLInt top_message);
		TLInt readInboxMaxId() const;
		void setReadInboxMaxId(TLInt read_inbox_max_id);
		TLInt readOutboxMaxId() const;
		void setReadOutboxMaxId(TLInt read_outbox_max_id);
		TLInt unreadCount() const;
		void setUnreadCount(TLInt unread_count);
		PeerNotifySettings* notifySettings() const;
		void setNotifySettings(PeerNotifySettings* notify_settings);
		TLInt pts() const;
		void setPts(TLInt pts);
		DraftMessage* draft() const;
		void setDraft(DraftMessage* draft);

	signals:
		void flagsChanged();
		void peerChanged();
		void topMessageChanged();
		void readInboxMaxIdChanged();
		void readOutboxMaxIdChanged();
		void unreadCountChanged();
		void notifySettingsChanged();
		void ptsChanged();
		void draftChanged();

	private:
		TLInt _flags;
		Peer* _peer;
		TLInt _top_message;
		TLInt _read_inbox_max_id;
		TLInt _read_outbox_max_id;
		TLInt _unread_count;
		PeerNotifySettings* _notify_settings;
		TLInt _pts;
		DraftMessage* _draft;

};

#endif // DIALOG_H
