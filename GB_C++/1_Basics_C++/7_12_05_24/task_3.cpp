/** Таблица умножения.
Первоклассник Вася родился в век высоких технологий и не умеет умножать в уме. 
Он боится контрольной работы на знание таблицы умножения, 
поэтому он решил написать на С++ программу-шпаргалку. 
Вася хочет ввести число, а программа должна выдать таблицу умножения для этого числа. 
Помогите Васе написать программу.*/

#include <iostream>
#include <string>

using namespace std;

class task_3
{
    public:
        void multiplication_table()
        {
            cout << "Enter number: ";
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

            for (int i = 1; i <= 10; i++)
            {
                cout << num << " * " << i << " = " << num * i << endl;
            }
        }
};