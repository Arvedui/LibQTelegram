// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "channelschannelparticipants.h"


ChannelsChannelParticipants::ChannelsChannelParticipants(QObject* parent) : TelegramObject(parent)
{
	this->_count = 0;
	this->_constructorid = ChannelsChannelParticipants::CtorChannelsChannelParticipants;
}

void ChannelsChannelParticipants::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == ChannelsChannelParticipants::CtorChannelsChannelParticipants));
	
	if(this->_constructorid == ChannelsChannelParticipants::CtorChannelsChannelParticipants)
	{
		this->_count = mtstream->readTLInt();
		mtstream->readTLVector<ChannelParticipant>(this->_participants, false, this);
		mtstream->readTLVector<User>(this->_users, false, this);
	}
}

void ChannelsChannelParticipants::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == ChannelsChannelParticipants::CtorChannelsChannelParticipants));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == ChannelsChannelParticipants::CtorChannelsChannelParticipants)
	{
		mtstream->writeTLInt(this->_count);
		mtstream->writeTLVector(this->_participants, false);
		mtstream->writeTLVector(this->_users, false);
	}
}

void ChannelsChannelParticipants::compileFlags() 
{
	
}

TLInt ChannelsChannelParticipants::count() const
{
	return this->_count;
}

void ChannelsChannelParticipants::setCount(TLInt count) 
{
	if(this->_count == count)
		return;

	this->_count = count;
	emit countChanged();
}

const TLVector<ChannelParticipant*>& ChannelsChannelParticipants::participants() const
{
	return this->_participants;
}

void ChannelsChannelParticipants::setParticipants(const TLVector<ChannelParticipant*>& participants) 
{
	if(this->_participants == participants)
		return;

	this->_participants = participants;
	emit participantsChanged();
}

const TLVector<User*>& ChannelsChannelParticipants::users() const
{
	return this->_users;
}

void ChannelsChannelParticipants::setUsers(const TLVector<User*>& users) 
{
	if(this->_users == users)
		return;

	this->_users = users;
	emit usersChanged();
}

