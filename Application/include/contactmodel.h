#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractListModel>
#include <vector>

#include "contact.h"
#include "contactsreader.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactsModel();

    static void registerMe(const std::string &moduleName);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

private:
    std::vector<Contact> m_contacts;
    ContactsReader m_contactsReader;

    enum ContactRoles{
        NameRole = Qt::UserRole + 1,
        SurnameRole,
        PhoneNumberRole
    };

    bool updateContacts();
};

#endif // CONTACTMODEL_H
