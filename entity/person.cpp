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

Person Person::setId(int value)
{
    _id = value;
    return *this;
}

Person Person::setName(const QString &value)
{
    _name = value;
    return *this;
}

Person Person::setEmail(const QString &value)
{
    _email = value;
    return *this;
}

QString Person::stringifiedStatus() const
{
    return keyToStatus(_status);
}

Person Person::setStatus(const Person::Status &value)
{
    _status = value;
    return *this;
}

Person Person::setStatus(const QString &value)
{
    _status = statusToKey(value);
    return *this;
}

Person &Person::setAccountId(int accountId)
{
    _accoun = Account(accountId);
    return *this;
}

int Person::id() const
{
    return _id;
}

QString Person::name() const
{
    return _name;
}

QString Person::email() const
{
    return _email;
}

Person::Status Person::status() const
{
    return _status;
}

Account Person::accoun() const
{
    return _accoun;
}

Person Person::setAccoun(const Account &accoun)
{
    _accoun = accoun;
    return *this;
}
