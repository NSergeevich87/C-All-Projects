/** Задача 1. Калькулятор скидки.
Вы покупаете 3 товара в магазине. Если сумма вашего чека превышает 10 000 руб, вам будет сделана скидка 10%.
Напишите программу которая запрашивает 3 стоимости товара и вычисляет сумму чека.*/

#include <iostream>

using namespace std;

class task_1
{
    public:
        void run()
        {
            double sum = 0;
            for (int i = 0; i < 3; i++)
            {
                cout << "Enter price of product " << i + 1 << ": ";
                double price;
                cin >> price;
                sum += price;
            }
            if (sum > 10000)
            {
                cout << "Cost of products: " << sum << endl;
                cout << "You have a discount 10%\n";
                sum *= 0.9;
            }
            cout << "Total price: " << sum << endl;

            cin.ignore(32767, '\n');
        }
};