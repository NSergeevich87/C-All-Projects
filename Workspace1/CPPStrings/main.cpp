//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);
#include <string>

using namespace std;

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        string s1 {"Nikiforov Nikita"};
        for (size_t i{0}; i < s1.length(); ++i)
        {
            cout << s1.at(i);
        }
        cout << endl;
        for (size_t i{0}; i < s1.length(); ++i)
        {
            cout << s1[i];
        }
        cout << endl;
        for (char c : s1)
        {
            cout << c;
        }
        cout << endl;
        cout << s1.substr(0, 9) << endl;
        cout << s1.substr(9, 1) << endl;
        cout << s1.substr(10, 6) << endl;
        string full_name {};
        cout << "Enter string where we'll find anything: ";
        getline(cin, full_name);
        cout << "String: " << full_name << endl;
        string word {};
        cout << "Enter word for find: ";
        cin >> word;
        size_t position = full_name.find(word);
        if (position != string::npos)
            cout << "Found " << word << " at position: " << position << endl;
        else 
            cout << "Sorry, " << word << " not found" << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}