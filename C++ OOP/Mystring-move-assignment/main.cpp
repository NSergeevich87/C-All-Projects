#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring a{"Madrid"};
    a = Mystring{"Barcelona"};
    a = "Moscú";
    
    cout << endl;
    return 0;
}