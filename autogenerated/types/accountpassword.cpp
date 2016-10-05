// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "accountpassword.h"


AccountPassword::AccountPassword(QObject* parent) : TelegramObject(parent)
{
	this->_has_recovery = false;
}

void AccountPassword::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == AccountPassword::ctorAccountNoPassword) ||
		 (this->_constructorid == AccountPassword::ctorAccountPassword));
	
	if(this->_constructorid == AccountPassword::ctorAccountNoPassword)
	{
		this->_new_salt = mtstream->readTLBytes();
		this->_email_unconfirmed_pattern = mtstream->readTLString();
	}
	else if(this->_constructorid == AccountPassword::ctorAccountPassword)
	{
		this->_current_salt = mtstream->readTLBytes();
		this->_new_salt = mtstream->readTLBytes();
		this->_hint = mtstream->readTLString();
		this->_has_recovery = mtstream->readTLBool();
		this->_email_unconfirmed_pattern = mtstream->readTLString();
	}
}

void AccountPassword::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == AccountPassword::ctorAccountNoPassword) ||
		 (this->_constructorid == AccountPassword::ctorAccountPassword));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == AccountPassword::ctorAccountNoPassword)
	{
		mtstream->writeTLBytes(this->_new_salt);
		mtstream->writeTLString(this->_email_unconfirmed_pattern);
	}
	else if(this->_constructorid == AccountPassword::ctorAccountPassword)
	{
		mtstream->writeTLBytes(this->_current_salt);
		mtstream->writeTLBytes(this->_new_salt);
		mtstream->writeTLString(this->_hint);
		mtstream->writeTLBool(this->_has_recovery);
		mtstream->writeTLString(this->_email_unconfirmed_pattern);
	}
}

void AccountPassword::compileFlags() 
{
	
}

TLBytes AccountPassword::newSalt() const
{
	return this->_new_salt;
}

void AccountPassword::setNewSalt(TLBytes new_salt) 
{
	if(this->_new_salt == new_salt)
		return;

	this->_new_salt = new_salt;
	emit newSaltChanged();
}

TLString AccountPassword::emailUnconfirmedPattern() const
{
	return this->_email_unconfirmed_pattern;
}

void AccountPassword::setEmailUnconfirmedPattern(TLString email_unconfirmed_pattern) 
{
	if(this->_email_unconfirmed_pattern == email_unconfirmed_pattern)
		return;

	this->_email_unconfirmed_pattern = email_unconfirmed_pattern;
	emit emailUnconfirmedPatternChanged();
}

TLBytes AccountPassword::currentSalt() const
{
	return this->_current_salt;
}

void AccountPassword::setCurrentSalt(TLBytes current_salt) 
{
	if(this->_current_salt == current_salt)
		return;

	this->_current_salt = current_salt;
	emit currentSaltChanged();
}

TLString AccountPassword::hint() const
{
	return this->_hint;
}

void AccountPassword::setHint(TLString hint) 
{
	if(this->_hint == hint)
		return;

	this->_hint = hint;
	emit hintChanged();
}

TLBool AccountPassword::hasRecovery() const
{
	return this->_has_recovery;
}

void AccountPassword::setHasRecovery(TLBool has_recovery) 
{
	if(this->_has_recovery == has_recovery)
		return;

	this->_has_recovery = has_recovery;
	emit hasRecoveryChanged();
}

