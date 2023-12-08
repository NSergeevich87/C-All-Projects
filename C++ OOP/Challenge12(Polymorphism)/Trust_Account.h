#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"
#include <iostream>
#include <string>

class Trust_Account : public Savings_Account
{
private:
    static constexpr const char *def_name = "No_name";
    static constexpr double def_balance = 0.0;
    static constexpr double def_rate = 0.0;
    static constexpr double def_bounus = 50.0;
    static constexpr double bonus_threshold = 5'000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
    
protected:
    int num_withdrawals;
    
public:
    Trust_Account(std::string name_val = def_name, double bal_val = def_balance, double int_rate = def_rate);
    
    virtual void print(std::ostream &os) const override;
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    
    virtual ~Trust_Account() = default;
};

#endif // _TRUST_ACCOUNT_H_
