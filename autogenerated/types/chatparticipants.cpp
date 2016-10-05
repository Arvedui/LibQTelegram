// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "chatparticipants.h"


ChatParticipants::ChatParticipants(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_chat_id = 0;
	this->_self_participant = NULL;
	this->_version = 0;
}

void ChatParticipants::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == ChatParticipants::ctorChatParticipantsForbidden) ||
		 (this->_constructorid == ChatParticipants::ctorChatParticipants));
	
	if(this->_constructorid == ChatParticipants::ctorChatParticipantsForbidden)
	{
		this->_flags = mtstream->readTLInt();
		this->_chat_id = mtstream->readTLInt();
		if(IS_FLAG_SET(this->_flags, 0))
		{
			RESET_TLTYPE(ChatParticipant, this->_self_participant);
			this->_self_participant->read(mtstream);
		}
	}
	else if(this->_constructorid == ChatParticipants::ctorChatParticipants)
	{
		this->_chat_id = mtstream->readTLInt();
		mtstream->readTLVector<ChatParticipant>(this->_participants, false);
		this->_version = mtstream->readTLInt();
	}
}

void ChatParticipants::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == ChatParticipants::ctorChatParticipantsForbidden) ||
		 (this->_constructorid == ChatParticipants::ctorChatParticipants));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == ChatParticipants::ctorChatParticipantsForbidden)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLInt(this->_chat_id);
		if(IS_FLAG_SET(this->_flags, 0))
		{
			Q_ASSERT(this->_self_participant != NULL);
			this->_self_participant->write(mtstream);
		}
	}
	else if(this->_constructorid == ChatParticipants::ctorChatParticipants)
	{
		mtstream->writeTLInt(this->_chat_id);
		mtstream->writeTLVector(this->_participants, false);
		mtstream->writeTLInt(this->_version);
	}
}

void ChatParticipants::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == ChatParticipants::ctorChatParticipantsForbidden)
	{
		if(this->_self_participant)
			SET_FLAG_BIT(this->_flags, 0);
	}
}

TLInt ChatParticipants::flags() const
{
	return this->_flags;
}

void ChatParticipants::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLInt ChatParticipants::chatId() const
{
	return this->_chat_id;
}

void ChatParticipants::setChatId(TLInt chat_id) 
{
	if(this->_chat_id == chat_id)
		return;

	this->_chat_id = chat_id;
	emit chatIdChanged();
}

ChatParticipant* ChatParticipants::selfParticipant() const
{
	return this->_self_participant;
}

void ChatParticipants::setSelfParticipant(ChatParticipant* self_participant) 
{
	if(this->_self_participant == self_participant)
		return;

	this->_self_participant = self_participant;
	emit selfParticipantChanged();
}

const TLVector<ChatParticipant*>& ChatParticipants::participants() const
{
	return this->_participants;
}

void ChatParticipants::setParticipants(const TLVector<ChatParticipant*>& participants) 
{
	if(this->_participants == participants)
		return;

	this->_participants = participants;
	emit participantsChanged();
}

TLInt ChatParticipants::version() const
{
	return this->_version;
}

void ChatParticipants::setVersion(TLInt version) 
{
	if(this->_version == version)
		return;

	this->_version = version;
	emit versionChanged();
}

