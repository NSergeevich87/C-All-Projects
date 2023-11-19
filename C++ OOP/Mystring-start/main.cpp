#include "Mystring.h"
#include <iostream>

using namespace std;

int main()
{
    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge {larry};
    
    empty.display();
    larry.display();
    stooge.display();
    
    cout << endl;
    return 0;
}