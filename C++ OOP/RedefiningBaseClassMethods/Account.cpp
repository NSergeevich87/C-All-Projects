#include "Account.h"

std::ostream &operator<<(std::ostream &os, const Account &account)
{
    os << "Account balance: " << account.balance;
    return os;
}

Account::Account() : Account(0.0)
{
}

Account::Account(double val) : balance{val}
{
}

void Account::deposit(double amount)
{
    balance += amount;
}

void Account::withdraw(double amount)
{
    if ((balance - amount) >= 0)
    {
        balance -= amount;
    }
    else
    {
        std::cout << "Insufficiente balance!" << std::endl;
    }
}