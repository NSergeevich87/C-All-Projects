#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string val_name, double val_bal, double val_rate) : Account(val_name, val_bal), int_rate{val_rate}
{
}

bool Savings_Account::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }
    else
    {
        amount += amount * (int_rate / 100);
        return Account::deposit(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account)
{
    os << "[Savings's Account name: " << account.name << " balance: " << account.balance << " int_rate: " << account.int_rate << "%]";
    return os;
}