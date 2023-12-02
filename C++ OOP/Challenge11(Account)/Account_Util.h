#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include "Account.h"
#include "Savings_Account.h"
#include "Chacking_Account.h"
#include "Trust_Account.h"
#include <vector>
#include <iostream>

//Utilites for Account class
void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);

//Utilites for Savings_Account class
void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &accounts, double amount);
void withdraw(std::vector<Savings_Account> &accounts, double amount);

//Utilites for Chacking_Account class
void display(const std::vector<Chacking_Account> &accounts);
void deposit(std::vector<Chacking_Account> &accounts, double amount);
void withdraw(std::vector<Chacking_Account> &accounts, double amount);

//Utilites for Trust_Account class
void display(const std::vector<Trust_Account> &accounts);
void deposit(std::vector<Trust_Account> &accounts, double amount);
void withdraw(std::vector<Trust_Account> &accounts, double amount);

#endif // _ACCOUNT_UTIL_H_
