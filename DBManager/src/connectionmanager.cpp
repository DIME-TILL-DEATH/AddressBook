#include "connectionmanager.h"
#include "dbtypes.h"

#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>

namespace db
{

namespace
{
    class DBCloser
    {
    public:
        void operator()(QSqlDatabase* db)
        {
            db->close();
            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
            delete db;
        }
    };
}
struct ConnectionManager::ConnectionManagerPrivate
{
    std::unique_ptr<QSqlDatabase, DBCloser> database;
    QString dbPath;
    bool isValid {true};
    DBState state {DBState::OK};

    bool setup();
    bool setupWorkspace();
    bool setupTables();
};

ConnectionManager &ConnectionManager::instance()
{
    // static инициализируется один раз
    static ConnectionManager instance;
    return instance;
}

bool ConnectionManager::isValid() const
{
    return m_d->isValid;
}

ConnectionManager::ConnectionManager()
    : m_d {new ConnectionManagerPrivate{}}
{
    const bool setupResult {m_d->setup()};
    m_d->isValid = setupResult;
}

ConnectionManager::~ConnectionManager()
{

}

bool ConnectionManager::ConnectionManagerPrivate::setup()
{
    const QString driver {"QSQLITE"};
    if(!QSqlDatabase::isDriverAvailable(driver))
    {
        state = DBState::ERROR_NO_DRIVER;
        qCritical() << "Driver" << driver << "is not available";
        return false;
    }

    if(!setupWorkspace())
    {
        state = DBState::ERROR_WORKSPACE;
        qCritical() << "Workspace setup failed!";
        return false;
    }

    database.reset(new QSqlDatabase{QSqlDatabase::addDatabase(driver)});
    database->setDatabaseName(dbPath);

    qDebug() << "Database name: " << database->databaseName();

    if(!database->open())
    {
        state = DBState::ERROR_OPENING;
        qCritical() << "Error in opening DB" << database->databaseName()
                    << "reason " << database->lastError().text();
        return false;
    }

    return setupTables();
}

bool ConnectionManager::ConnectionManagerPrivate::setupWorkspace()
{
#ifdef BUILD_TESTS
    static const QString databaseName{"TestDB"};
#else
    static const QString databaseName{"ContactsDB"};
#endif

    const QString location {QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)};
    const QString fullPath {location + "/" + databaseName};

    dbPath = fullPath;

    QDir dbDirectory {location};

    if(!dbDirectory.exists())
    {
        const bool creationResult {dbDirectory.mkpath(location)};
        qInfo() << "DB directory not exist, creating result: " << creationResult;
    }

    qDebug() << "Data path: " << fullPath;

    return dbDirectory.exists();
}

bool ConnectionManager::ConnectionManagerPrivate::setupTables()
{
    bool result{true};

    std::vector<QSqlQuery> creationQueries
    {
        QSqlQuery{
            "CREATE TABLE IF NOT EXISTS Contacts"
            "("
            "Name TEXT,"
            "Surname TEXT,"
            "PhoneNumber TEXT,"
            "UNIQUE(Name, Surname)"
            ")"
        }
    };

    for(auto& query : creationQueries)
    {
        if(!query.exec())
        {
            result = false;
            state = DBState::ERROR_TABLES;
            qWarning() << "Table creation failed. Reason:" <<
                          query.lastError() << "; Query: " << query.lastQuery();
        }
        else
        {
            qInfo() << "Table successfully created! Query: \n" << query.lastQuery();
        }
    }
    return result;
}

}
