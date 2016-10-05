// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "inputgame.h"


InputGame::InputGame(QObject* parent) : TelegramObject(parent)
{
	this->_id = 0;
	this->_access_hash = 0;
	this->_bot_id = NULL;
}

void InputGame::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == InputGame::ctorInputGameID) ||
		 (this->_constructorid == InputGame::ctorInputGameShortName));
	
	if(this->_constructorid == InputGame::ctorInputGameID)
	{
		this->_id = mtstream->readTLLong();
		this->_access_hash = mtstream->readTLLong();
	}
	else if(this->_constructorid == InputGame::ctorInputGameShortName)
	{
		RESET_TLTYPE(InputUser, this->_bot_id);
		this->_bot_id->read(mtstream);
		this->_short_name = mtstream->readTLString();
	}
}

void InputGame::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == InputGame::ctorInputGameID) ||
		 (this->_constructorid == InputGame::ctorInputGameShortName));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == InputGame::ctorInputGameID)
	{
		mtstream->writeTLLong(this->_id);
		mtstream->writeTLLong(this->_access_hash);
	}
	else if(this->_constructorid == InputGame::ctorInputGameShortName)
	{
		Q_ASSERT(this->_bot_id != NULL);
		this->_bot_id->write(mtstream);
		mtstream->writeTLString(this->_short_name);
	}
}

void InputGame::compileFlags() 
{
	
}

TLLong InputGame::id() const
{
	return this->_id;
}

void InputGame::setId(TLLong id) 
{
	if(this->_id == id)
		return;

	this->_id = id;
	emit idChanged();
}

TLLong InputGame::accessHash() const
{
	return this->_access_hash;
}

void InputGame::setAccessHash(TLLong access_hash) 
{
	if(this->_access_hash == access_hash)
		return;

	this->_access_hash = access_hash;
	emit accessHashChanged();
}

InputUser* InputGame::botId() const
{
	return this->_bot_id;
}

void InputGame::setBotId(InputUser* bot_id) 
{
	if(this->_bot_id == bot_id)
		return;

	this->_bot_id = bot_id;
	emit botIdChanged();
}

TLString InputGame::shortName() const
{
	return this->_short_name;
}

void InputGame::setShortName(TLString short_name) 
{
	if(this->_short_name == short_name)
		return;

	this->_short_name = short_name;
	emit shortNameChanged();
}

