/** Складываем в уме
Что нужно сделать:
Напишите программу которая проверяет то, как вы умеете складывать два числа в уме. 
Программа должна выводить два разных сообщения на верный и неверный ответ пользователя. 
В последнем случае надо показывать правильный результат.*/

#include <iostream>

using namespace std;

class task_6
{
    public:
        void run()
        {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            int sum = a + b;
            cout << "Enter the sum of numbers: ";
            int userSum;
            cin >> userSum;
            if (userSum == sum)
            {
                cout << "Correct answer.\n";
            }
            else
            {
                cout << "Incorrect answer. Correct answer: " << sum << endl;
            }

            cin.ignore(32767, '\n');
        }
};