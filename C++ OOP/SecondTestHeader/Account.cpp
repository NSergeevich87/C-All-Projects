#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

void Account::deposit(float num)
{
    balance += num;
    cout << "Balance: " << balance << endl;
}

void Account::withdraw(float num)
{
    balance -= num;
    cout << "Balance: " << balance << endl;
}
        
Account::Account()
    : name{"NO_name"}, balance{0} {
        
    }
        
Account::Account(std::string n)
    : name{n}, balance{0} {
        
    }
        
Account::Account(std::string n, float num)
    : name{n}, balance{num} {
        
    }
    
Account::~Account() {
    cout << "Destructor was called for: " << name << endl;
}

