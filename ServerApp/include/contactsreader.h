#ifndef CONTACTSREADER_H
#define CONTACTSREADER_H

#include <vector>
#include <memory>
#include <QVariant>

namespace db {
class Processor;
}

class ContactsReader
{
public:
    std::pair<bool, std::vector<QVariant>> requestContactsBrowse();

    ContactsReader();
    ~ContactsReader();
private:
    std::unique_ptr<db::Processor> m_processor;
};

#endif // CONTACTSREADER_H
