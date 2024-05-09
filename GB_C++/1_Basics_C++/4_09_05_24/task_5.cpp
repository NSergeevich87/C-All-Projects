/** Минимум из двух чисел
Что нужно сделать:
Напишите программу, которая ищет минимальное значение из двух чисел.*/

#include <iostream>

using namespace std;

class task_5
{
    public:
        void run()
        {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if (a < b)
            {
                cout << "Minimum number: " << a << endl;
            }
            else if (a == b)
            {
                cout << "Numbers are equal.\n";
            }
            else
            {
                cout << "Minimum number: " << b << endl;
            }

            cin.ignore(32767, '\n');
        }
};