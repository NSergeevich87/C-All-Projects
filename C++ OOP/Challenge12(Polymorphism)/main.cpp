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
    
    cout << "==================================================" << endl;
    
    Account *s1 = new Savings_Account("Nick");
    Account *s2 = new Savings_Account("Nick", 3000);
    Account *s3 = new Savings_Account("Nick", 5000, 5);
    Account *c1 = new Checking_Account("Ksy", 4000);
    Account *t1 = new Trust_Account("Daniil", 1000, 2.5);
    
    vector<Account *> accounts;
    accounts.push_back(s1);
    accounts.push_back(s2);
    accounts.push_back(s3);
    accounts.push_back(c1);
    accounts.push_back(t1);
    
    cout << "==================================================" << endl;
    
    //Account_Util::display(accounts);
    
    cout << "==================================================" << endl;
    
    
    
    cout << endl;
    return 0;
}