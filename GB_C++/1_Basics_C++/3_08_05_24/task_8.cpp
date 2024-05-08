#include <iostream>
#include <string>
#include <limits>

using namespace std;

class task_8
{
    public:
        void run()
        {
            int a = 5;
            int b = 10;
            cout << "Before swap: a = " << a << ", b = " << b << endl;
            
            swap(a, b);

            cout << "After swap: a = " << a << ", b = " << b << endl;
        }
};