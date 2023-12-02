#include "Account_Util.h"

//Utils of Account
void display(const std::vector<Account> &accounts)
{
    for (const auto &acc: accounts)
    {
        std::cout << acc << std::endl;
    }
}

void deposit(std::vector<Account> &accounts, double amount)
{
    for (auto &acc: accounts)
    {
        if (acc.deposit(amount)) std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

void withdraw(std::vector<Account> &accounts, double amount)
{
    for (auto &acc: accounts)
    {
        if (acc.withdraw(amount)) std::cout << "Withdraw " << amount << " from " << acc << std::endl;
        else std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}


//Utils of Savings_Account
void display(const std::vector<Savings_Account> &accounts)
{
    std::cout << "===================Savings_Accounts=====================" << std::endl;
    for (const auto &acc: accounts) std::cout << acc << std::endl;
}

void deposit(std::vector<Savings_Account> &accounts, double amount)
{
    std::cout << "===================Deposit_Savings_Accounts=====================" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.deposit(amount)) std::cout << "Deposit: " << amount << " for " << acc << std::endl;
        else std::cout << "Failed! Deposit: " << amount << " for " << acc << std::endl;
    }
}

void withdraw(std::vector<Savings_Account> &accounts, double amount)
{
    std::cout << "===================Withdraw_Savings_Accounts=====================" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.withdraw(amount)) std::cout << "Withdraw: " << amount << " from " << acc << std::endl;
        else std::cout << "Failed! Withdraw: " << amount << " from " << acc << std::endl;
    }
}

//Utils of Chacking_Account
void display(const std::vector<Chacking_Account> &accounts)
{
    std::cout << "====================Chacking_Account====================" << std::endl;
    for (const auto &acc: accounts) std::cout << acc << std::endl;
}

void deposit(std::vector<Chacking_Account> &accounts, double amount)
{
    std::cout << "====================Deposit_Chacking_Account====================" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.deposit(amount)) std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else std::cout << "Failed deposit " << amount << " to " << acc << std::endl;
    }
}

void withdraw(std::vector<Chacking_Account> &accounts, double amount)
{
    std::cout << "====================Withdraw_Chacking_Account====================" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.withdraw(amount)) std::cout << "Withdrawed " << amount + acc.get_fee() << " from " << acc << std::endl;
        else std::cout << "Failed withdraw " << amount << " from " << acc << std::endl;
    }
}

//Utils of Trust_Account
void display(const std::vector<Trust_Account> &accounts)
{
    std::cout << "====================Trust_Account====================" << std::endl;
    for (const auto &acc: accounts)
    {
        std::cout << acc << std::endl;
    }
}

void deposit(std::vector<Trust_Account> &accounts, double amount)
{
    std::cout << "====================Deposit_Trust_Account====================" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.deposit(amount)) std::cout << "Deposit " << amount << " to acc: " << acc << std::endl;
        else std::cout << "Failed deposit " << amount << " to acc: " << acc << std::endl;
    }
}

void withdraw(std::vector<Trust_Account> &accounts, double amount)
{
    std::cout << "====================Withdraw_Trust_Account====================" << std::endl;
    for (auto &acc: accounts)
    {
        if (acc.withdraw(amount)) std::cout << "Withdrawed " << amount << " from acc: " << acc << std::endl;
        else std::cout << "Failed withdraw " << amount << " from acc: " << acc << std::endl;
    }
}