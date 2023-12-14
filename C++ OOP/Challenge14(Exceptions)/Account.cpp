#include "Account.h"

Account::Account(std::string name_val, double bal_val) : name{name_val}, balance{bal_val}
{
    
}

bool Account::withdraw(double amount)
{
    if ((balance - amount) >= 0)
    {
        balance -= amount;
        return true;
    }
    else
    {
        return false;
    }
}