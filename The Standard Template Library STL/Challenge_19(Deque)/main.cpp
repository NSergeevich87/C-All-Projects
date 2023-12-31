#include <iostream>
#include <deque>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool is_polindrom(const string &value)
{
    deque<char> d{};
    char c1{};
    char c2{};
    
    cout << "You entered: " << value << endl;
    
    for(auto &i : value)
    {
        if(ispunct(i) || i == ' ') continue;
        else d.push_back(toupper(i));
    }
    
    cout << "String for compare: ";
    for(auto i: d)
    {
        cout << i;
    }
    cout << endl;
    
    while(d.size() > 1)
    {
        c1 = d.front();
        c2 = d.back();
        if(c1 == c2)
        {
            d.pop_front();
            d.pop_back();
        }
        else return false;
    }
    
    return true;
}

int main()
{
    cout << boolalpha;
    string text {};
    bool answer{};
    
    do
    {
        cout << "Enter something: ";
        getline(cin, text);
        answer = is_polindrom(text);
        cout << "This is a polindrom: " << answer << endl;
        cout << "Do you want repeat? y/n" << endl;
        getline(cin, text);
        
    } while (text[0] != 'n');
    
    cout << "Goodbay" << endl;
    
    return 0;
}