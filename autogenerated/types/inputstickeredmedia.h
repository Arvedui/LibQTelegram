#ifndef INPUTSTICKEREDMEDIA_H
#define INPUTSTICKEREDMEDIA_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "inputdocument.h"
#include "../../types/telegramobject.h"
#include "inputphoto.h"

class InputStickeredMedia: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(InputPhoto* idInputstickeredmediaphoto READ idInputstickeredmediaphoto WRITE setIdInputstickeredmediaphoto NOTIFY idInputstickeredmediaphotoChanged)
	Q_PROPERTY(InputDocument* idInputstickeredmediadocument READ idInputstickeredmediadocument WRITE setIdInputstickeredmediadocument NOTIFY idInputstickeredmediadocumentChanged)

	public:
		enum Constructors {
			ctorInputStickeredMediaPhoto = 0x4a992157,
			ctorInputStickeredMediaDocument = 0x438865b,
		};

	public:
		explicit InputStickeredMedia(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		InputPhoto* idInputstickeredmediaphoto() const;
		void setIdInputstickeredmediaphoto(InputPhoto* id_inputstickeredmediaphoto);
		InputDocument* idInputstickeredmediadocument() const;
		void setIdInputstickeredmediadocument(InputDocument* id_inputstickeredmediadocument);

	signals:
		void idInputstickeredmediaphotoChanged();
		void idInputstickeredmediadocumentChanged();

	private:
		InputPhoto* _id_inputstickeredmediaphoto;
		InputDocument* _id_inputstickeredmediadocument;

};

#endif // INPUTSTICKEREDMEDIA_H
