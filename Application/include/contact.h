#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact() = default;
    Contact(QString firstName, QString surname, QString phone);

    const QString &phone() const;
    const QString &firstName() const;
    const QString &surname() const;

private:
    QString m_phone;
    QString m_firstName;
    QString m_surname;
};

#endif // CONTACT_H
