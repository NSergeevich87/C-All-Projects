#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Chacking_Account.h"

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
    
    //Chacking_Account
    
    vector<Chacking_Account> Third_Accounts;
    Third_Accounts.push_back(Chacking_Account {});
    Third_Accounts.push_back(Chacking_Account {"Ksy", 1000});
    Third_Accounts.push_back(Chacking_Account {"Nick", 2000, 3});
    
    display(Third_Accounts);
    deposit(Third_Accounts, 1000);
    withdraw(Third_Accounts, 800);
    
    //Trust_Account
    
    vector<Trust_Account> Fourth_Accounts;
    Fourth_Accounts.push_back(Trust_Account {});
    Fourth_Accounts.push_back(Trust_Account {"Nick", 2000, 5});
    Fourth_Accounts.push_back(Trust_Account {"Ksy", 4000, 15});
    
    display(Fourth_Accounts);
    deposit(Fourth_Accounts, 5000);
    deposit(Fourth_Accounts, 5000);
    withdraw(Fourth_Accounts, 2880);
    withdraw(Fourth_Accounts, 1000);
    withdraw(Fourth_Accounts, 1000);
    withdraw(Fourth_Accounts, 1000);
    withdraw(Fourth_Accounts, 1000);
    
    cout << endl;
    return 0;
}