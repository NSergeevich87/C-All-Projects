#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    cout << boolalpha << endl;
    
    Mystring text1 {"Nikita"};
    Mystring text2;
    text2 = Mystring {"Kseniia"};
    text2 = "No Name";
    
    cout << (text1 == text2) << endl;
    text1 = text2;
    cout << (text1 == text2) << endl;
    text2 = -text2;
    text2.display();
    Mystring text3 = text1 + text2;
    text3.display();
    
    cout << endl;
    return 0;
}