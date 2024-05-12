/** Сумма чисел (цикл for).
Перепишите программу из прошлого модуля, используя цикл for. 
У бухгалтера сломались счеты. Напишите программу, которая считала бы сумму вводимых чисел. 
В начале у бухгалтера спрашивают, сколько чисел тот хочет сложить, 
затем нужное количество раз просят ввести число и в конце выводят получившуюся сумму.*/

#include <iostream>

using namespace std;

class task_2
{
    public:
        void sum()
        {
            int numbers;
            cout << "Enter the number of numbers: ";
            cin >> numbers;
            cin.ignore(32767, '\n');

            int sum = 0;
            for (int i = 0; i < numbers; i++)
            {
                int number;
                cout << "Enter number " << i + 1 << ": ";
                cin >> number;
                cin.ignore(32767, '\n');
                sum += number;
            }

            cout << "Sum of numbers: " << sum << endl;
        }
};