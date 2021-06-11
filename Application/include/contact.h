#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QVariant>
#include "dbtypes.h"

class Contact
{
public:
    Contact() = default;
    Contact(QString firstName, QString surname, QString phone, db::DBIndex id);

    const QString &phone() const;
    const QString &firstName() const;
    const QString &surname() const;

private:
    QString m_phone;
    QString m_firstName;
    QString m_surname;
    db::DBIndex m_id;
};

#endif // CONTACT_H
