#ifndef MESSAGEFWDHEADER_H
#define MESSAGEFWDHEADER_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class MessageFwdHeader: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt flags READ flags WRITE setFlags NOTIFY flagsChanged)
	Q_PROPERTY(TLInt fromId READ fromId WRITE setFromId NOTIFY fromIdChanged)
	Q_PROPERTY(TLInt date READ date WRITE setDate NOTIFY dateChanged)
	Q_PROPERTY(TLInt channelId READ channelId WRITE setChannelId NOTIFY channelIdChanged)
	Q_PROPERTY(TLInt channelPost READ channelPost WRITE setChannelPost NOTIFY channelPostChanged)

	public:
		enum Constructors {
			ctorMessageFwdHeader = 0xc786ddcb,
		};

	public:
		explicit MessageFwdHeader(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt flags() const;
		void setFlags(TLInt flags);
		TLInt fromId() const;
		void setFromId(TLInt from_id);
		TLInt date() const;
		void setDate(TLInt date);
		TLInt channelId() const;
		void setChannelId(TLInt channel_id);
		TLInt channelPost() const;
		void setChannelPost(TLInt channel_post);

	signals:
		void flagsChanged();
		void fromIdChanged();
		void dateChanged();
		void channelIdChanged();
		void channelPostChanged();

	private:
		TLInt _flags;
		TLInt _from_id;
		TLInt _date;
		TLInt _channel_id;
		TLInt _channel_post;

};

#endif // MESSAGEFWDHEADER_H
