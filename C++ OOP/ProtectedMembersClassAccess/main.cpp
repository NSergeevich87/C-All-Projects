#include <iostream>

using namespace std;

class Base
{
    public:
        int a{};
        void display() { cout << "a : " << a << " b : " << b << " c : " << c << endl; }
    protected:
        int b{};
 
    private:
        int c{};
    
};

class Derived : public Base
{
  public:
    void acces_numbers()
    {
        a = 100;
        b = 200;
        //c = 300;
    }
};

int main()
{
    Base base1;
    base1.a = 100;
    //base1.b = 100;
    //base1.c = 100;
    base1.display();
	
    Derived der1;
    der1.a = 100;
    //der1.b = 100;
    //der1.c = 100;
    der1.acces_numbers();
    der1.display();
    
	cout << endl;
	return 0;
}		