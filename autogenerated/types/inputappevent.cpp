// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "inputappevent.h"


InputAppEvent::InputAppEvent(QObject* parent) : TelegramObject(parent)
{
	this->_time = 0;
	this->_peer = 0;
	this->_constructorid = InputAppEvent::CtorInputAppEvent;
}

void InputAppEvent::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == InputAppEvent::CtorInputAppEvent));
	
	if(this->_constructorid == InputAppEvent::CtorInputAppEvent)
	{
		this->_time = mtstream->readTLDouble();
		this->_type = mtstream->readTLString();
		this->_peer = mtstream->readTLLong();
		this->_data = mtstream->readTLString();
	}
}

void InputAppEvent::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == InputAppEvent::CtorInputAppEvent));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == InputAppEvent::CtorInputAppEvent)
	{
		mtstream->writeTLDouble(this->_time);
		mtstream->writeTLString(this->_type);
		mtstream->writeTLLong(this->_peer);
		mtstream->writeTLString(this->_data);
	}
}

void InputAppEvent::compileFlags() 
{
	
}

TLDouble InputAppEvent::time() const
{
	return this->_time;
}

void InputAppEvent::setTime(TLDouble time) 
{
	if(this->_time == time)
		return;

	this->_time = time;
	emit timeChanged();
}

TLString InputAppEvent::type() const
{
	return this->_type;
}

void InputAppEvent::setType(TLString type) 
{
	if(this->_type == type)
		return;

	this->_type = type;
	emit typeChanged();
}

TLLong InputAppEvent::peer() const
{
	return this->_peer;
}

void InputAppEvent::setPeer(TLLong peer) 
{
	if(this->_peer == peer)
		return;

	this->_peer = peer;
	emit peerChanged();
}

TLString InputAppEvent::data() const
{
	return this->_data;
}

void InputAppEvent::setData(TLString data) 
{
	if(this->_data == data)
		return;

	this->_data = data;
	emit dataChanged();
}

