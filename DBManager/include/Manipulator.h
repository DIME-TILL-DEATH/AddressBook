#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "executor.h"
#include "dbtypes.h"


namespace db
{
class Manipulator
{
public:
    std::pair<DBResult, DBIndex> insertRow(const QString& tableName,
                                           const QVariantList& recordData);

private:
    Executor m_executor;
    QString generateBindString(size_t recordSize) const;
    QString generateInsertQuery(const QString& tableName, size_t recordSize) const;
};
}

#endif // MANIPULATOR_H
