#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name_val, double bal_val, double rate_val) : Account(name_val, bal_val), int_rate{rate_val}
{
}

void Savings_Account::print(std::ostream &os) const
{
    os << "Savings_Account: " << name << " " << balance << " " << int_rate;
}

bool Savings_Account::withdraw(double amount)
{
    if (amount <= 0) return false;
    else
    {
        std::cout << "Withdraw " << amount << " from Savings_Account" << std::endl;
        return Account::withdraw(amount);
    }
}

bool Savings_Account::deposit(double amount)
{
    if (amount <= 0) return false;
    else
    {
        amount += amount * (int_rate/100);
        std::cout << "Deposit " << amount << " to Savings_Account" << std::endl;
        return Account::deposit(amount);
    }
}