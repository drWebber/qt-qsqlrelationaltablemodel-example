#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <qstring.h>



class Account
{
public:
    Account() { }
    Account(const int id);

    int id() const;
    Account setId(int id);

    QString name() const;
    Account setName(const QString &name);

private:
    int _id;
    QString _name;
};

inline bool operator==(const Account &a, const Account &b) {
    return a.id() == b.id();
}

#endif // ACCOUNT_H
