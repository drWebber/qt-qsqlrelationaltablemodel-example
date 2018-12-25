#include "personsmodel.h"

#include <QSqlQuery>
#include <qsqlerror.h>
#include <qdebug.h>

PersonsModel::PersonsModel(QObject *parent) : QSqlRelationalTableModel(parent)
{
    setTable("Person");
    setRelation(4, QSqlRelation("Account", "id", "name"));
}

Person PersonsModel::personAt(const QModelIndex &item) const
{
    int row = item.row();
    return Person().setId(data(index(row, ID)).toInt())
            .setName(data(index(row, NAME)).toString())
            .setEmail(data(index(row, EMAIL)).toString())
            .setAccountId(data(index(row, ACCOUNT_ID)).toInt())
            .setStatus(data(index(row, STATUS)).toString());
}

void PersonsModel::queryUnemployed()
{
    setFilter("`status` = 'UNEMPLOYED'");
}

void PersonsModel::queryEmployed()
{
    setFilter("`status` = 'EMPLOYED'");
}

void PersonsModel::queryAll()
{
    setFilter("");
}

void PersonsModel::save(const int row, const Person &person)
{
    setData(index(row, NAME), person.name());
    setData(index(row, EMAIL), person.email());
    setData(index(row, ACCOUNT_ID), person.accoun().id());
    setData(index(row, STATUS), person.stringifiedStatus());
    submitAll();
}

void PersonsModel::create(const Person &person)
{
    int row = rowCount();
    insertRow(row);

    setData(index(row, NAME), person.name());
    setData(index(row, EMAIL), person.email());
    setData(index(row, STATUS), person.stringifiedStatus());
    setData(index(row, ACCOUNT_ID), person.accoun().id());
    submitAll();
}

void PersonsModel::remove(const QModelIndex &index)
{
    removeRow(index.row());
    select();
}
