/** Високосный год (необязательная). *
Напишите программу, которая определяет количество дней в году.*/

#include <iostream>

using namespace std;

class task_3
{
    public:
        void run()
        {
            int year;
            cout << "Enter the year: ";
            cin >> year;
            
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            {
                cout << "The year is leap" << endl;
            }
            else
            {
                cout << "The year is not leap" << endl;
            }

            cin.ignore(32767, '\n');
        }
};