// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "inputfile.h"


InputFile::InputFile(QObject* parent) : TelegramObject(parent)
{
	this->_id = 0;
	this->_parts = 0;
}

void InputFile::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == InputFile::ctorInputFile) ||
		 (this->_constructorid == InputFile::ctorInputFileBig));
	
	if(this->_constructorid == InputFile::ctorInputFile)
	{
		this->_id = mtstream->readTLLong();
		this->_parts = mtstream->readTLInt();
		this->_name = mtstream->readTLString();
		this->_md5_checksum = mtstream->readTLString();
	}
	else if(this->_constructorid == InputFile::ctorInputFileBig)
	{
		this->_id = mtstream->readTLLong();
		this->_parts = mtstream->readTLInt();
		this->_name = mtstream->readTLString();
	}
}

void InputFile::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == InputFile::ctorInputFile) ||
		 (this->_constructorid == InputFile::ctorInputFileBig));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == InputFile::ctorInputFile)
	{
		mtstream->writeTLLong(this->_id);
		mtstream->writeTLInt(this->_parts);
		mtstream->writeTLString(this->_name);
		mtstream->writeTLString(this->_md5_checksum);
	}
	else if(this->_constructorid == InputFile::ctorInputFileBig)
	{
		mtstream->writeTLLong(this->_id);
		mtstream->writeTLInt(this->_parts);
		mtstream->writeTLString(this->_name);
	}
}

void InputFile::compileFlags() 
{
	
}

TLLong InputFile::id() const
{
	return this->_id;
}

void InputFile::setId(TLLong id) 
{
	if(this->_id == id)
		return;

	this->_id = id;
	emit idChanged();
}

TLInt InputFile::parts() const
{
	return this->_parts;
}

void InputFile::setParts(TLInt parts) 
{
	if(this->_parts == parts)
		return;

	this->_parts = parts;
	emit partsChanged();
}

TLString InputFile::name() const
{
	return this->_name;
}

void InputFile::setName(TLString name) 
{
	if(this->_name == name)
		return;

	this->_name = name;
	emit nameChanged();
}

TLString InputFile::md5Checksum() const
{
	return this->_md5_checksum;
}

void InputFile::setMd5Checksum(TLString md5_checksum) 
{
	if(this->_md5_checksum == md5_checksum)
		return;

	this->_md5_checksum = md5_checksum;
	emit md5ChecksumChanged();
}

