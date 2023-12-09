#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;
    
    Account *ptr = new Trust_Account("Leo", 10000, 2.6);
    cout << *ptr << endl;
    
    
    Savings_Account noempty {"Kick", 8888, 10};
    cout << noempty << endl;
    
    cout << "==================================================" << endl;
    
    Account *s1 = new Savings_Account("Nick");
    Account *s2 = new Savings_Account("Nick", 3000);
    Account *s3 = new Savings_Account("Nick", 5000, 5);
    Account *c1 = new Checking_Account("Ksy", 4000);
    Account *t1 = new Trust_Account("Daniil", 4000, 2.5);
    
    vector<Account *> accounts;
    accounts.push_back(s1);
    accounts.push_back(s2);
    accounts.push_back(s3);
    accounts.push_back(c1);
    accounts.push_back(t1);
    
    cout << "==================================================" << endl;
    
    display(accounts);
    deposit(accounts, 5000);
    for(auto i = 0; i < 15; ++i)
        withdraw(accounts, 1000);
    
    cout << "==================================================" << endl;
    
    
    
    cout << endl;
    return 0;
}