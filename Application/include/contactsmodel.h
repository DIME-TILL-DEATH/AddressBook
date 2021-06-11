#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractListModel>
#include <vector>

#include "contact.h"
#include "contactsworker.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactsModel();

    static void registerMe(const std::string &moduleName);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;

private slots:
    void onContactListDownloaded(const std::vector<Contact>& data);

private:
    std::vector<Contact> m_contacts;
    ContactsWorker m_worker;

    enum ContactRoles{
        NameRole = Qt::UserRole + 1,
        SurnameRole,
        PhoneNumberRole
    };

    bool updateContacts();
};

#endif // CONTACTMODEL_H
