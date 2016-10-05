// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "stickerset.h"


StickerSet::StickerSet(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_is_installed = false;
	this->_is_archived = false;
	this->_is_official = false;
	this->_is_masks = false;
	this->_id = 0;
	this->_access_hash = 0;
	this->_count = 0;
	this->_hash = 0;
	this->_constructorid = StickerSet::ctorStickerSet;
}

void StickerSet::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == StickerSet::ctorStickerSet));
	
	if(this->_constructorid == StickerSet::ctorStickerSet)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_installed = IS_FLAG_SET(this->_flags, 0);
		this->_is_archived = IS_FLAG_SET(this->_flags, 1);
		this->_is_official = IS_FLAG_SET(this->_flags, 2);
		this->_is_masks = IS_FLAG_SET(this->_flags, 3);
		this->_id = mtstream->readTLLong();
		this->_access_hash = mtstream->readTLLong();
		this->_title = mtstream->readTLString();
		this->_short_name = mtstream->readTLString();
		this->_count = mtstream->readTLInt();
		this->_hash = mtstream->readTLInt();
	}
}

void StickerSet::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == StickerSet::ctorStickerSet));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == StickerSet::ctorStickerSet)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLLong(this->_id);
		mtstream->writeTLLong(this->_access_hash);
		mtstream->writeTLString(this->_title);
		mtstream->writeTLString(this->_short_name);
		mtstream->writeTLInt(this->_count);
		mtstream->writeTLInt(this->_hash);
	}
}

void StickerSet::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == StickerSet::ctorStickerSet)
	{
		if(this->_is_installed)
			SET_FLAG_BIT(this->_flags, 0);
		if(this->_is_archived)
			SET_FLAG_BIT(this->_flags, 1);
		if(this->_is_official)
			SET_FLAG_BIT(this->_flags, 2);
		if(this->_is_masks)
			SET_FLAG_BIT(this->_flags, 3);
	}
}

TLInt StickerSet::flags() const
{
	return this->_flags;
}

void StickerSet::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLTrue StickerSet::isInstalled() const
{
	return this->_is_installed;
}

void StickerSet::setIsInstalled(TLTrue is_installed) 
{
	if(this->_is_installed == is_installed)
		return;

	this->_is_installed = is_installed;
	emit isInstalledChanged();
}

TLTrue StickerSet::isArchived() const
{
	return this->_is_archived;
}

void StickerSet::setIsArchived(TLTrue is_archived) 
{
	if(this->_is_archived == is_archived)
		return;

	this->_is_archived = is_archived;
	emit isArchivedChanged();
}

TLTrue StickerSet::isOfficial() const
{
	return this->_is_official;
}

void StickerSet::setIsOfficial(TLTrue is_official) 
{
	if(this->_is_official == is_official)
		return;

	this->_is_official = is_official;
	emit isOfficialChanged();
}

TLTrue StickerSet::isMasks() const
{
	return this->_is_masks;
}

void StickerSet::setIsMasks(TLTrue is_masks) 
{
	if(this->_is_masks == is_masks)
		return;

	this->_is_masks = is_masks;
	emit isMasksChanged();
}

TLLong StickerSet::id() const
{
	return this->_id;
}

void StickerSet::setId(TLLong id) 
{
	if(this->_id == id)
		return;

	this->_id = id;
	emit idChanged();
}

TLLong StickerSet::accessHash() const
{
	return this->_access_hash;
}

void StickerSet::setAccessHash(TLLong access_hash) 
{
	if(this->_access_hash == access_hash)
		return;

	this->_access_hash = access_hash;
	emit accessHashChanged();
}

TLString StickerSet::title() const
{
	return this->_title;
}

void StickerSet::setTitle(TLString title) 
{
	if(this->_title == title)
		return;

	this->_title = title;
	emit titleChanged();
}

TLString StickerSet::shortName() const
{
	return this->_short_name;
}

void StickerSet::setShortName(TLString short_name) 
{
	if(this->_short_name == short_name)
		return;

	this->_short_name = short_name;
	emit shortNameChanged();
}

TLInt StickerSet::count() const
{
	return this->_count;
}

void StickerSet::setCount(TLInt count) 
{
	if(this->_count == count)
		return;

	this->_count = count;
	emit countChanged();
}

TLInt StickerSet::hash() const
{
	return this->_hash;
}

void StickerSet::setHash(TLInt hash) 
{
	if(this->_hash == hash)
		return;

	this->_hash = hash;
	emit hashChanged();
}

