// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "chatparticipant.h"


ChatParticipant::ChatParticipant(QObject* parent) : TelegramObject(parent)
{
	this->_user_id = 0;
	this->_inviter_id = 0;
	this->_date = 0;
}

void ChatParticipant::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == ChatParticipant::ctorChatParticipant) ||
		 (this->_constructorid == ChatParticipant::ctorChatParticipantCreator) ||
		 (this->_constructorid == ChatParticipant::ctorChatParticipantAdmin));
	
	if(this->_constructorid == ChatParticipant::ctorChatParticipant)
	{
		this->_user_id = mtstream->readTLInt();
		this->_inviter_id = mtstream->readTLInt();
		this->_date = mtstream->readTLInt();
	}
	else if(this->_constructorid == ChatParticipant::ctorChatParticipantCreator)
		this->_user_id = mtstream->readTLInt();
	else if(this->_constructorid == ChatParticipant::ctorChatParticipantAdmin)
	{
		this->_user_id = mtstream->readTLInt();
		this->_inviter_id = mtstream->readTLInt();
		this->_date = mtstream->readTLInt();
	}
}

void ChatParticipant::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == ChatParticipant::ctorChatParticipant) ||
		 (this->_constructorid == ChatParticipant::ctorChatParticipantCreator) ||
		 (this->_constructorid == ChatParticipant::ctorChatParticipantAdmin));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == ChatParticipant::ctorChatParticipant)
	{
		mtstream->writeTLInt(this->_user_id);
		mtstream->writeTLInt(this->_inviter_id);
		mtstream->writeTLInt(this->_date);
	}
	else if(this->_constructorid == ChatParticipant::ctorChatParticipantCreator)
		mtstream->writeTLInt(this->_user_id);
	else if(this->_constructorid == ChatParticipant::ctorChatParticipantAdmin)
	{
		mtstream->writeTLInt(this->_user_id);
		mtstream->writeTLInt(this->_inviter_id);
		mtstream->writeTLInt(this->_date);
	}
}

void ChatParticipant::compileFlags() 
{
	
}

TLInt ChatParticipant::userId() const
{
	return this->_user_id;
}

void ChatParticipant::setUserId(TLInt user_id) 
{
	if(this->_user_id == user_id)
		return;

	this->_user_id = user_id;
	emit userIdChanged();
}

TLInt ChatParticipant::inviterId() const
{
	return this->_inviter_id;
}

void ChatParticipant::setInviterId(TLInt inviter_id) 
{
	if(this->_inviter_id == inviter_id)
		return;

	this->_inviter_id = inviter_id;
	emit inviterIdChanged();
}

TLInt ChatParticipant::date() const
{
	return this->_date;
}

void ChatParticipant::setDate(TLInt date) 
{
	if(this->_date == date)
		return;

	this->_date = date;
	emit dateChanged();
}

