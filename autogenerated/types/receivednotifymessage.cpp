// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "receivednotifymessage.h"


ReceivedNotifyMessage::ReceivedNotifyMessage(QObject* parent) : TelegramObject(parent)
{
	this->_id = 0;
	this->_flags = 0;
	this->_constructorid = ReceivedNotifyMessage::ctorReceivedNotifyMessage;
}

void ReceivedNotifyMessage::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == ReceivedNotifyMessage::ctorReceivedNotifyMessage));
	
	if(this->_constructorid == ReceivedNotifyMessage::ctorReceivedNotifyMessage)
	{
		this->_id = mtstream->readTLInt();
		this->_flags = mtstream->readTLInt();
	}
}

void ReceivedNotifyMessage::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == ReceivedNotifyMessage::ctorReceivedNotifyMessage));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == ReceivedNotifyMessage::ctorReceivedNotifyMessage)
	{
		mtstream->writeTLInt(this->_id);
		mtstream->writeTLInt(this->_flags);
	}
}

void ReceivedNotifyMessage::compileFlags() 
{
	
}

TLInt ReceivedNotifyMessage::id() const
{
	return this->_id;
}

void ReceivedNotifyMessage::setId(TLInt id) 
{
	if(this->_id == id)
		return;

	this->_id = id;
	emit idChanged();
}

TLInt ReceivedNotifyMessage::flags() const
{
	return this->_flags;
}

void ReceivedNotifyMessage::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

