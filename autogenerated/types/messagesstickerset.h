#ifndef MESSAGESSTICKERSET_H
#define MESSAGESSTICKERSET_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "stickerpack.h"
#include "../../types/telegramobject.h"
#include "stickerset.h"
#include "document.h"

class MessagesStickerSet: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(StickerSet* set READ set WRITE setSet NOTIFY setChanged)
	Q_PROPERTY(TLVector<StickerPack*> packs READ packs WRITE setPacks NOTIFY packsChanged)
	Q_PROPERTY(TLVector<Document*> documents READ documents WRITE setDocuments NOTIFY documentsChanged)

	public:
		enum Constructors {
			ctorMessagesStickerSet = 0xb60a24a6,
		};

	public:
		explicit MessagesStickerSet(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		StickerSet* set() const;
		void setSet(StickerSet* set);
		const TLVector<StickerPack*>& packs() const;
		void setPacks(const TLVector<StickerPack*>& packs);
		const TLVector<Document*>& documents() const;
		void setDocuments(const TLVector<Document*>& documents);

	signals:
		void setChanged();
		void packsChanged();
		void documentsChanged();

	private:
		StickerSet* _set;
		TLVector<StickerPack*> _packs;
		TLVector<Document*> _documents;

};

#endif // MESSAGESSTICKERSET_H
