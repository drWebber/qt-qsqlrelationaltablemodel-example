#include "person.h"


const QStringList Person::statuses = QStringList() << "EMPLOYED"
                                                   << "UNEMPLOYED";


Person::Status Person::statusToKey(QString status)
{
    return Status(statuses.indexOf(status));
}

QString Person::keyToStatus(const Person::Status &key)
{
    return statuses.value(key);
}

int Person::getId() const
{
    return id;
}

Person Person::setId(int value)
{
    id = value;
    return *this;
}

QString Person::getName() const
{
    return name;
}

Person Person::setName(const QString &value)
{
    name = value;
    return *this;
}

QString Person::getEmail() const
{
    return email;
}

Person Person::setEmail(const QString &value)
{
    email = value;
    return *this;
}

Person::Status Person::getStatus() const
{
    return status;
}

QString Person::stringifiedStatus() const
{
    return keyToStatus(status);
}

Person Person::setStatus(const Person::Status &value)
{
    status = value;
    return *this;
}

Person Person::setStatus(const QString &value)
{
    status = statusToKey(value);
    return *this;
}
