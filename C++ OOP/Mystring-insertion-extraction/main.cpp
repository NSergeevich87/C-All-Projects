#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring text1{"Nikita"};
    Mystring text2;
    text1.display();
    cout << "Enter text2: ";
    cin >> text2;
    text2.display();
    cout << text1 << " " << text2 << endl;
    
    
    cout << endl;
    return 0;
}