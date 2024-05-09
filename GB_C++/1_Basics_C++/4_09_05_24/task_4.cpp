/** Задача 4. Барберы (необязательная).
В небольшом городке проживает 18 000 взрослых человек: 9 000 мужчин и 9 000 женщин. 
Согласно традиции этого городка все мужчины обязаны носить бороду. 
Один предприимчивый житель открыл сеть барбершопов, чтобы помочь мужчинам ухаживать за их бородами. 
Однако он никак не может посчитать сколько всего специалистов-барберов для этого нужно. 
Вам нужно написать программу которая будет рассчитывать сколько мужчин можно постричь во всех барбершопах 
исходя из следующих данных:
каждый из 9000 мужчин посещает барбершоп раз в месяц (30 дней)
один барбер способен обслужить одного клиента за 1 час
смена барбера — 8 часов
Программа должна спросить сколько мужчин проживает в городе и сколько всего барберов уже работает 
во всех барбершопах, и посчитать сколько барберов нужно, и если их недостаточно — выдать сообщение об этом. 
Если барберов достаточно — сказать и об этом.*/

#include <iostream>

using namespace std;

class task_4
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