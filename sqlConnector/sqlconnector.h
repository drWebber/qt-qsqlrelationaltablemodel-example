#ifndef SQLCONNECTOR_H
#define SQLCONNECTOR_H

#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqldriver.h>
#include <QtSql/qsqlerror.h>

class SqlConnector
{
private:
    QSqlDatabase db;
public:
    SqlConnector(const QString &databaseName = "database",
            const QString &connectionName = "qt_sql_default_connection");
    ~SqlConnector() { }

    bool open();
    void close();

};

#endif // SQLCONNECTOR_H
