#ifndef PERSONSMODEL_H
#define PERSONSMODEL_H

#include <qsqlrelationaltablemodel.h>

#include <entity/person.h>

class PersonsModel : public QSqlRelationalTableModel
{
public:
    PersonsModel(QObject *parent = nullptr);

    enum Column {
        ID, NAME, EMAIL, STATUS, ACCOUNT_ID
    };

    Person personAt(const QModelIndex &index) const;

    void queryUnemployed();
    void queryEmployed();
    void queryAll();

    void save(const int row, const Person &person);
    void create(const Person &person);
    void remove(const QModelIndex &index);
};

#endif // PERSONSMODEL_H
