#include "Chacking_Account.h"

Chacking_Account::Chacking_Account(std::string name_val, double bal_val) : Account(name_val, bal_val)
{
}

bool Chacking_Account::withdraw(double amount)
{
    amount += def_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Chacking_Account &account)
{
    os << "Chacking_Account name: " << account.name << " balance: " << account.balance << " fee: " << account.def_fee;
    return os;
}

double Chacking_Account::get_fee() const
{
    return def_fee;
}