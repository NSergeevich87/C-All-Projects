/** Начальник.

Напишите программу для робота-начальника. Он спрашивает у пользователя, выполнил ли он задания, 
которые выдавал вчера, и продолжает это делать до тех пор, пока тот не ответит ему “Да, конечно, сделал”.

Подсказка 1: строки можно сравнивать вот так: (answer == “Да, конечно, сделал”), 
где answer — переменная с типом std::string
Подсказка 2: чтобы считать строку с пробелами, воспользуйтесь функцией std::getline(std::cin, line);"*/

#include <iostream>
#include <string>

using namespace std;

class task_1
{
    public:
        void run()
        {
            string answer;
            do
            {
                cout << "Did you do the tasks I gave you yesterday? ";
                cout << "Please answer 'Yes, of course, I did': ";
                getline(cin, answer);
            } while (answer != "Yes, of course, I did");

            cout << "Good job! Keep it up!" << endl;
        }
};