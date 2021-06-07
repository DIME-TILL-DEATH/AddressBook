#ifndef CONTACTSREADER_H
#define CONTACTSREADER_H

#include <vector>
#include <memory>
#include "contact.h"

namespace db {
class Processor;
}

class ContactsReader
{
public:
    std::pair<bool, std::vector<Contact>> requestContactsBrowse();

    ContactsReader();
    ~ContactsReader();
private:
    std::unique_ptr<db::Processor> m_processor;
};

#endif // CONTACTSREADER_H
