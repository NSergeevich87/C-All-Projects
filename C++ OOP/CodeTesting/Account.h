#pragma once

class Account
{
private:
    string name {};
    double balance {};

public:
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }
    
    void set_name(string name) { name = name; }
};

