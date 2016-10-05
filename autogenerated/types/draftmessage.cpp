// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "draftmessage.h"


DraftMessage::DraftMessage(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_is_no_webpage = false;
	this->_reply_to_msg_id = 0;
	this->_date = 0;
}

void DraftMessage::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == DraftMessage::ctorDraftMessageEmpty) ||
		 (this->_constructorid == DraftMessage::ctorDraftMessage));
	
	if(this->_constructorid == DraftMessage::ctorDraftMessage)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_no_webpage = IS_FLAG_SET(this->_flags, 1);
		if(IS_FLAG_SET(this->_flags, 0))
			this->_reply_to_msg_id = mtstream->readTLInt();
		
		this->_message = mtstream->readTLString();
		if(IS_FLAG_SET(this->_flags, 3))
			mtstream->readTLVector<MessageEntity>(this->_entities, false);
		
		this->_date = mtstream->readTLInt();
	}
}

void DraftMessage::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == DraftMessage::ctorDraftMessageEmpty) ||
		 (this->_constructorid == DraftMessage::ctorDraftMessage));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == DraftMessage::ctorDraftMessage)
	{
		mtstream->writeTLInt(this->_flags);
		if(IS_FLAG_SET(this->_flags, 0))
			mtstream->writeTLInt(this->_reply_to_msg_id);
		
		mtstream->writeTLString(this->_message);
		if(IS_FLAG_SET(this->_flags, 3))
			mtstream->writeTLVector(this->_entities, false);
		
		mtstream->writeTLInt(this->_date);
	}
}

void DraftMessage::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == DraftMessage::ctorDraftMessage)
	{
		if(this->_is_no_webpage)
			SET_FLAG_BIT(this->_flags, 1);
		if(this->_reply_to_msg_id)
			SET_FLAG_BIT(this->_flags, 0);
		if(!this->_entities.isEmpty())
			SET_FLAG_BIT(this->_flags, 3);
	}
}

TLInt DraftMessage::flags() const
{
	return this->_flags;
}

void DraftMessage::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLTrue DraftMessage::isNoWebpage() const
{
	return this->_is_no_webpage;
}

void DraftMessage::setIsNoWebpage(TLTrue is_no_webpage) 
{
	if(this->_is_no_webpage == is_no_webpage)
		return;

	this->_is_no_webpage = is_no_webpage;
	emit isNoWebpageChanged();
}

TLInt DraftMessage::replyToMsgId() const
{
	return this->_reply_to_msg_id;
}

void DraftMessage::setReplyToMsgId(TLInt reply_to_msg_id) 
{
	if(this->_reply_to_msg_id == reply_to_msg_id)
		return;

	this->_reply_to_msg_id = reply_to_msg_id;
	emit replyToMsgIdChanged();
}

TLString DraftMessage::message() const
{
	return this->_message;
}

void DraftMessage::setMessage(TLString message) 
{
	if(this->_message == message)
		return;

	this->_message = message;
	emit messageChanged();
}

const TLVector<MessageEntity*>& DraftMessage::entities() const
{
	return this->_entities;
}

void DraftMessage::setEntities(const TLVector<MessageEntity*>& entities) 
{
	if(this->_entities == entities)
		return;

	this->_entities = entities;
	emit entitiesChanged();
}

TLInt DraftMessage::date() const
{
	return this->_date;
}

void DraftMessage::setDate(TLInt date) 
{
	if(this->_date == date)
		return;

	this->_date = date;
	emit dateChanged();
}

