// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "authpasswordrecovery.h"


AuthPasswordRecovery::AuthPasswordRecovery(QObject* parent) : TelegramObject(parent)
{
	this->_constructorid = AuthPasswordRecovery::ctorAuthPasswordRecovery;
}

void AuthPasswordRecovery::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == AuthPasswordRecovery::ctorAuthPasswordRecovery));
	
	if(this->_constructorid == AuthPasswordRecovery::ctorAuthPasswordRecovery)
		this->_email_pattern = mtstream->readTLString();
}

void AuthPasswordRecovery::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == AuthPasswordRecovery::ctorAuthPasswordRecovery));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == AuthPasswordRecovery::ctorAuthPasswordRecovery)
		mtstream->writeTLString(this->_email_pattern);
}

void AuthPasswordRecovery::compileFlags() 
{
	
}

TLString AuthPasswordRecovery::emailPattern() const
{
	return this->_email_pattern;
}

void AuthPasswordRecovery::setEmailPattern(TLString email_pattern) 
{
	if(this->_email_pattern == email_pattern)
		return;

	this->_email_pattern = email_pattern;
	emit emailPatternChanged();
}

