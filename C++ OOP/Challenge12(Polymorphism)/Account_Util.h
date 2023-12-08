#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include "Account.h"
#include <vector>

class Account_Util
{
    void display(const std::vector<Account *> &accounts);
    void deposit(std::vector<Account *> &accounts, double amount);
    void withdraw(std::vector<Account *> &accounts, double amount);
};

#endif // _ACCOUNT_UTIL_H_
