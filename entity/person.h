#ifndef PERSON_H
#define PERSON_H

#include <qstring.h>
#include <qstringlist.h>



class Person
{
public:
    Person () { }
    enum Status {
        EMPLOYED,
        UNEMPLOYED
    };

    static const QStringList statuses;

    static Person::Status statusToKey(QString status);
    static QString keyToStatus(const Person::Status &key);

    int getId() const;
    Person setId(int value);

    QString getName() const;
    Person setName(const QString &value);

    QString getEmail() const;
    Person setEmail(const QString &value);

    Status getStatus() const;
    QString stringifiedStatus() const;
    Person setStatus(const Person::Status &value);
    Person setStatus(const QString &value);

    bool operator==(const Person &person) {
        return person.getId() == id ? true : false;
    }

private:
    int id = 0;
    QString name;
    QString email;
    Status status;

};

#endif // PERSON_H
