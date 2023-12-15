#include "Account.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

Account::Account(std::string name_val, double bal_val) : name{name_val}, balance{bal_val}
{
    if (bal_val < 0) throw IllegalBalanceException{};
}

bool Account::withdraw(double amount)
{
    if ((balance - amount) >= 0)
    {
        balance -= amount;
        return true;
    }
    else
    {
        throw InsufficentFundsException{};
        return false;
    }
}

void Account::get_bal()
{
    std::cout << "Balance: " << balance << std::endl;
}