#include "contactsreader.h"
#include "Processor.h"
#include "dbtypes.h"

//namespace
//{
//const std::vector<Contact> mockData{
//    {"Will", "Johns", "39823748927523"},
//    {"John", "Bill", "9854457480"}
//};
//}
ContactsReader::ContactsReader()
    : m_processor{new db::Processor{}}
{

}

ContactsReader::~ContactsReader()
{

}

std::vector<QVariant> transform(const std::vector<db::DBEntry>& source)
{
    std::vector<QVariant> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                    [](const db::DBEntry& entry){
                    return QVariant::fromValue(entry);
                    });
    return target;
}

std::pair<bool, std::vector<QVariant> > ContactsReader::requestContactsBrowse()
{
    db::DBResult result;
    std::vector<db::DBEntry> entries;
    std::tie(result, entries) = m_processor->requestTableData(db::DBTables::Contacts);

    return {result == db::DBResult::OK,
                        transform(entries)};
}


