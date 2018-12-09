#include "sqlconnector.h"


SqlConnector::SqlConnector(const QString &databaseName,
                           const QString &connectionName)
{
    db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName(databaseName + ".db3");
}

bool SqlConnector::open()
{
    return db.open();
}

void SqlConnector::close()
{
    db.close();
}
