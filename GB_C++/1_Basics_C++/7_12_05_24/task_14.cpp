/** Важные объявления
Что нужно сделать
Напишите программу для печати важных объявлений. 
Сверху объявления должен располагаться вот такой колонтитул:

Восклицательные знаки всегда располагаются по центру строки, 
причём в зависимости от важности объявления количество восклицательных знаков может быть разным. 
Напишите программу, которая спрашивает у пользователя сначала общую длину колонтитула в символах, 
потом желаемое количество восклицательных знаков, после чего выводит на экран готовую строку. 
Обеспечьте контроль ввода.
Пример выполнения

Рекомендации по выполнению
Если невозможно разместить восклицательные знаки ровно по центру, допускается сдвиг на один символ.

Что оценивается
• Символов всегда ровно столько, сколько требует пользователь.
• Вывод восклицательных знаков находится посередине, когда это возможно, 
и со сдвигом на один символ в остальных случаях.*/

#include <iostream>
#include <string>

using namespace std;

class task_14
{
    public:
        void important_announcements()
        {
            int total_length;
            cout << "Enter a number of total length: ";
            cin >> total_length;
            cin.ignore(32767, '\n');
            if (total_length < 1)
            {
                cout << "Invalid input\n";
                return;
            }

            int exclamation_marks;
            cout << "Enter a number of exclamation marks: ";
            cin >> exclamation_marks;
            cin.ignore(32767, '\n');
            if (exclamation_marks < 1)
            {
                cout << "Invalid input\n";
                return;
            }
            if (exclamation_marks > total_length)
            {
                cout << "Invalid input\n";
                return;
            }

            string message;
            cout << "Enter a message with " << total_length << " characters: ";
            getline(cin, message);

            int spaces = (total_length - exclamation_marks) / 2;
            for (int i = 0; i < spaces; i++)
            {
                cout << "_";
            }
            for (int i = 0; i < exclamation_marks; i++)
            {
                cout << "!";
            }
            for (int i = 0; i < spaces; i++)
            {
                cout << "_";
            }

            cout << "\n" << message << endl;
        }
};