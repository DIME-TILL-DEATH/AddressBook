#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <QSqlQuery>
#include <QSqlError>
#include <QVariantList>

#include "connectionmanager.h"
#include "dbtypes.h"

namespace db {
class Executor
{
public:
    Executor();
    Q_DISABLE_COPY(Executor)
    std::pair<DBResult, QSqlQuery> execute(const QString& queryText, const QVariantList& args = {});
private:
    ConnectionManager& m_connectionManager;
};
}
#endif // EXECUTOR_H
