// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "messagesbotcallbackanswer.h"


MessagesBotCallbackAnswer::MessagesBotCallbackAnswer(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_is_alert = false;
	this->_has_url = false;
	this->_constructorid = MessagesBotCallbackAnswer::ctorMessagesBotCallbackAnswer;
}

void MessagesBotCallbackAnswer::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MessagesBotCallbackAnswer::ctorMessagesBotCallbackAnswer));
	
	if(this->_constructorid == MessagesBotCallbackAnswer::ctorMessagesBotCallbackAnswer)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_alert = IS_FLAG_SET(this->_flags, 1);
		this->_has_url = IS_FLAG_SET(this->_flags, 3);
		if(IS_FLAG_SET(this->_flags, 0))
			this->_message = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 2))
			this->_url = mtstream->readTLString();
	}
}

void MessagesBotCallbackAnswer::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MessagesBotCallbackAnswer::ctorMessagesBotCallbackAnswer));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MessagesBotCallbackAnswer::ctorMessagesBotCallbackAnswer)
	{
		mtstream->writeTLInt(this->_flags);
		if(IS_FLAG_SET(this->_flags, 0))
			mtstream->writeTLString(this->_message);
		
		if(IS_FLAG_SET(this->_flags, 2))
			mtstream->writeTLString(this->_url);
	}
}

void MessagesBotCallbackAnswer::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == MessagesBotCallbackAnswer::ctorMessagesBotCallbackAnswer)
	{
		if(this->_is_alert)
			SET_FLAG_BIT(this->_flags, 1);
		if(this->_has_url)
			SET_FLAG_BIT(this->_flags, 3);
		if(!this->_message.isEmpty())
			SET_FLAG_BIT(this->_flags, 0);
		if(!this->_url.isEmpty())
			SET_FLAG_BIT(this->_flags, 2);
	}
}

TLInt MessagesBotCallbackAnswer::flags() const
{
	return this->_flags;
}

void MessagesBotCallbackAnswer::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLTrue MessagesBotCallbackAnswer::isAlert() const
{
	return this->_is_alert;
}

void MessagesBotCallbackAnswer::setIsAlert(TLTrue is_alert) 
{
	if(this->_is_alert == is_alert)
		return;

	this->_is_alert = is_alert;
	emit isAlertChanged();
}

TLTrue MessagesBotCallbackAnswer::hasUrl() const
{
	return this->_has_url;
}

void MessagesBotCallbackAnswer::setHasUrl(TLTrue has_url) 
{
	if(this->_has_url == has_url)
		return;

	this->_has_url = has_url;
	emit hasUrlChanged();
}

TLString MessagesBotCallbackAnswer::message() const
{
	return this->_message;
}

void MessagesBotCallbackAnswer::setMessage(TLString message) 
{
	if(this->_message == message)
		return;

	this->_message = message;
	emit messageChanged();
}

TLString MessagesBotCallbackAnswer::url() const
{
	return this->_url;
}

void MessagesBotCallbackAnswer::setUrl(TLString url) 
{
	if(this->_url == url)
		return;

	this->_url = url;
	emit urlChanged();
}

