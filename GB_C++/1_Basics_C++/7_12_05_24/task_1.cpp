/** Кукушка (цикл for).
Перепишите программу из прошлого модуля, используя цикл for. 
Напишите программу, которая имитировала бы часы с кукушкой. 
В начале работы она спрашивает, который час, а затем нужное количество раз пишет “Ку-ку!”. 
Обеспечьте контроль ввода (например, количество часов не может быть отрицательным).*/

#include <iostream>
#include <string>

using namespace std;

class task_1
{
    public:
        void cuckoo()
        {
            int hours;
            cout << "Enter the number of hours (1-12): ";
            cin >> hours;
            cin.ignore(32767, '\n');

            if (hours < 1 || hours > 12)
            {
                cout << "The number of hours can be between 1 and 12!" << endl;
                return;
            }

            for (int i = 0; i < hours; i++)
            {
                cout << i + 1 << " Cuckoo!" << endl;
            }
        }
};