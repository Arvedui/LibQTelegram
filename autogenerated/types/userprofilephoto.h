#ifndef USERPROFILEPHOTO_H
#define USERPROFILEPHOTO_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"
#include "filelocation.h"

class UserProfilePhoto: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLLong photoId READ photoId WRITE setPhotoId NOTIFY photoIdChanged)
	Q_PROPERTY(FileLocation* photoSmall READ photoSmall WRITE setPhotoSmall NOTIFY photoSmallChanged)
	Q_PROPERTY(FileLocation* photoBig READ photoBig WRITE setPhotoBig NOTIFY photoBigChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorUserProfilePhotoEmpty = 0x4f11bae1,
			CtorUserProfilePhoto = 0xd559d8c8,
		};

	public:
		explicit UserProfilePhoto(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLLong photoId() const;
		void setPhotoId(TLLong photo_id);
		FileLocation* photoSmall() const;
		void setPhotoSmall(FileLocation* photo_small);
		FileLocation* photoBig() const;
		void setPhotoBig(FileLocation* photo_big);

	signals:
		void photoIdChanged();
		void photoSmallChanged();
		void photoBigChanged();

	private:
		TLLong _photo_id;
		FileLocation* _photo_small;
		FileLocation* _photo_big;

};

#endif // USERPROFILEPHOTO_H
