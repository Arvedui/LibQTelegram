// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "messagesbotresults.h"


MessagesBotResults::MessagesBotResults(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_is_gallery = false;
	this->_query_id = 0;
	this->_switch_pm = NULL;
	this->_constructorid = MessagesBotResults::ctorMessagesBotResults;
}

void MessagesBotResults::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MessagesBotResults::ctorMessagesBotResults));
	
	if(this->_constructorid == MessagesBotResults::ctorMessagesBotResults)
	{
		this->_flags = mtstream->readTLInt();
		this->_is_gallery = IS_FLAG_SET(this->_flags, 0);
		this->_query_id = mtstream->readTLLong();
		if(IS_FLAG_SET(this->_flags, 1))
			this->_next_offset = mtstream->readTLString();
		
		if(IS_FLAG_SET(this->_flags, 2))
		{
			RESET_TLTYPE(InlineBotSwitchPM, this->_switch_pm);
			this->_switch_pm->read(mtstream);
		}
		
		mtstream->readTLVector<BotInlineResult>(this->_results, false);
	}
}

void MessagesBotResults::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MessagesBotResults::ctorMessagesBotResults));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MessagesBotResults::ctorMessagesBotResults)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLLong(this->_query_id);
		if(IS_FLAG_SET(this->_flags, 1))
			mtstream->writeTLString(this->_next_offset);
		
		if(IS_FLAG_SET(this->_flags, 2))
		{
			Q_ASSERT(this->_switch_pm != NULL);
			this->_switch_pm->write(mtstream);
		}
		
		mtstream->writeTLVector(this->_results, false);
	}
}

void MessagesBotResults::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == MessagesBotResults::ctorMessagesBotResults)
	{
		if(this->_is_gallery)
			SET_FLAG_BIT(this->_flags, 0);
		if(!this->_next_offset.isEmpty())
			SET_FLAG_BIT(this->_flags, 1);
		if(this->_switch_pm)
			SET_FLAG_BIT(this->_flags, 2);
	}
}

TLInt MessagesBotResults::flags() const
{
	return this->_flags;
}

void MessagesBotResults::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLTrue MessagesBotResults::isGallery() const
{
	return this->_is_gallery;
}

void MessagesBotResults::setIsGallery(TLTrue is_gallery) 
{
	if(this->_is_gallery == is_gallery)
		return;

	this->_is_gallery = is_gallery;
	emit isGalleryChanged();
}

TLLong MessagesBotResults::queryId() const
{
	return this->_query_id;
}

void MessagesBotResults::setQueryId(TLLong query_id) 
{
	if(this->_query_id == query_id)
		return;

	this->_query_id = query_id;
	emit queryIdChanged();
}

TLString MessagesBotResults::nextOffset() const
{
	return this->_next_offset;
}

void MessagesBotResults::setNextOffset(TLString next_offset) 
{
	if(this->_next_offset == next_offset)
		return;

	this->_next_offset = next_offset;
	emit nextOffsetChanged();
}

InlineBotSwitchPM* MessagesBotResults::switchPm() const
{
	return this->_switch_pm;
}

void MessagesBotResults::setSwitchPm(InlineBotSwitchPM* switch_pm) 
{
	if(this->_switch_pm == switch_pm)
		return;

	this->_switch_pm = switch_pm;
	emit switchPmChanged();
}

const TLVector<BotInlineResult*>& MessagesBotResults::results() const
{
	return this->_results;
}

void MessagesBotResults::setResults(const TLVector<BotInlineResult*>& results) 
{
	if(this->_results == results)
		return;

	this->_results = results;
	emit resultsChanged();
}

