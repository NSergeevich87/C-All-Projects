#ifndef _MAIN_ACCOUNT_H_
#define _MAIN_ACCOUNT_H_

#include "Account.h"
#include <iostream>
#include <string>

class Main_Account : public Account
{
private:
    static constexpr const char *def_name = "No_name";
    static constexpr double def_balance = 0.0;
    
protected:
    std::string name;
    double balance;
    
public:
    Main_Account(std::string name_val = def_name, double balance = def_balance);
    virtual bool withdraw(double amount) override final;
    virtual void get_bal() override;
    virtual ~Main_Account() = default;
};

#endif // _MAIN_ACCOUNT_H_
