#ifndef ENCRYPTEDCHAT_H
#define ENCRYPTEDCHAT_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"

class EncryptedChat: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt id READ id WRITE setId NOTIFY idChanged)
	Q_PROPERTY(TLLong accessHash READ accessHash WRITE setAccessHash NOTIFY accessHashChanged)
	Q_PROPERTY(TLInt date READ date WRITE setDate NOTIFY dateChanged)
	Q_PROPERTY(TLInt adminId READ adminId WRITE setAdminId NOTIFY adminIdChanged)
	Q_PROPERTY(TLInt participantId READ participantId WRITE setParticipantId NOTIFY participantIdChanged)
	Q_PROPERTY(TLBytes gA READ gA WRITE setGA NOTIFY gAChanged)
	Q_PROPERTY(TLBytes gAOrB READ gAOrB WRITE setGAOrB NOTIFY gAOrBChanged)
	Q_PROPERTY(TLLong keyFingerprint READ keyFingerprint WRITE setKeyFingerprint NOTIFY keyFingerprintChanged)

	public:
		enum Constructors {
			ctorEncryptedChatEmpty = 0xab7ec0a0,
			ctorEncryptedChatWaiting = 0x3bf703dc,
			ctorEncryptedChatRequested = 0xc878527e,
			ctorEncryptedChat = 0xfa56ce36,
			ctorEncryptedChatDiscarded = 0x13d6dd27,
		};

	public:
		explicit EncryptedChat(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt id() const;
		void setId(TLInt id);
		TLLong accessHash() const;
		void setAccessHash(TLLong access_hash);
		TLInt date() const;
		void setDate(TLInt date);
		TLInt adminId() const;
		void setAdminId(TLInt admin_id);
		TLInt participantId() const;
		void setParticipantId(TLInt participant_id);
		TLBytes gA() const;
		void setGA(TLBytes g_a);
		TLBytes gAOrB() const;
		void setGAOrB(TLBytes g_a_or_b);
		TLLong keyFingerprint() const;
		void setKeyFingerprint(TLLong key_fingerprint);

	signals:
		void idChanged();
		void accessHashChanged();
		void dateChanged();
		void adminIdChanged();
		void participantIdChanged();
		void gAChanged();
		void gAOrBChanged();
		void keyFingerprintChanged();

	private:
		TLInt _id;
		TLLong _access_hash;
		TLInt _date;
		TLInt _admin_id;
		TLInt _participant_id;
		TLBytes _g_a;
		TLBytes _g_a_or_b;
		TLLong _key_fingerprint;

};

#endif // ENCRYPTEDCHAT_H
