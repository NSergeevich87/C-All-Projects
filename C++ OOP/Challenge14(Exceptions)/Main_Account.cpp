#include "Main_Account.h"

Main_Account::Main_Account(std::string name_val, double bal_val) : Account(name_val, bal_val)
{
}

bool Main_Account::withdraw(double amount)
{
    return Account::withdraw(amount);
}