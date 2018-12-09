#include "mainwindow.h"
#include <QApplication>
#include <qdebug.h>

#include "sqlConnector/sqlconnector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("drwebber's soft");
    QCoreApplication::setApplicationName("qt-qsqlrelationaltablemodel-example");

    SqlConnector connector;
    qDebug() << "db isOpen" << connector.open();

    MainWindow w;
    w.show();

    return a.exec();
}
