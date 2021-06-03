#include "contactsreader.h"

namespace
{
const std::vector<Contact> mockData{
    {"Will", "Johns", "39823748927523"},
    {"John", "Bill", "9854457480"}
};
}

std::pair<bool, std::vector<Contact> > ContactsReader::requestContactsBrowse()
{
    return std::make_pair(true, mockData);
}
