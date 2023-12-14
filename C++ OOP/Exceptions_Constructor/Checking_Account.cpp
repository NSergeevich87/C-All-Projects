#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name_val, double bal_val) :
    Account(name_val, bal_val) {
        
    }
    
void Checking_Account::print(std::ostream &os) const
{
    os.precision(2);
    os << std::fixed;
    
    os << "Checking_Account: " << name << " " << balance << " " << def_fee;
}

bool Checking_Account::deposit(double amount)
{
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount)
{
    amount += def_fee;
    return Account::withdraw(amount);
}