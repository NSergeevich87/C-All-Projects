/** Улучшим барберов
Что нужно сделать:
Помните задачу про барберов из видео 4.3? Кстати, именно оператор % мог помочь нам с барберами. 
Перепишите программу про них с его использованием для проверки на проблему с целочисленным делением.
Напишите программу, которая отвечает на вопрос хватает ли барберов в данном
городе если задано число людей и число барберов, а так же указано, что
один барбер работает 8 часов в день, на одного клиента тратит 1 час
а каждый клиент приходит раз в месяц. Воспользуйтесь для решения проблемы
целочисленного деления оператором %*/

#include <iostream>

using namespace std;

class task_10
{
    public:
        void run()
        {
            int mans = 0;
            int barbers = 0;
            int days = 30;
            int hours = 8;
            int cutsHour = 1;

            cout << "Haw much mans in city: ";
            cin >> mans;
            cout << "Haw much barbers in city: ";
            cin >> barbers;

            int oneDayMansInBarbershop = mans / days;
            // Если количество мужчин не делится на дни без остатка, то добавляем одного мужчину в барбершоп
            if (mans % days != 0)
            {
                oneDayMansInBarbershop++;
            }

            int cutsInDay = (hours / cutsHour) * barbers;

            if (oneDayMansInBarbershop > cutsInDay)
            {
                cout << "Not enough barbers.\n";
                cout << "Need " <<  (((oneDayMansInBarbershop * barbers) / cutsInDay) - barbers) + 1 << " more barbers.\n";
            }
            else
            {
                cout << "Enough barbers.\n";
                cout << "Barbers can cut " << cutsInDay << " mans in day.\n";
            }

            cin.ignore(32767, '\n');
        }
};