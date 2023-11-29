#include <iostream>

using namespace std;

class Base
{
    private:
        int val{};
    
    public:
        Base() : val{0}
        {
            cout << "Base constructor was called" << endl;
        }
        
        Base(int new_val) : val{new_val}
        {
            cout << "Base overload constructor was called" << endl;
        }
        
        ~Base()
        {
            cout << "Base destructor was called" << endl;
        }
};

class Derived : public Base
{
    using Base::Base;
    
    private:
        int val{};
        
    public:
        Derived() : val{0}
        {
            cout << "Derived constructor was called" << endl;
        }
        
        Derived(int new_val) : val{new_val * 2}
        {
            cout << "Derived overload constructor was called" << endl;
        }
        
        ~Derived()
        {
            cout << "Derived destructor was called" << endl;
        }
};

int main()
{
    //Base base1;
    //Base base2{1000};
    
    //Derived der1;
    Derived der2{1000};
    
    cout << endl;
    return 0;
}