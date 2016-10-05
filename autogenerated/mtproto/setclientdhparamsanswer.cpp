// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "setclientdhparamsanswer.h"


SetClientDHParamsAnswer::SetClientDHParamsAnswer(QObject* parent) : TelegramObject(parent)
{
	
}

void SetClientDHParamsAnswer::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == SetClientDHParamsAnswer::ctorDhGenOk) ||
		 (this->_constructorid == SetClientDHParamsAnswer::ctorDhGenRetry) ||
		 (this->_constructorid == SetClientDHParamsAnswer::ctorDhGenFail));
	
	if(this->_constructorid == SetClientDHParamsAnswer::ctorDhGenOk)
	{
		this->_nonce = mtstream->readTLInt128();
		this->_server_nonce = mtstream->readTLInt128();
		this->_new_nonce_hash1 = mtstream->readTLInt128();
	}
	else if(this->_constructorid == SetClientDHParamsAnswer::ctorDhGenRetry)
	{
		this->_nonce = mtstream->readTLInt128();
		this->_server_nonce = mtstream->readTLInt128();
		this->_new_nonce_hash2 = mtstream->readTLInt128();
	}
	else if(this->_constructorid == SetClientDHParamsAnswer::ctorDhGenFail)
	{
		this->_nonce = mtstream->readTLInt128();
		this->_server_nonce = mtstream->readTLInt128();
		this->_new_nonce_hash3 = mtstream->readTLInt128();
	}
}

void SetClientDHParamsAnswer::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == SetClientDHParamsAnswer::ctorDhGenOk) ||
		 (this->_constructorid == SetClientDHParamsAnswer::ctorDhGenRetry) ||
		 (this->_constructorid == SetClientDHParamsAnswer::ctorDhGenFail));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == SetClientDHParamsAnswer::ctorDhGenOk)
	{
		mtstream->writeTLInt128(this->_nonce);
		mtstream->writeTLInt128(this->_server_nonce);
		mtstream->writeTLInt128(this->_new_nonce_hash1);
	}
	else if(this->_constructorid == SetClientDHParamsAnswer::ctorDhGenRetry)
	{
		mtstream->writeTLInt128(this->_nonce);
		mtstream->writeTLInt128(this->_server_nonce);
		mtstream->writeTLInt128(this->_new_nonce_hash2);
	}
	else if(this->_constructorid == SetClientDHParamsAnswer::ctorDhGenFail)
	{
		mtstream->writeTLInt128(this->_nonce);
		mtstream->writeTLInt128(this->_server_nonce);
		mtstream->writeTLInt128(this->_new_nonce_hash3);
	}
}

void SetClientDHParamsAnswer::compileFlags() 
{
	
}

TLInt128 SetClientDHParamsAnswer::nonce() const
{
	return this->_nonce;
}

void SetClientDHParamsAnswer::setNonce(TLInt128 nonce) 
{
	if(this->_nonce == nonce)
		return;

	this->_nonce = nonce;
	emit nonceChanged();
}

TLInt128 SetClientDHParamsAnswer::serverNonce() const
{
	return this->_server_nonce;
}

void SetClientDHParamsAnswer::setServerNonce(TLInt128 server_nonce) 
{
	if(this->_server_nonce == server_nonce)
		return;

	this->_server_nonce = server_nonce;
	emit serverNonceChanged();
}

TLInt128 SetClientDHParamsAnswer::newNonceHash1() const
{
	return this->_new_nonce_hash1;
}

void SetClientDHParamsAnswer::setNewNonceHash1(TLInt128 new_nonce_hash1) 
{
	if(this->_new_nonce_hash1 == new_nonce_hash1)
		return;

	this->_new_nonce_hash1 = new_nonce_hash1;
	emit newNonceHash1Changed();
}

TLInt128 SetClientDHParamsAnswer::newNonceHash2() const
{
	return this->_new_nonce_hash2;
}

void SetClientDHParamsAnswer::setNewNonceHash2(TLInt128 new_nonce_hash2) 
{
	if(this->_new_nonce_hash2 == new_nonce_hash2)
		return;

	this->_new_nonce_hash2 = new_nonce_hash2;
	emit newNonceHash2Changed();
}

TLInt128 SetClientDHParamsAnswer::newNonceHash3() const
{
	return this->_new_nonce_hash3;
}

void SetClientDHParamsAnswer::setNewNonceHash3(TLInt128 new_nonce_hash3) 
{
	if(this->_new_nonce_hash3 == new_nonce_hash3)
		return;

	this->_new_nonce_hash3 = new_nonce_hash3;
	emit newNonceHash3Changed();
}

