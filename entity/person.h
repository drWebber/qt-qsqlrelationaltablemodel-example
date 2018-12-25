#ifndef PERSON_H
#define PERSON_H

#include "account.h"

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

    static Person::Status statusToKey(QString _status);
    static QString keyToStatus(const Person::Status &key);

    Person setId(int value);

    Person setName(const QString &value);

    Person setEmail(const QString &value);

    QString stringifiedStatus() const;

    Person setStatus(const Person::Status &value);
    Person setStatus(const QString &value);

    Person &setAccountId(int accountId);

    bool operator==(const Person &person) const;

    int id() const;
    QString name() const;
    QString email() const;
    Status status() const;

    Account accoun() const;
    Person setAccoun(const Account &accoun);

private:
    int _id = 0;
    QString _name;
    QString _email;
    Account _accoun;
    Status _status;

};

inline bool operator==(const Person &a, const Person &b) {
    return a.id() == b.id();
}

#endif // PERSON_H
