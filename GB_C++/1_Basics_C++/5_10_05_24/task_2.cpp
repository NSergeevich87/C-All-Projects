/** Банкомат.
Пользователи банкомата хотят снимать деньги. Но банкомат умеет выдавать только купюры по 100 рублей, 
а максимальная сумма снятия — 100 000 рублей.
Напишите программу, которая проверяет допустимость суммы средств, введенной пользователем.*/

#include <iostream>

using namespace std;

class task_2
{
    public:
        void run()
        {
            int sum;
            cout << "Enter the amount of money: ";
            cin >> sum;
            
            if (sum % 100 == 0 && sum <= 100000 && sum > 0)
            {
                cout << "The amount is valid" << endl;
            }
            else
            {
                cout << "The amount is not valid" << endl;
            }

            cin.ignore(32767, '\n');
        }
};