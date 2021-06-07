#include "Manipulator.h"
#include "dbmapper.h"

#include <sstream>

namespace db {

std::pair<db::DBResult, db::DBIndex> db::Manipulator::insertRow(const QString &tableName, const QVariantList &recordData)
{
    const QString& query {generateInsertQuery(tableName, recordData.size())};
    const auto& result {m_executor.execute(query, recordData)};
    return {result.first, result.second.lastInsertId().toInt()};
}

QString Manipulator::generateBindString(size_t recordSize) const
{
    std::ostringstream bindings;
    std::fill_n(std::ostream_iterator<std::string>(bindings),
                recordSize,
                "?,");
    std::string bindString = bindings.str();
    bindString.pop_back();

    return QString::fromStdString(bindString);
}

QString Manipulator::generateInsertQuery(const QString &tableName, size_t recordSize) const
{
    QString query {"INSERT INTO " + tableName + " (" + TablesMapping.at(tableName) + ")" +
                   "VALUES ("};
    query += generateBindString(recordSize);
    query += ")";
    return query;
}
}
