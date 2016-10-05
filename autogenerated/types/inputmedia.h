#ifndef INPUTMEDIA_H
#define INPUTMEDIA_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "inputfile.h"
#include "inputdocument.h"
#include "../../types/telegramobject.h"
#include "inputgame.h"
#include "documentattribute.h"
#include "inputgeopoint.h"
#include "inputphoto.h"

class InputMedia: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt flags READ flags WRITE setFlags NOTIFY flagsChanged)
	Q_PROPERTY(InputFile* file READ file WRITE setFile NOTIFY fileChanged)
	Q_PROPERTY(TLString caption READ caption WRITE setCaption NOTIFY captionChanged)
	Q_PROPERTY(TLVector<InputDocument*> stickers READ stickers WRITE setStickers NOTIFY stickersChanged)
	Q_PROPERTY(InputPhoto* idInputmediaphoto READ idInputmediaphoto WRITE setIdInputmediaphoto NOTIFY idInputmediaphotoChanged)
	Q_PROPERTY(InputGeoPoint* geoPoint READ geoPoint WRITE setGeoPoint NOTIFY geoPointChanged)
	Q_PROPERTY(TLString phoneNumber READ phoneNumber WRITE setPhoneNumber NOTIFY phoneNumberChanged)
	Q_PROPERTY(TLString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged)
	Q_PROPERTY(TLString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged)
	Q_PROPERTY(TLString mimeType READ mimeType WRITE setMimeType NOTIFY mimeTypeChanged)
	Q_PROPERTY(TLVector<DocumentAttribute*> attributes READ attributes WRITE setAttributes NOTIFY attributesChanged)
	Q_PROPERTY(InputFile* thumb READ thumb WRITE setThumb NOTIFY thumbChanged)
	Q_PROPERTY(InputDocument* idInputmediadocument READ idInputmediadocument WRITE setIdInputmediadocument NOTIFY idInputmediadocumentChanged)
	Q_PROPERTY(TLString title READ title WRITE setTitle NOTIFY titleChanged)
	Q_PROPERTY(TLString address READ address WRITE setAddress NOTIFY addressChanged)
	Q_PROPERTY(TLString provider READ provider WRITE setProvider NOTIFY providerChanged)
	Q_PROPERTY(TLString venueId READ venueId WRITE setVenueId NOTIFY venueIdChanged)
	Q_PROPERTY(TLString url READ url WRITE setUrl NOTIFY urlChanged)
	Q_PROPERTY(TLString q READ q WRITE setQ NOTIFY qChanged)
	Q_PROPERTY(InputGame* idInputmediagame READ idInputmediagame WRITE setIdInputmediagame NOTIFY idInputmediagameChanged)

	public:
		enum Constructors {
			ctorInputMediaEmpty = 0x9664f57f,
			ctorInputMediaUploadedPhoto = 0x630c9af1,
			ctorInputMediaPhoto = 0xe9bfb4f3,
			ctorInputMediaGeoPoint = 0xf9c44144,
			ctorInputMediaContact = 0xa6e45987,
			ctorInputMediaUploadedDocument = 0xd070f1e9,
			ctorInputMediaUploadedThumbDocument = 0x50d88cae,
			ctorInputMediaDocument = 0x1a77f29c,
			ctorInputMediaVenue = 0x2827a81a,
			ctorInputMediaGifExternal = 0x4843b0fd,
			ctorInputMediaPhotoExternal = 0xb55f4f18,
			ctorInputMediaDocumentExternal = 0xe5e9607c,
			ctorInputMediaGame = 0xd33f43f3,
		};

	public:
		explicit InputMedia(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt flags() const;
		void setFlags(TLInt flags);
		InputFile* file() const;
		void setFile(InputFile* file);
		TLString caption() const;
		void setCaption(TLString caption);
		const TLVector<InputDocument*>& stickers() const;
		void setStickers(const TLVector<InputDocument*>& stickers);
		InputPhoto* idInputmediaphoto() const;
		void setIdInputmediaphoto(InputPhoto* id_inputmediaphoto);
		InputGeoPoint* geoPoint() const;
		void setGeoPoint(InputGeoPoint* geo_point);
		TLString phoneNumber() const;
		void setPhoneNumber(TLString phone_number);
		TLString firstName() const;
		void setFirstName(TLString first_name);
		TLString lastName() const;
		void setLastName(TLString last_name);
		TLString mimeType() const;
		void setMimeType(TLString mime_type);
		const TLVector<DocumentAttribute*>& attributes() const;
		void setAttributes(const TLVector<DocumentAttribute*>& attributes);
		InputFile* thumb() const;
		void setThumb(InputFile* thumb);
		InputDocument* idInputmediadocument() const;
		void setIdInputmediadocument(InputDocument* id_inputmediadocument);
		TLString title() const;
		void setTitle(TLString title);
		TLString address() const;
		void setAddress(TLString address);
		TLString provider() const;
		void setProvider(TLString provider);
		TLString venueId() const;
		void setVenueId(TLString venue_id);
		TLString url() const;
		void setUrl(TLString url);
		TLString q() const;
		void setQ(TLString q);
		InputGame* idInputmediagame() const;
		void setIdInputmediagame(InputGame* id_inputmediagame);

	signals:
		void flagsChanged();
		void fileChanged();
		void captionChanged();
		void stickersChanged();
		void idInputmediaphotoChanged();
		void geoPointChanged();
		void phoneNumberChanged();
		void firstNameChanged();
		void lastNameChanged();
		void mimeTypeChanged();
		void attributesChanged();
		void thumbChanged();
		void idInputmediadocumentChanged();
		void titleChanged();
		void addressChanged();
		void providerChanged();
		void venueIdChanged();
		void urlChanged();
		void qChanged();
		void idInputmediagameChanged();

	private:
		TLInt _flags;
		InputFile* _file;
		TLString _caption;
		TLVector<InputDocument*> _stickers;
		InputPhoto* _id_inputmediaphoto;
		InputGeoPoint* _geo_point;
		TLString _phone_number;
		TLString _first_name;
		TLString _last_name;
		TLString _mime_type;
		TLVector<DocumentAttribute*> _attributes;
		InputFile* _thumb;
		InputDocument* _id_inputmediadocument;
		TLString _title;
		TLString _address;
		TLString _provider;
		TLString _venue_id;
		TLString _url;
		TLString _q;
		InputGame* _id_inputmediagame;

};

#endif // INPUTMEDIA_H
