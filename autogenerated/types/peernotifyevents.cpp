// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "peernotifyevents.h"

PeerNotifyEvents::PeerNotifyEvents(QObject* parent) : TelegramObject(parent)
{
	
}

void PeerNotifyEvents::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == PeerNotifyEvents::ctorPeerNotifyEventsEmpty) ||
		 (this->_constructorid == PeerNotifyEvents::ctorPeerNotifyEventsAll));
}

void PeerNotifyEvents::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == PeerNotifyEvents::ctorPeerNotifyEventsEmpty) ||
		 (this->_constructorid == PeerNotifyEvents::ctorPeerNotifyEventsAll));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
}

void PeerNotifyEvents::compileFlags() 
{
	
}

