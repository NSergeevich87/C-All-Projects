#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name_val, double bal_val, double rate_val) : Savings_Account(name_val, bal_val, rate_val), num_withdrawals{0}
{
}

void Trust_Account::print(std::ostream &os) const
{
    os << "Trust_Account: " << name << " " << balance << " " << int_rate << " num_withdraw: " << num_withdrawals;
}

bool Trust_Account::deposit(double amount)
{
    if (amount >= bonus_threshold) amount += def_bounus;
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if (num_withdrawals < max_withdrawals && (amount <= balance * max_withdraw_percent))
    {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
    return false;
}