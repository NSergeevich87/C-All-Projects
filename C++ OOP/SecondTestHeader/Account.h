#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account
{
    private:
        std::string name;
        float balance;
    
    public:
        void set_name(std::string n) { name = n; }
        void set_balance(float num) { balance = num; }
        
        void deposit(float num);
        void withdraw(float num);
        
        Account();
        Account(std::string n);
        Account(std::string n, float num);
        ~Account();
        
};

#endif // _ACCOUNT_H_
