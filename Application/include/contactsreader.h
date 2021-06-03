#ifndef CONTACTSREADER_H
#define CONTACTSREADER_H

#include <vector>

#include "contact.h"

class ContactsReader
{
public:
    std::pair<bool, std::vector<Contact>> requestContactsBrowse();
};

#endif // CONTACTSREADER_H
