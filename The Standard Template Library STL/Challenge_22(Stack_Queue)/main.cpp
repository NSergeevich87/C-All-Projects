#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

bool is_polindrom(string &s)
{
    return false;
}

int main()
{
    cout << boolalpha;
    vector<string> text = { "word1", "word2" };
    
    for(auto item: text)
    {
        cout << is_polindrom(item) << " " << item << endl;
    }
    
    return 0;
}