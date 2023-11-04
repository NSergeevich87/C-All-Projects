#include <iostream>
#include <string>

using namespace std;

string reverse_string(const string &str)
{
    string reversed{};
    
    const char *start = &str[0];
    const char *stop = &str[str.size() - 1];
    while(stop >= start)
    {
        reversed.push_back(*stop);
        stop--;
    }
    
    return reversed;
}

int main()
{   
    string name {"Nikita"};
    name = reverse_string(name);
    cout << name << endl;
    
    cout << endl;
    return 0;
}