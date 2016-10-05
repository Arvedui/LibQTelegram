// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "inputbotinlinemessageid.h"


InputBotInlineMessageID::InputBotInlineMessageID(QObject* parent) : TelegramObject(parent)
{
	this->_dc_id = 0;
	this->_id = 0;
	this->_access_hash = 0;
	this->_constructorid = InputBotInlineMessageID::ctorInputBotInlineMessageID;
}

void InputBotInlineMessageID::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == InputBotInlineMessageID::ctorInputBotInlineMessageID));
	
	if(this->_constructorid == InputBotInlineMessageID::ctorInputBotInlineMessageID)
	{
		this->_dc_id = mtstream->readTLInt();
		this->_id = mtstream->readTLLong();
		this->_access_hash = mtstream->readTLLong();
	}
}

void InputBotInlineMessageID::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == InputBotInlineMessageID::ctorInputBotInlineMessageID));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == InputBotInlineMessageID::ctorInputBotInlineMessageID)
	{
		mtstream->writeTLInt(this->_dc_id);
		mtstream->writeTLLong(this->_id);
		mtstream->writeTLLong(this->_access_hash);
	}
}

void InputBotInlineMessageID::compileFlags() 
{
	
}

TLInt InputBotInlineMessageID::dcId() const
{
	return this->_dc_id;
}

void InputBotInlineMessageID::setDcId(TLInt dc_id) 
{
	if(this->_dc_id == dc_id)
		return;

	this->_dc_id = dc_id;
	emit dcIdChanged();
}

TLLong InputBotInlineMessageID::id() const
{
	return this->_id;
}

void InputBotInlineMessageID::setId(TLLong id) 
{
	if(this->_id == id)
		return;

	this->_id = id;
	emit idChanged();
}

TLLong InputBotInlineMessageID::accessHash() const
{
	return this->_access_hash;
}

void InputBotInlineMessageID::setAccessHash(TLLong access_hash) 
{
	if(this->_access_hash == access_hash)
		return;

	this->_access_hash = access_hash;
	emit accessHashChanged();
}

