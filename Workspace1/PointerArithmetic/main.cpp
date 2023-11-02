//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        int array[] { 10, 8, 6, 4, 2, 0, -1 };
        int *ptr_arr { array };
        
        while ( *ptr_arr != -1 )
        {
            cout << *ptr_arr << endl;
            ptr_arr++;
        }
        
        //ptr_arr = array;
        while ( *ptr_arr != 10 )
            cout << *ptr_arr-- << endl;
            
        cout << "\n-------------------------------------" << endl;
        
        string s1 { "Nikita" };
        string s2 { "Kseniia" };
        string s3 { "Nikita" };
        
        string *p1 { &s1 };
        string *p2 { &s2 };
        string *p3 { &s1 };
        
        cout << boolalpha;
        
        cout << p1 << " == " << p2 << ": " << (p1 == p2) << endl;
        cout << p1 << " == " << p3 << ": " << (p1 == p3) << endl;
        
        cout << s1 << " == " << s2 << ": " << (s1 == s2) << endl;
        cout << *p1 << " == " << *p2 << ": " << (*p1 == *p2) << endl;
        
        char name[] { "Nikita" };
        char *p_name1 { nullptr };
        char *p_name2 { nullptr };
        p_name1 = &name[0];
        p_name2 = &name[4];
        
        cout << "Letra " << *p_name1 << " away from letra " << *p_name2 << " for " << ( p_name1 - p_name2 ) << " numbers " << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}