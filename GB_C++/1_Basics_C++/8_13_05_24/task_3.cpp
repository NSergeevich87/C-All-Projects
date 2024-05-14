/** Постоянный покупатель
Иногда к Араику Вачагановичу приходят постоянные покупатели, для которых он делает скидку. 
Для каждого такого клиента скидка своя. Модифицируйте программу из задачи «Орехи»: 
Араик будет вводить цену товара за 100 грамм, вес покупки и размер скидки в процентах, 
а программа должна выводить итоговую стоимость.*/

#include <iostream>
#include <string>

using namespace std;

class task_3
{
    public:
        void run()
        {
            cout << "Enter price for 100 grams: ";
            string price;
            getline(cin, price);
            float price_100 = stoi(price);

            cout << "Enter weight of product in grams: ";
            string weight;
            getline(cin, weight);
            float weight_product = stoi(weight);

            cout << "Enter discount %: ";
            string discount;
            getline(cin, discount);
            float discount_product = stoi(discount);
            if (discount_product > 100 || discount_product < 0)
            {
                cout << "Discount can't be more than 100'%' and less than 0%" << endl;
                return;
            }
            float discount_price = (100 - discount_product) / 100;
            cout << "Total price: " << (price_100 * weight_product / 100) * discount_price << endl;
        }
};