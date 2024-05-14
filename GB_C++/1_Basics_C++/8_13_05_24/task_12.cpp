/** Космический симулятор
Что нужно сделать
Вы пишете симулятор космических полётов. Ваш звездолёт массой m килограмм включает двигатель с силой тяги F 
ньютонов на t секунд. Напишите программу, которая по заданным F, m и t покажет, на каком расстоянии от 
первоначального положения окажется космический корабль через t секунд. Обеспечьте контроль ввода.
Примечание: космический корабль находится в открытом космосе.
Напоминаем, что расстояние можно рассчитать по формуле:

Рекомендации по выполнению
Для операции возведения в степень удобно использовать функцию std::pow.

Что оценивается
• Правильно использована формула.
• В расчётах используются переменные типа float.*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class task_12
{
    public:
        void run()
        {
            cout << "Enter the mass of the spacecraft: ";
            string mass;
            getline(cin, mass);
            float mass_f = stof(mass);
            if (mass_f <= 0)
            {
                cout << "Invalid input." << endl;
                return;
            }

            cout << "Enter the engine thrust: ";
            string thrust;
            getline(cin, thrust);
            float thrust_f = stof(thrust);
            if (thrust_f <= 0)
            {
                cout << "Invalid input." << endl;
                return;
            }

            cout << "Enter the time of the engine operation: ";
            string time;
            getline(cin, time);
            float time_f = stof(time);
            if (time_f <= 0)
            {
                cout << "Invalid input." << endl;
                return;
            }

            float distance = (thrust_f * pow(time_f, 2)) / (2 * mass_f);
            cout << "The distance from the original position after " << time_f << " seconds: " << distance << endl;
        }
};