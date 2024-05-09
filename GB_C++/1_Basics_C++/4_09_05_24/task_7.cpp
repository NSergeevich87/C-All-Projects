/** Проверка на чётное число
Что нужно сделать:
Напишите программу, которая проверяет, чётное ли число ввел пользователь.*/

#include <iostream>

using namespace std;

class task_7
{
    public:
        void run()
        {
            cout << "Enter number: ";
            int number;
            cin >> number;
            if (number % 2 == 0)
            {
                cout << "Number is even.\n";
            }
            else
            {
                cout << "Number is odd.\n";
            }
            cin.ignore(32767, '\n');
        }
};