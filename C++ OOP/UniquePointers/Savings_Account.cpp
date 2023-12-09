#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name_val, double bal_val, double rate_val) : Account(name_val, bal_val), int_rate{rate_val}
{
}

void Savings_Account::print(std::ostream &os) const
{
    os.precision(2);
    os << std::fixed;
    
    os << "Savings_Account: " << name << " " << balance << " " << int_rate;
}

bool Savings_Account::withdraw(double amount)
{
    return Account::withdraw(amount);
}

bool Savings_Account::deposit(double amount)
{
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}