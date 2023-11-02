//#include <climits>
//#include <cfloat>
#include <iostream>
#include <cstring>
#include <cctype>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        //char first_name[20] {};
        //char second_name[20] {};
        char full_name[50] {};
        char temp[50] {};
        /*cout << "Please enter your first name: ";
        cin >> first_name;
        cout << "Please enter your second name: ";
        cin >> second_name;
        cout << "\n=========================" << endl;
        cout << "Your first name has " << strlen(first_name) << " simbols" << endl;
        cout << "Your second name has " << strlen(second_name) << " simbols" << endl;
        strcpy(full_name, first_name);
        strcat(full_name, " ");
        strcat(full_name, second_name);
        cout << "Your full_name is: " << full_name << endl;
        cout << "And has " << strlen(full_name) << " simbols" << endl;*/
        cout << "Please enter your full name: ";
        cin.getline(full_name, 50);
        cout << full_name << endl;
        strcpy(temp, full_name);
        cout << "Temp: " << temp << endl;
        if(strcmp(temp, full_name) == 0)
        {
            cout << full_name << " and " << temp << " are the same" << endl;
        }
        else
        {
            cout << full_name << " and " << temp << " are different" << endl;
        }
        for (size_t i {0}; i < strlen(full_name); ++i)
        {
            if (isalpha(full_name[i]))
            {
                full_name[i] = toupper(full_name[i]);
            }
        }
        cout << full_name << endl;
        if (strcmp(temp, full_name) == 0)
        {
            cout << "Temp and full_name are the same" << endl;
        }
        else
        {
            cout << temp << " and " << full_name << " are different" << endl;
        }
        cout << "Compare Temp whith full_name: " << strcmp(temp, full_name) << endl;
        cout << "Compare full_name whith Temp: " << strcmp(full_name, temp) << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}