#include <iostream>

class Account
{
  friend std::ostream &operator<<(std::ostream &os, const Account &obj);

  public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {}
};

std::ostream &operator<<(std::ostream &os, const Account &obj)
{
  os << "Account display";
  return os;  
}

class Savings : public Account
{
  friend std::ostream &operator<<(std::ostream &os, const Savings &obj);  
  
  public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {}
};

std::ostream &operator<<(std::ostream &os, const Savings &obj)
{
    os << "Savings display";
    return os;
}

class Checking : public Account
{
  friend std::ostream &operator<<(std::ostream &os, const Checking &obj);
  
  public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {}
};

std::ostream &operator<<(std::ostream &os, const Checking &obj)
{
    os << "Checking display";
    return os;
}

class Trust : public Account
{
  friend std::ostream &operator<<(std::ostream &os, const Trust &obj);
  
  public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {}
};

std::ostream &operator<<(std::ostream &os, const Trust &obj)
{
    os << "Trust display";
    return os;
}

int main()
{
    /*Account a;
    Checking c;
    Savings s;
    Trust t;
    
    std::cout << a << std::endl;
    std::cout << c << std::endl;
    std::cout << s << std::endl;
    std::cout << t << std::endl;*/
    
    Account *a1 = new Account();
    Account *a2 = new Checking();
    std::cout << *a1 << std::endl;
    std::cout << *a2 << std::endl;
    
    std::cout << std::endl;
    return 0;
}