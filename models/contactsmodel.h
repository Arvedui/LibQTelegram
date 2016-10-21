#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H

#include "abstract/telegrammodel.h"

class ContactsModel : public TelegramModel
{
    Q_OBJECT

    public:
        enum ContactRoles {
            FirstLetterRole = Qt::UserRole + 10,
            FullNameRole,
            StatusText,
        };

    public:
        explicit ContactsModel(QObject *parent = 0);

    public slots:
        void createGroup(const QString &title, const QVariantList &users);

    protected:
        virtual QVariant data(const QModelIndex &index, int role) const;
        virtual int rowCount(const QModelIndex &) const;
        virtual QHash<int, QByteArray> roleNames() const;
        virtual void telegramReady();

    private:
        void sortUsers();

    private:
        QList<User*> _contacts;
};

#endif // CONTACTSMODEL_H
