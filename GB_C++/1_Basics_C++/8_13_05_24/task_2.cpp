/** ЗОЖ
Лена решила следить за питанием и вести учёт потребляемых белков и углеводов. 
На этикетках продуктов указано содержание белков и углеводов на 100 грамм продукта, 
но обычно упаковка весит меньше или больше 100 грамм. Напишите программу, 
которая принимает на вход информацию с упаковки: количество белков и углеводов на 100 грамм 
и массу нетто продукта. На выходе программа сообщает Лене, сколько белков и углеводов содержится в упаковке 
с продуктом этого веса.*/

#include <iostream>
#include <string>

using namespace std;

class task_2
{
    public:
        void run()
        {
            cout << "Enter proteins for 100 grams: ";
            string proteins;
            getline(cin, proteins);
            int proteins_100 = stoi(proteins);

            cout << "Enter carbohydrates for 100 grams: ";
            string carbohydrates;
            getline(cin, carbohydrates);
            int carbohydrates_100 = stoi(carbohydrates);

            cout << "Enter net weight of product: ";
            string weight;
            getline(cin, weight);
            int weight_product = stoi(weight);

            cout << "Proteins in product: " << proteins_100 * weight_product / 100 << endl;
            cout << "Carbohydrates in product: " << carbohydrates_100 * weight_product / 100 << endl;
        }
};