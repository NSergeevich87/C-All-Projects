#include "Account_Util.h"

void display(const std::vector<Account *> &accounts)
{
    std::cout << "\n=============All_Accounts=============" << std::endl;
    for(const auto acc : accounts)
        std::cout << *acc << std::endl;
}

void deposit(std::vector<Account *> &accounts, double amount)
{
    for(auto acc : accounts)
    {
        if (acc->deposit(amount)) std::cout << "Deposit for: " << *acc << " done!" << std::endl;
        else std::cout << "Deposit for: " << *acc << " fail!" << std::endl;
    }
}

void withdraw(std::vector<Account *> &accounts, double amount)
{
    for(auto acc : accounts)
    {
        if (acc->withdraw(amount)) std::cout << "Withdraw for: " << *acc << " done!" << std::endl;
        else std::cout << "Withdraw for: " << *acc << " fail!" << std::endl;
    }
}