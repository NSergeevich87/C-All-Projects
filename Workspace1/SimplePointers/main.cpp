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
        
        /*int num { 10 };
        cout << num << endl;
        cout << sizeof num << endl;
        cout << &num << endl;
        
        int *p;
        cout << p << endl;
        cout << sizeof p << endl;
        cout << &p << endl;
        
        int *n { nullptr };
        cout << n << endl;
        cout << sizeof n << endl;
        cout << &n << endl;*/
        
        /*int *a { nullptr };
        float *b { nullptr };
        double *c { nullptr };
        unsigned long long *d { nullptr };
        string *e { nullptr };
        vector<string> *f { nullptr };
        
        cout << "\nSizeof a is: " << sizeof a << endl;
        cout << "Sizeof b is: " << sizeof b << endl;
        cout << "Sizeof c is: " << sizeof c << endl;
        cout << "Sizeof d is: " << sizeof d << endl;
        cout << "Sizeof e is: " << sizeof e << endl;
        cout << "Sizeof f is: " << sizeof f << endl;*/
        
        int num { 10 };
        //double num2 { 10.10 };
        int *p { nullptr };
        
        p = &num;
        
        cout << "Num: " << num << endl;
        cout << "Num address: " << &num << endl;
        cout << "Pointer p address: " << p << endl;
        
        //p = &num2;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}