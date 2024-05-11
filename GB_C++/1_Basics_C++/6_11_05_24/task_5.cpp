/** Банкомат 3.0.

В банке ПлюсПлюсБанк тестируют новую систему пин-кодов на банкоматы. 
Теперь вместо фиксированного пин-кода пользователь должен ввести 4 числа. 
Если их сумма оказывается равна 42, пользователь может продолжать работу. 
Напишите программу, которая спрашивает у пользователя 4 числа и отвечает “Ввод корректный”, 
если их сумма равна 42, и “Ввод некорректный, попробуйте еще раз” в противном случае. 
Так повторяется бесконечно.*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class task_5
{
    public:
        void run()
        {
            
            while (true)
            {
                int a, b, c, d;
                cout << "Enter 4 numbers: ";
                cout << "Sum of numbers should be 42\n";
                cin >> a >> b >> c >> d;
                if (a + b + c + d == 42)
                {
                    cout << "Correct input\n";
                    break;
                }
                else
                {
                    cout << "Incorrect input, try again\n";
                }
            }

            cin.ignore(32767, '\n');
        }
};