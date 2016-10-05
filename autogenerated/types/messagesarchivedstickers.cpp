// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "messagesarchivedstickers.h"


MessagesArchivedStickers::MessagesArchivedStickers(QObject* parent) : TelegramObject(parent)
{
	this->_count = 0;
	this->_constructorid = MessagesArchivedStickers::ctorMessagesArchivedStickers;
}

void MessagesArchivedStickers::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MessagesArchivedStickers::ctorMessagesArchivedStickers));
	
	if(this->_constructorid == MessagesArchivedStickers::ctorMessagesArchivedStickers)
	{
		this->_count = mtstream->readTLInt();
		mtstream->readTLVector<StickerSetCovered>(this->_sets, false);
	}
}

void MessagesArchivedStickers::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MessagesArchivedStickers::ctorMessagesArchivedStickers));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MessagesArchivedStickers::ctorMessagesArchivedStickers)
	{
		mtstream->writeTLInt(this->_count);
		mtstream->writeTLVector(this->_sets, false);
	}
}

void MessagesArchivedStickers::compileFlags() 
{
	
}

TLInt MessagesArchivedStickers::count() const
{
	return this->_count;
}

void MessagesArchivedStickers::setCount(TLInt count) 
{
	if(this->_count == count)
		return;

	this->_count = count;
	emit countChanged();
}

const TLVector<StickerSetCovered*>& MessagesArchivedStickers::sets() const
{
	return this->_sets;
}

void MessagesArchivedStickers::setSets(const TLVector<StickerSetCovered*>& sets) 
{
	if(this->_sets == sets)
		return;

	this->_sets = sets;
	emit setsChanged();
}

