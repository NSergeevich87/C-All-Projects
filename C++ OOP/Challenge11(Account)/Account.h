#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include <iostream>

class Account
{
friend std::ostream &operator<<(std::ostream &os, const Account &account);

private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    
protected:
    std::string name;
    double balance;
    
public:
    Account(std::string val_name = def_name, double val_bal = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

#endif // _ACCOUNT_H_
