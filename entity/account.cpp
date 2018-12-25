#include "account.h"


Account::Account(const int id)
{
    _id = id;
}

int Account::id() const
{
    return _id;
}

Account Account::setId(int id)
{
    _id = id;
    return *this;
}

QString Account::name() const
{
    return _name;
}

Account Account::setName(const QString &name)
{
    _name = name;
    return *this;
}
