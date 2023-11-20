#include <iostream>
#include "NewString.h"

using namespace std;

int main()
{
    NewString a {"Hello"};
    NewString b;
    b = a;
    
    b = "Hello World";
    
    cout << endl;
    return 0;
}