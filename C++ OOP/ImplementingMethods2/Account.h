#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account
{
private:
    std::string name {};
    float balance {};

public:
    void set_balance(float bal) { balance = bal; }
    float get_balance() { return balance; }
    
    void set_name(std::string n);
    std::string get_name();
    
    bool deposit(float val);
    bool withdraw(float val);
};

#endif // _ACCOUNT_H_
