#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name_val, double bal_val, double rate_val) : Savings_Account(name_val, bal_val, rate_val), withdraw_counter{0}
{
}

bool Trust_Account::deposit(double amount)
{
    if (amount >= def_bonus_deposit)
    {
        amount += def_bonus;
    }
    
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if (withdraw_counter < def_withdraw_counter && amount < balance * (def_withdraw_limite / 100))
    {
        ++withdraw_counter;
        return Savings_Account::withdraw(amount);
    }
    else return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
    os << "[Trust_account: " << account.name << " balance: " << account.balance << " int_rate: " << account.int_rate << " withdrawals: " << account.withdraw_counter;
    return os;
}