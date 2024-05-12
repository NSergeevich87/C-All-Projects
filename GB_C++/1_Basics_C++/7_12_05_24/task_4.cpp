/** Сумма нечётных.
Напишите программу, похожую на разобранный нами пример с суммой чисел, 
но только теперь нужно вычислить сумму всех нечётных чисел, 
лежащих в диапазоне от единицы до указанного пользователем числа включительно.*/

#include <iostream>
#include <string>

using namespace std;

class task_4
{
    public:
        void sum_odd()
        {
            cout << "Enter the number: ";
            string number;
            getline(cin, number);

            int num = 0;
            try
            {
                num = stoi(number);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Wrong number!" << '\n';
            }

            int sum = 0;
            for (int i = 1; i <= num; i++)
            {
                if (i % 2 != 0)
                {
                    cout << i << " + ";
                    sum += i;
                }
            }

            cout << "Sum of odd numbers: " << sum << endl;
        }
};