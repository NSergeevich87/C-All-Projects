/** Задача 3. Модуль числа.
Напишите программу, которая вычисляет модуль числа.
Подсказка: чтобы обратить знак числа в переменной ‘x’ надо писать вот так: x = - x.*/

#include <iostream>

using namespace std;

class task_3
{
    public:
        void run()
        {
            cout << "Enter number: ";
            int number;
            cin >> number;
            if (number < 0)
            {
                number = -number;
            }
            cout << "Module of number: " << number << endl;
            cin.ignore(32767, '\n');
        }
};