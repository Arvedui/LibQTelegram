// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "msgresendreq.h"


MsgResendReq::MsgResendReq(QObject* parent) : TelegramObject(parent)
{
	this->_constructorid = MsgResendReq::ctorMsgResendReq;
}

void MsgResendReq::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == MsgResendReq::ctorMsgResendReq));
	
	if(this->_constructorid == MsgResendReq::ctorMsgResendReq)
		mtstream->readTLVector<TLLong>(this->_msg_ids, false);
}

void MsgResendReq::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == MsgResendReq::ctorMsgResendReq));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == MsgResendReq::ctorMsgResendReq)
		mtstream->writeTLVector(this->_msg_ids, false);
}

void MsgResendReq::compileFlags() 
{
	
}

const TLVector<TLLong>& MsgResendReq::msgIds() const
{
	return this->_msg_ids;
}

void MsgResendReq::setMsgIds(const TLVector<TLLong>& msg_ids) 
{
	if(this->_msg_ids == msg_ids)
		return;

	this->_msg_ids = msg_ids;
	emit msgIdsChanged();
}

