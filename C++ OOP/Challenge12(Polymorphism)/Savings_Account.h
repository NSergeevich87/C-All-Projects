#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"
#include <iostream>
#include <string>

class Savings_Account : public Account
{
private:
    static constexpr const char *def_name = "No_name";
    static constexpr double def_balance = 0.0;
    static constexpr double def_rate = 0.0;
    
protected:
    double int_rate;
    
public:
    Savings_Account(std::string name_val = def_name, double bal_val = def_balance, double rate_val = def_rate);
    
    virtual void print(std::ostream &os) const override;
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    
    virtual ~Savings_Account() = default;

};

#endif // _SAVINGS_ACCOUNT_H_
