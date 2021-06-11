#ifndef CONTACTSWORKER_H
#define CONTACTSWORKER_H

#include <QObject>

#include "contact.h"
#include "clientmanager.h"
#include "networktypes.h"

class ContactsWorker : public QObject
{
    Q_OBJECT
public:
    ContactsWorker();
    bool requestBrowseContacts();

signals:
    void browsingContactsCompleted(const std::vector<Contact>& data);

private slots:
    void onConnectionStateChanged(net::ConnectionState state);    // запросить контакты когда сеть появилась
    void onContactsDownloadSuccessed(const std::vector<QVariant>& data);


private:
    ClientManager& m_clientManager;
};

#endif // CONTACTSWORKER_H
