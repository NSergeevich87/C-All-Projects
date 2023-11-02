#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

int main()
{
    cout << "size of short: " << sizeof(short) << " bytes" << endl;
    cout << "size of int: " << sizeof(int) << " bytes" << endl;
    cout << "size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "size of long: " << sizeof(long) << " bytes" << endl;
    cout << "size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "size of long double: " << sizeof(long double) << " bytes" << endl;
    
    cout << "Minimum values" << endl;
    cout << "short: " << SHRT_MIN << endl;
    cout << "int: " << INT_MIN << endl;
    cout << "long: " << LONG_MIN << endl;
    cout << "long long: " << LLONG_MIN << endl;
    cout << "float: " << FLT_MIN << endl;
    cout << "long double: " << LDBL_MIN << endl;
    
    cout << "Maximum values" << endl;
    cout << "short: " << SHRT_MAX << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "long: " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MAX << endl;
    cout << "float: " << FLT_MAX << endl;
    cout << "long double: " << LDBL_MAX << endl;
    
    long double very_large_number {3'435'468'978'678'439'549};
    cout << "very_large_number's weight is: " << sizeof(very_large_number) << " bytes" << endl;
    cout << very_large_number << endl;
    
    long double pi {4};
    cout << pi << endl;
    
    return 0;
}