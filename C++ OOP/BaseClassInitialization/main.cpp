#include <iostream>

using namespace std;

class Base
{
	private:
        int x;
        
    public:
        Base() : x{0}
        {
            cout << "Base no-args" << endl;
        }
        
        Base(int val) : x{val}
        {
            cout << "Base overload" << endl;
        }
        
        ~Base()
        {
            cout << "Base destructor" << endl;
        }
};

class Derived : public Base
{
    private:
        int y;
        
    public:
        Derived() : Base{}, y{0}
        {
            cout << "Derived no-args" << endl;
        }
        
        Derived(int val) : Base{val}, y{val * 2}
        {
            cout << "Derived overload" << endl;
        }
        
        ~Derived()
        {
            cout << "Derived destructor" << endl;
        }
};

int main()
{
	//Derived d;
    Derived d{1000};
	
	cout << endl;
	return 0;
}		