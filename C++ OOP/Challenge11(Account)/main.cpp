#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;
    
    //Accounts
    
    vector<Account> First_Accounts;
    First_Accounts.push_back(Account {});
    First_Accounts.push_back(Account {"Petr"});
    First_Accounts.push_back(Account {"Nikita", 5000});
    //First_Accounts.push_back(Account {"Kseniia", 7000, 5.0});
    
    display(First_Accounts);
    deposit(First_Accounts, 1400);
    withdraw(First_Accounts, 1950);
    
    //Savings_Account
    
    vector<Savings_Account> Second_Accounts;
    Second_Accounts.push_back(Savings_Account {});
    Second_Accounts.push_back(Savings_Account {"Petr"});
    Second_Accounts.push_back(Savings_Account {"Nikita", 4650});
    Second_Accounts.push_back(Savings_Account {"Kseniia", 35654, 7.0});
    
    display(Second_Accounts);
    deposit(Second_Accounts, 3456);
    withdraw(Second_Accounts, 3500);
    
    cout << endl;
    return 0;
}