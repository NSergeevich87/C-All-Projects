#include "Chacking_Account.h"

Chacking_Account::Chacking_Account(std::string name_val, double bal_val, double fee_val) : Account(name_val, bal_val), fee{fee_val}
{
}

bool Chacking_Account::withdraw(double amount)
{
    if (balance - (amount + fee) <= 0) return false;
    else return balance -= (amount + fee);
}

std::ostream &operator<<(std::ostream &os, const Chacking_Account &account)
{
    os << "Chacking_Account name: " << account.name << " balance: " << account.balance << " fee: " << account.fee;
    return os;
}

double Chacking_Account::get_fee() const
{
    return fee;
}