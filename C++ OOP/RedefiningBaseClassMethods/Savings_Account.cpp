#include "Savings_Account.h"

Savings_Account::Savings_Account() : Savings_Account(0.0, 0.0)
{
}

Savings_Account::Savings_Account(double balance, double int_rate_val) : Account(balance), int_rate{int_rate_val}
{
}

void Savings_Account::deposit(double amount)
{
    amount += (amount * int_rate / 100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account)
{
    os << "Savings_Account balance: " << account.balance << " with int_rate: " << account.int_rate;
    return os;
}