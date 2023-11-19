#include "Mystr.h"
#include <iostream>

using namespace std;

int main()
{
    Mystr empty;
    Mystr nick("Nikita");
    Mystr copy(nick);
    
    empty.display();
    nick.display();
    copy.display();
    
    cout << endl;
    return 0;
}