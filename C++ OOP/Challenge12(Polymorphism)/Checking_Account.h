#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account : public Account
{
private:
    static constexpr const char *def_name = "No_name";
    static constexpr double def_balance = 0.0;
    static constexpr double def_fee = 1.5;
    
public:
    Checking_Account(std::string name_val, double bal_val);
    
    virtual void print(std::ostream &os) const override;
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    
    virtual ~Checking_Account() = default;
};

#endif // _CHECKING_ACCOUNT_H_
