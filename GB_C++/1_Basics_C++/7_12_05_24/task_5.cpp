/** Начальник (цикл for).
Перепишите программу из прошлого модуля, используя цикл for. Напишите программу для робота-начальника. 
Он спрашивает у пользователя, выполнил ли он задание, которое тот выдавал вчера, 
и продолжает это делать до тех пор, пока пользователь не ответит ему “Да, конечно, сделал”. 
Для большей реалистичности в конце пусть робот-начальник пожалуется: 
“Ну почему тебя нужно спрашивать N раз?”, где N — это число попыток, которые были потрачены пользователем, 
прежде чем он ввёл правильный ответ.*/

#include <iostream>
#include <string>

using namespace std;

class task_5
{
    public:
        void chief()
        {
            int count = 0;
            for (int i = 0; i < 100; i++)
            {
                cout << "Did you do the task? ";
                cout << "You need to answer 'Yes, of course, I did'\n";
                string answer;
                getline(cin, answer);

                if (answer == "Yes, of course, I did")
                {
                    cout << "Why do I have to ask you " << count + 1 << " times?" << endl;
                    break;
                }
                else
                {
                    count++;
                }
            }
        }
};