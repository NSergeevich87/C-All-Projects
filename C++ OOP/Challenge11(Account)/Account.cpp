#include "Account.h"

Account::Account(std::string val_name, double val_bal) : name{val_name}, balance{val_bal}
{
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
        std::cout << "Insufficient balance!" << std::endl;
        return false;
    }
}

double Account::get_balance() const
{
    return balance;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
    os << "[Account name: " << account.name << " balance: " << account.balance << "]";
    return os;
}