// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "keyboardbutton.h"


KeyboardButton::KeyboardButton(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_is_same_peer = false;
}

void KeyboardButton::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == KeyboardButton::CtorKeyboardButton) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonUrl) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonCallback) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonRequestPhone) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonRequestGeoLocation) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonSwitchInline) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonGame));
	
	if(this->_constructorid == KeyboardButton::CtorKeyboardButton)
		this->_text = mtstream->readTLString();
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonUrl)
	{
		this->_text = mtstream->readTLString();
		this->_url = mtstream->readTLString();
	}
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonCallback)
	{
		this->_text = mtstream->readTLString();
		this->_data = mtstream->readTLBytes();
	}
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonRequestPhone)
		this->_text = mtstream->readTLString();
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonRequestGeoLocation)
		this->_text = mtstream->readTLString();
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonSwitchInline)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_same_peer = IS_FLAG_SET(this->_flags, 0);
		this->_text = mtstream->readTLString();
		this->_query = mtstream->readTLString();
	}
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonGame)
		this->_text = mtstream->readTLString();
}

void KeyboardButton::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == KeyboardButton::CtorKeyboardButton) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonUrl) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonCallback) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonRequestPhone) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonRequestGeoLocation) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonSwitchInline) ||
		 (this->_constructorid == KeyboardButton::CtorKeyboardButtonGame));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == KeyboardButton::CtorKeyboardButton)
		mtstream->writeTLString(this->_text);
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonUrl)
	{
		mtstream->writeTLString(this->_text);
		mtstream->writeTLString(this->_url);
	}
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonCallback)
	{
		mtstream->writeTLString(this->_text);
		mtstream->writeTLBytes(this->_data);
	}
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonRequestPhone)
		mtstream->writeTLString(this->_text);
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonRequestGeoLocation)
		mtstream->writeTLString(this->_text);
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonSwitchInline)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLString(this->_text);
		mtstream->writeTLString(this->_query);
	}
	else if(this->_constructorid == KeyboardButton::CtorKeyboardButtonGame)
		mtstream->writeTLString(this->_text);
}

void KeyboardButton::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == KeyboardButton::CtorKeyboardButtonSwitchInline)
	{
		if(this->_is_same_peer)
			SET_FLAG_BIT(this->_flags, 0);
	}
}

TLString KeyboardButton::text() const
{
	return this->_text;
}

void KeyboardButton::setText(TLString text) 
{
	if(this->_text == text)
		return;

	this->_text = text;
	emit textChanged();
}

TLString KeyboardButton::url() const
{
	return this->_url;
}

void KeyboardButton::setUrl(TLString url) 
{
	if(this->_url == url)
		return;

	this->_url = url;
	emit urlChanged();
}

TLBytes KeyboardButton::data() const
{
	return this->_data;
}

void KeyboardButton::setData(TLBytes data) 
{
	if(this->_data == data)
		return;

	this->_data = data;
	emit dataChanged();
}

TLInt KeyboardButton::flags() const
{
	return this->_flags;
}

void KeyboardButton::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLTrue KeyboardButton::isSamePeer() const
{
	return this->_is_same_peer;
}

void KeyboardButton::setIsSamePeer(TLTrue is_same_peer) 
{
	if(this->_is_same_peer == is_same_peer)
		return;

	this->_is_same_peer = is_same_peer;
	emit isSamePeerChanged();
}

TLString KeyboardButton::query() const
{
	return this->_query;
}

void KeyboardButton::setQuery(TLString query) 
{
	if(this->_query == query)
		return;

	this->_query = query;
	emit queryChanged();
}

