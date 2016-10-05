#ifndef CONTACTSBLOCKED_H
#define CONTACTSBLOCKED_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "contactblocked.h"
#include "../../types/telegramobject.h"
#include "user.h"

class ContactsBlocked: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLVector<ContactBlocked*> blocked READ blocked WRITE setBlocked NOTIFY blockedChanged)
	Q_PROPERTY(TLVector<User*> users READ users WRITE setUsers NOTIFY usersChanged)
	Q_PROPERTY(TLInt count READ count WRITE setCount NOTIFY countChanged)

	public:
		enum Constructors {
			ctorContactsBlocked = 0x1c138d15,
			ctorContactsBlockedSlice = 0x900802a1,
		};

	public:
		explicit ContactsBlocked(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		const TLVector<ContactBlocked*>& blocked() const;
		void setBlocked(const TLVector<ContactBlocked*>& blocked);
		const TLVector<User*>& users() const;
		void setUsers(const TLVector<User*>& users);
		TLInt count() const;
		void setCount(TLInt count);

	signals:
		void blockedChanged();
		void usersChanged();
		void countChanged();

	private:
		TLVector<ContactBlocked*> _blocked;
		TLVector<User*> _users;
		TLInt _count;

};

#endif // CONTACTSBLOCKED_H
