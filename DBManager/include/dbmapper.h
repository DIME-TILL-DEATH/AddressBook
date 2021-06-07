#ifndef DBMAPPER_H
#define DBMAPPER_H

#include <QString>

#include "dbtypes.h"

namespace db
{
static const std::map<DBTables, QString> TableMapper
{
    {DBTables::Contacts, "Contacts"}
};

static const std::map<QString, QString> TablesMapping
{
    {"Contacts", "Name, Surname, PhoneNumber"}
};
}

#endif // DBMAPPER_H
