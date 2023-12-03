#include <iostream>
#include <memory>

using namespace std;

class Base
{
public:
    void display() const
    {
        cout << "Base class!" << endl;
    }
};

class Derived : public Base
{
public:
    void display() const
    {
        cout << "Derived class!" << endl;
    }
};

void display_class(const Base &obj)
{
    cout << "Display_class: ";
    obj.display();
}

int main()
{
    Base b;          
    b.display();                //"Base class!"
    
    Derived d;
    d.display();                //"Derived class!"
    
    display_class(b);           //"Base class!"
    display_class(d);           //"Base class!"
    
    Base *ptr = new Derived();
    ptr->display();             //"Base class!"
    display_class(*ptr);        //"Base class!"
    
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();        //Smart pointer
    ptr1->display();            //"Base class!"
    
    delete ptr;
    
    cout << endl;
    return 0;
}