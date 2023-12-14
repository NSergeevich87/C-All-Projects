#include "Account.h"

Account::Account(std::string name_val, double bal_val) : name{name_val}, balance{bal_val}
{
    if (bal_val < 0) throw IllegalBalanceException{};
}

void Account::print(std::ostream &os) const
{
    os.precision(2);
    os << std::fixed;
    
    os << "Account: " << name << " " << balance;
}

bool Account::deposit(double amount)
{
    if (amount <= 0)
    {   
        return false;
    }
    else
    {
        balance += amount;
        return true;
    }
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