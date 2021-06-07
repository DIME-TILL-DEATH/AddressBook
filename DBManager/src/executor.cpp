#include <QDebug>

#include "executor.h"

namespace db {

Executor::Executor()
    : m_connectionManager{ConnectionManager::instance()}
{

}

std::pair<DBResult, QSqlQuery> Executor::execute(const QString &queryText, const QVariantList &args)
{
    if(!m_connectionManager.isValid())
    {
        qCritical() << "Database is not valid, skip!";
        return std::make_pair(DBResult::FAIL, QSqlQuery{});
    }

    QSqlQuery query{queryText};

    for(int i = 0; i < args.size(); ++i)
    {
        query.bindValue(i, args[i]);
    }

    DBResult result{DBResult::OK};

    if(!query.exec() && query.lastError().isValid())
    {
        qCritical() << query.lastError().text() << query.lastQuery();
        result = DBResult::FAIL;
    }

    return {result, query};
}
}
