#ifndef ACCOUNTAUTHORIZATIONS_H
#define ACCOUNTAUTHORIZATIONS_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "authorization.h"
#include "../../types/telegramobject.h"

class AccountAuthorizations: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLVector<Authorization*> authorizations READ authorizations WRITE setAuthorizations NOTIFY authorizationsChanged)

	public:
		enum Constructors {
			ctorAccountAuthorizations = 0x1250abde,
		};

	public:
		explicit AccountAuthorizations(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		const TLVector<Authorization*>& authorizations() const;
		void setAuthorizations(const TLVector<Authorization*>& authorizations);

	signals:
		void authorizationsChanged();

	private:
		TLVector<Authorization*> _authorizations;

};

#endif // ACCOUNTAUTHORIZATIONS_H
