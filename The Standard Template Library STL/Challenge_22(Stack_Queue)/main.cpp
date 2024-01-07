#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

bool is_polindrom(const string &s)
{
    stack<char> st {};
    queue<char> qu {};
    
    for(auto &i: s)
    {
        if (!isalpha(i)) continue;
        else 
        {
            st.push(toupper(i));
            qu.push(toupper(i));
        }
    }
    
    while(!st.empty())
    {
        if(st.top() == qu.front())
        {
            st.pop();
            qu.pop();
        }
        else return false;
    }
    
    return true;
}

int main()
{
    cout << boolalpha;
    vector<string> text = { "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
    
    cout << "=====================================\n" << endl;
    
    for(auto item: text)
    {
        cout << setw(10) << left << is_polindrom(item) << " " 
             << setw(10) << right << item << endl;
    }
    
    return 0;
}