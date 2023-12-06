#include <iostream>

class I_Print
{
  friend std::ostream &operator<<(std::ostream &os, const I_Print &obj);
  
  public:
    virtual void Print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const I_Print &obj)
{
    obj.Print(os);
    return os;
}

class Account : public I_Print
{
  public:
      
    virtual void Print(std::ostream &os) const override
    {
        os << "Account print";
    }
      
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {}
};

class Savings : public Account
{
  public:
      
    virtual void Print(std::ostream &os) const override
    {
        os << "Savings print";
    }  
      
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {}
};

class Checking : public Account
{
  public:
      
    virtual void Print(std::ostream &os) const override
    {
        os << "Checking print";
    }  
      
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {}
};

class Trust : public Account
{
  public:
      
    virtual void Print(std::ostream &os) const override
    {
        os << "Trust print";
    }  
      
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {}
};

class Dog : public I_Print
{
    public:
        virtual void Print(std::ostream &os) const override
        {
            os << "Woof woof";
        }
        virtual ~Dog() {}
};

void Print(const I_Print &obj)
{
    std::cout << obj << std::endl;
}  

int main()
{
    Dog *d = new Dog();
    std::cout << *d << std::endl;
    Print(*d);
    
    Account *a1 = new Account();
    Account *a2 = new Checking();
    std::cout << *a1 << std::endl;
    std::cout << *a2 << std::endl;
    
    std::cout << std::endl;
    return 0;
}