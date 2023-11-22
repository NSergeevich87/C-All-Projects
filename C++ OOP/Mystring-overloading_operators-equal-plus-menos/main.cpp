#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    cout << boolalpha << endl;
    
    Mystring text1 {"NIKITA"};
    Mystring text1_2 {"nikita"};
    text1.display();
    text1 = -text1;
    text1.display();
    
    Mystring text2 {" + kseniia"};
    text2.display();
    
    cout << (text1 == text2) << endl;
    
    Mystring text3 = {text1 + text2};
    text3.display();
    
    cout << (text1 == text1_2) << endl;
    
    cout << endl;
    return 0;
}