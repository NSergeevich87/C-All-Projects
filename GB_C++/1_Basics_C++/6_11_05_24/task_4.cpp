/** Напоминалка.

Василий — очень ответственный менеджер, но очень забывчивый. 
Иногда он пьет воду несколько раз подряд, потому что забыл, что только что пил. 
Напишите для него программу-напоминалку. В самом начале программа спрашивает, сколько раз ему напомнить, 
а затем нужное количество раз выводит “Вы хотели не забыть о чем-то”.

Усложнение: добавьте возможность ввести фразу-напоминалку, чтобы можно было напоминать о чем-то конкретном.*/

#include <iostream>
#include <string>

using namespace std;

class task_4
{
    public:
        void run()
        {
            int N;
            cout << "How many times do you want to be reminded? ";
            cin >> N;
            cin.ignore(32767, '\n');

            string reminder;
            cout << "What do you want to be reminded of? ";
            getline(cin, reminder);

            for (int i = 0; i < N; i++)
            {
                cout << "You wanted to remember something: " << reminder << endl;
            }
        }
};