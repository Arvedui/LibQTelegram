// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "chatinvite.h"


ChatInvite::ChatInvite(QObject* parent) : TelegramObject(parent)
{
	this->_chat = NULL;
	this->_flags = 0;
	this->_is_channel = false;
	this->_is_broadcast = false;
	this->_is_public = false;
	this->_is_megagroup = false;
	this->_photo = NULL;
	this->_participants_count = 0;
}

void ChatInvite::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == ChatInvite::ctorChatInviteAlready) ||
		 (this->_constructorid == ChatInvite::ctorChatInvite));
	
	if(this->_constructorid == ChatInvite::ctorChatInviteAlready)
	{
		RESET_TLTYPE(Chat, this->_chat);
		this->_chat->read(mtstream);
	}
	else if(this->_constructorid == ChatInvite::ctorChatInvite)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_channel = IS_FLAG_SET(this->_flags, 0);
		this->_is_broadcast = IS_FLAG_SET(this->_flags, 1);
		this->_is_public = IS_FLAG_SET(this->_flags, 2);
		this->_is_megagroup = IS_FLAG_SET(this->_flags, 3);
		this->_title = mtstream->readTLString();
		RESET_TLTYPE(ChatPhoto, this->_photo);
		this->_photo->read(mtstream);
		this->_participants_count = mtstream->readTLInt();
		if(IS_FLAG_SET(this->_flags, 4))
			mtstream->readTLVector<User>(this->_participants, false);
	}
}

void ChatInvite::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == ChatInvite::ctorChatInviteAlready) ||
		 (this->_constructorid == ChatInvite::ctorChatInvite));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == ChatInvite::ctorChatInviteAlready)
	{
		Q_ASSERT(this->_chat != NULL);
		this->_chat->write(mtstream);
	}
	else if(this->_constructorid == ChatInvite::ctorChatInvite)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLString(this->_title);
		Q_ASSERT(this->_photo != NULL);
		this->_photo->write(mtstream);
		mtstream->writeTLInt(this->_participants_count);
		if(IS_FLAG_SET(this->_flags, 4))
			mtstream->writeTLVector(this->_participants, false);
	}
}

void ChatInvite::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == ChatInvite::ctorChatInvite)
	{
		if(this->_is_channel)
			SET_FLAG_BIT(this->_flags, 0);
		if(this->_is_broadcast)
			SET_FLAG_BIT(this->_flags, 1);
		if(this->_is_public)
			SET_FLAG_BIT(this->_flags, 2);
		if(this->_is_megagroup)
			SET_FLAG_BIT(this->_flags, 3);
		if(!this->_participants.isEmpty())
			SET_FLAG_BIT(this->_flags, 4);
	}
}

Chat* ChatInvite::chat() const
{
	return this->_chat;
}

void ChatInvite::setChat(Chat* chat) 
{
	if(this->_chat == chat)
		return;

	this->_chat = chat;
	emit chatChanged();
}

TLInt ChatInvite::flags() const
{
	return this->_flags;
}

void ChatInvite::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLTrue ChatInvite::isChannel() const
{
	return this->_is_channel;
}

void ChatInvite::setIsChannel(TLTrue is_channel) 
{
	if(this->_is_channel == is_channel)
		return;

	this->_is_channel = is_channel;
	emit isChannelChanged();
}

TLTrue ChatInvite::isBroadcast() const
{
	return this->_is_broadcast;
}

void ChatInvite::setIsBroadcast(TLTrue is_broadcast) 
{
	if(this->_is_broadcast == is_broadcast)
		return;

	this->_is_broadcast = is_broadcast;
	emit isBroadcastChanged();
}

TLTrue ChatInvite::isPublic() const
{
	return this->_is_public;
}

void ChatInvite::setIsPublic(TLTrue is_public) 
{
	if(this->_is_public == is_public)
		return;

	this->_is_public = is_public;
	emit isPublicChanged();
}

TLTrue ChatInvite::isMegagroup() const
{
	return this->_is_megagroup;
}

void ChatInvite::setIsMegagroup(TLTrue is_megagroup) 
{
	if(this->_is_megagroup == is_megagroup)
		return;

	this->_is_megagroup = is_megagroup;
	emit isMegagroupChanged();
}

TLString ChatInvite::title() const
{
	return this->_title;
}

void ChatInvite::setTitle(TLString title) 
{
	if(this->_title == title)
		return;

	this->_title = title;
	emit titleChanged();
}

ChatPhoto* ChatInvite::photo() const
{
	return this->_photo;
}

void ChatInvite::setPhoto(ChatPhoto* photo) 
{
	if(this->_photo == photo)
		return;

	this->_photo = photo;
	emit photoChanged();
}

TLInt ChatInvite::participantsCount() const
{
	return this->_participants_count;
}

void ChatInvite::setParticipantsCount(TLInt participants_count) 
{
	if(this->_participants_count == participants_count)
		return;

	this->_participants_count = participants_count;
	emit participantsCountChanged();
}

const TLVector<User*>& ChatInvite::participants() const
{
	return this->_participants;
}

void ChatInvite::setParticipants(const TLVector<User*>& participants) 
{
	if(this->_participants == participants)
		return;

	this->_participants = participants;
	emit participantsChanged();
}

