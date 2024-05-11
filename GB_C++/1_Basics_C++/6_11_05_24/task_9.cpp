/** Кожаный мешок.

На этот раз нужно написать фрагмент кода для прошивки робота. 
Как мы знаем, роботы понимают только нули и единицы, других цифр для них не существует. 
Напишите программу, которая проверяет, состоит ли число только из нулей и единиц.*/

#include <iostream>
#include <string>

using namespace std;

class task_9
{
    public:
        void run()
        {
            string str;
            cout << "Enter a number: ";
            getline(cin, str);
            bool is_binary = true;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] != '0' && str[i] != '1')
                {
                    is_binary = false;
                    break;
                }
            }
            if (is_binary)
            {
                cout << "The number consists only of zeros and ones.\n";
            }
            else
            {
                cout << "The number does not consist only of zeros and ones.\n";
            }
        }
};