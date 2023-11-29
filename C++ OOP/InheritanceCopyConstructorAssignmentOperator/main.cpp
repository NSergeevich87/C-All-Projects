#include <iostream>

using namespace std;

class Base
{
	private:
        int value;
        
    public:
        Base() : value{0}
        {
            cout << "Base no-args constructor" << endl;
        }
        
        Base(int val) : value{val}
        {
            cout << "Base overload constructor" << endl;
        }
        
        Base(const Base &other) : value{other.value}
        {
            cout << "Copy constructor" << endl;
        }
        
        Base &operator=(const Base &rhs)
        {
            cout << "Base operator=" << endl;
            
            if (this == &rhs)
            {
                return *this;
            }
            
            value = rhs.value;
            return *this;
        }
        
        ~Base() 
        {
            cout << "Base destructor" << endl;
        }
};

class Derived : public Base
{
    private:
        int doubled_value;
        
    public:
        Derived() : Base{}
        {
            cout << "Derived no-args constructor" << endl;
        }
        
        Derived(int val) : Base{val}, doubled_value{val * 2}
        {
            cout << "Derived overload constructor" << endl;
        }
        
        Derived(const Derived &other) : Base(other), doubled_value{other.doubled_value}
        {
            cout << "Derived copy constructor" << endl;
        }
        
        Derived &operator=(const Derived &rhs)
        {
            cout << "Derived operator=" << endl;
            
            if (this == &rhs) return *this;
            
            Base::operator=(rhs);
            doubled_value = rhs.doubled_value;
            return *this;
        }
        
        ~Derived()
        {
            cout << "Derived destructor" << endl;
        }
};

int main()
{
	Base b {100};
    Base b1 {b};
    b = b1;
    
    Derived d {100};
    Derived d1 {d};
    d = d1;
	
	cout << endl;
	return 0;
}		