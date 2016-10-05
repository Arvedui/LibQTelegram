// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "messageshighscores.h"


MessagesHighScores::MessagesHighScores(QObject* parent) : TelegramObject(parent)
{
	this->_constructorid = MessagesHighScores::ctorMessagesHighScores;
}

void MessagesHighScores::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MessagesHighScores::ctorMessagesHighScores));
	
	if(this->_constructorid == MessagesHighScores::ctorMessagesHighScores)
	{
		mtstream->readTLVector<HighScore>(this->_scores, false);
		mtstream->readTLVector<User>(this->_users, false);
	}
}

void MessagesHighScores::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MessagesHighScores::ctorMessagesHighScores));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MessagesHighScores::ctorMessagesHighScores)
	{
		mtstream->writeTLVector(this->_scores, false);
		mtstream->writeTLVector(this->_users, false);
	}
}

void MessagesHighScores::compileFlags() 
{
	
}

const TLVector<HighScore*>& MessagesHighScores::scores() const
{
	return this->_scores;
}

void MessagesHighScores::setScores(const TLVector<HighScore*>& scores) 
{
	if(this->_scores == scores)
		return;

	this->_scores = scores;
	emit scoresChanged();
}

const TLVector<User*>& MessagesHighScores::users() const
{
	return this->_users;
}

void MessagesHighScores::setUsers(const TLVector<User*>& users) 
{
	if(this->_users == users)
		return;

	this->_users = users;
	emit usersChanged();
}

