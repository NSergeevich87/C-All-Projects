/** Купи слона.

Напишите программу-дразнилку “Купи слона”. Она спрашивает у пользователя, как его зовут, 
затем отвечает “%username%, купи слона!”. Дальше, что бы он ни говорил, она передразнивает: 
Все говорят “...”, а ты купи слона!
Так повторяется бесконечно.

Пример

- Хорошо, давай куплю.
- Все говорят “Хорошо, давай куплю.”, а ты купи слона!*/

#include <iostream>
#include <string>

using namespace std;

class task_2
{
    public:
        void run()
        {
            string name;
            cout << "What is your name? ";
            getline(cin, name);
            cout << name << ", buy an elephant!" << endl;

            string answer;
            do
            {
                cout << "Say something: ";
                getline(cin, answer);
                cout << "Everyone says \"" << answer << "\", and you buy an elephant!" << endl;
            } while (true);
        }
};