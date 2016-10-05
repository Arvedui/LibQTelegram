// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "updatesdifference.h"


UpdatesDifference::UpdatesDifference(QObject* parent) : TelegramObject(parent)
{
	this->_date = 0;
	this->_seq = 0;
	this->_state = NULL;
	this->_intermediate_state = NULL;
}

void UpdatesDifference::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == UpdatesDifference::ctorUpdatesDifferenceEmpty) ||
		 (this->_constructorid == UpdatesDifference::ctorUpdatesDifference) ||
		 (this->_constructorid == UpdatesDifference::ctorUpdatesDifferenceSlice));
	
	if(this->_constructorid == UpdatesDifference::ctorUpdatesDifferenceEmpty)
	{
		this->_date = mtstream->readTLInt();
		this->_seq = mtstream->readTLInt();
	}
	else if(this->_constructorid == UpdatesDifference::ctorUpdatesDifference)
	{
		mtstream->readTLVector<Message>(this->_new_messages, false);
		mtstream->readTLVector<EncryptedMessage>(this->_new_encrypted_messages, false);
		mtstream->readTLVector<Update>(this->_other_updates, false);
		mtstream->readTLVector<Chat>(this->_chats, false);
		mtstream->readTLVector<User>(this->_users, false);
		RESET_TLTYPE(UpdatesState, this->_state);
		this->_state->read(mtstream);
	}
	else if(this->_constructorid == UpdatesDifference::ctorUpdatesDifferenceSlice)
	{
		mtstream->readTLVector<Message>(this->_new_messages, false);
		mtstream->readTLVector<EncryptedMessage>(this->_new_encrypted_messages, false);
		mtstream->readTLVector<Update>(this->_other_updates, false);
		mtstream->readTLVector<Chat>(this->_chats, false);
		mtstream->readTLVector<User>(this->_users, false);
		RESET_TLTYPE(UpdatesState, this->_intermediate_state);
		this->_intermediate_state->read(mtstream);
	}
}

void UpdatesDifference::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == UpdatesDifference::ctorUpdatesDifferenceEmpty) ||
		 (this->_constructorid == UpdatesDifference::ctorUpdatesDifference) ||
		 (this->_constructorid == UpdatesDifference::ctorUpdatesDifferenceSlice));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == UpdatesDifference::ctorUpdatesDifferenceEmpty)
	{
		mtstream->writeTLInt(this->_date);
		mtstream->writeTLInt(this->_seq);
	}
	else if(this->_constructorid == UpdatesDifference::ctorUpdatesDifference)
	{
		mtstream->writeTLVector(this->_new_messages, false);
		mtstream->writeTLVector(this->_new_encrypted_messages, false);
		mtstream->writeTLVector(this->_other_updates, false);
		mtstream->writeTLVector(this->_chats, false);
		mtstream->writeTLVector(this->_users, false);
		Q_ASSERT(this->_state != NULL);
		this->_state->write(mtstream);
	}
	else if(this->_constructorid == UpdatesDifference::ctorUpdatesDifferenceSlice)
	{
		mtstream->writeTLVector(this->_new_messages, false);
		mtstream->writeTLVector(this->_new_encrypted_messages, false);
		mtstream->writeTLVector(this->_other_updates, false);
		mtstream->writeTLVector(this->_chats, false);
		mtstream->writeTLVector(this->_users, false);
		Q_ASSERT(this->_intermediate_state != NULL);
		this->_intermediate_state->write(mtstream);
	}
}

void UpdatesDifference::compileFlags() 
{
	
}

TLInt UpdatesDifference::date() const
{
	return this->_date;
}

void UpdatesDifference::setDate(TLInt date) 
{
	if(this->_date == date)
		return;

	this->_date = date;
	emit dateChanged();
}

TLInt UpdatesDifference::seq() const
{
	return this->_seq;
}

void UpdatesDifference::setSeq(TLInt seq) 
{
	if(this->_seq == seq)
		return;

	this->_seq = seq;
	emit seqChanged();
}

const TLVector<Message*>& UpdatesDifference::newMessages() const
{
	return this->_new_messages;
}

void UpdatesDifference::setNewMessages(const TLVector<Message*>& new_messages) 
{
	if(this->_new_messages == new_messages)
		return;

	this->_new_messages = new_messages;
	emit newMessagesChanged();
}

const TLVector<EncryptedMessage*>& UpdatesDifference::newEncryptedMessages() const
{
	return this->_new_encrypted_messages;
}

void UpdatesDifference::setNewEncryptedMessages(const TLVector<EncryptedMessage*>& new_encrypted_messages) 
{
	if(this->_new_encrypted_messages == new_encrypted_messages)
		return;

	this->_new_encrypted_messages = new_encrypted_messages;
	emit newEncryptedMessagesChanged();
}

const TLVector<Update*>& UpdatesDifference::otherUpdates() const
{
	return this->_other_updates;
}

void UpdatesDifference::setOtherUpdates(const TLVector<Update*>& other_updates) 
{
	if(this->_other_updates == other_updates)
		return;

	this->_other_updates = other_updates;
	emit otherUpdatesChanged();
}

const TLVector<Chat*>& UpdatesDifference::chats() const
{
	return this->_chats;
}

void UpdatesDifference::setChats(const TLVector<Chat*>& chats) 
{
	if(this->_chats == chats)
		return;

	this->_chats = chats;
	emit chatsChanged();
}

const TLVector<User*>& UpdatesDifference::users() const
{
	return this->_users;
}

void UpdatesDifference::setUsers(const TLVector<User*>& users) 
{
	if(this->_users == users)
		return;

	this->_users = users;
	emit usersChanged();
}

UpdatesState* UpdatesDifference::state() const
{
	return this->_state;
}

void UpdatesDifference::setState(UpdatesState* state) 
{
	if(this->_state == state)
		return;

	this->_state = state;
	emit stateChanged();
}

UpdatesState* UpdatesDifference::intermediateState() const
{
	return this->_intermediate_state;
}

void UpdatesDifference::setIntermediateState(UpdatesState* intermediate_state) 
{
	if(this->_intermediate_state == intermediate_state)
		return;

	this->_intermediate_state = intermediate_state;
	emit intermediateStateChanged();
}

