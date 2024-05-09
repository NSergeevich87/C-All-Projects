/** Кратность числа
Что нужно сделать:
Напишите программу, которая проверяет, делится ли одно число на другое без остатка.*/

#include <iostream>

using namespace std;

class task_9
{
    public:
        void run()
        {
            cout << "Enter two numbers: ";
            int a, b;
            cin >> a >> b;
            if (a % b == 0)
            {
                cout << "YES, Number " << a << " is a multiple of number " << b << endl;
            }
            else
            {
                cout << "NO, Number " << a << " is NOT a multiple of number " << b << endl;
            }
            cin.ignore(32767, '\n');
        }
};