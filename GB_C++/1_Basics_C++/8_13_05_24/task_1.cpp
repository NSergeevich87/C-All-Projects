/** Орехи
Араик Вачаганович торгует на рынке орехами и сухофруктами. Товары продаются на развес, 
у каждого есть цена за 100 грамм. Араик пользуется механическими весами с гирями, поэтому каждый раз 
рассчитывает итоговую стоимость продажи на бумаге или в уме. Это неудобно: например, если покупатель 
хочет 265 грамм грецких орехов, а 100 грамм стоят 600 рублей, приходится умножать и делить в столбик. 
Напишите простую программу в помощь Араику: он вводит цену товара за 100 грамм и итоговый вес покупки, 
а программа выдаёт стоимость покупки указанного веса.*/

#include <iostream>
#include <string>

using namespace std;

class task_1
{
    public:
        void run()
        {
            cout << "Enter price for 100 grams: ";
            string price;
            getline(cin, price);
            int price_100 = stoi(price);

            cout << "Enter weight of purchase in grams: ";
            string weight;
            getline(cin, weight);
            int weight_purchase = stoi(weight);

            cout << "Total price: " << price_100 * weight_purchase / 100 << endl;
        }
};