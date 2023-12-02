#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name_val, double bal_val, double rate_val, double val_bonus_deposit, double val_bonus, double val_withdraw_limite, int val_withdraw_counter) 
    : Savings_Account(name_val, bal_val, rate_val), bonus_deposit{val_bonus_deposit}, bonus{val_bonus}, withdraw_limite{val_withdraw_limite}, withdraw_counter{val_withdraw_counter}
{
}

bool Trust_Account::deposit(double amount)
{
    if (amount <= 0) return false;
    else if (amount >= bonus_deposit)
    {
        amount += bonus;
        return Savings_Account::deposit(amount);
    }
    else return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if (withdraw_counter > 0 && amount < balance * (withdraw_limite / 100))
    {
        --withdraw_counter;
        return Account::withdraw(amount);
    }
    else return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
    os << "[Trust_account: " << account.name << " balance: " << account.balance << " int_rate: " << account.int_rate;
    return os;
}