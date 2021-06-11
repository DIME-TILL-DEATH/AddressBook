#pragma once

#include "contactsreader.h"
#include "package.h"
#include <QObject>


class QTcpSocket;
class ContactsWorker :  public QObject
{
    Q_OBJECT
public:
    void handleContactsRequest(QTcpSocket* socket);

signals:
    void contactsRequestCompleted(const net::Package& packageData, QTcpSocket* socket);

private:
    ContactsReader m_contactsReader;
};
