#include "Account.h"
#include <string>

void Account::set_name(std::string n)
{
    name = n;
}

std::string Account::get_name()
{
    return name;
}

bool Account::deposit(float val)
{
    balance += val;
    return true;
}

bool Account::withdraw(float val)
{
    if ((balance - val) >= 0)
    {
        balance -= val;
        return true;
    }
    else
    {
        return false;
    }
}

