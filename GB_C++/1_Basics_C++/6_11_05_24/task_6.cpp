/** Сумма чисел.

У бухгалтера сломались счеты. Напишите программу, которая считала бы сумму вводимых чисел. 
В начале у бухгалтера спрашивают, сколько чисел тот хочет сложить, 
затем нужное количество раз просят ввести число и в конце выводят получившуюся сумму.*/

#include <iostream>

using namespace std;

class task_6
{
    public:
        void run()
        {
            int n;
            cout << "Enter number of numbers: ";
            cin >> n;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                int a;
                cout << "Enter number: ";
                cin >> a;
                sum += a;
            }
            cout << "Sum of numbers: " << sum << endl;

            cin.ignore(32767, '\n');
        }
};