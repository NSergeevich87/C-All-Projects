/** Метеостанция
Для удобства работы сотрудников международной метеостанции каждый день нужно распечатывать различные 
таблицы соответствия градусов по шкалам Цельсия и Фаренгейта. Напишите программу, которая принимает на вход 
три целых числа в градусах Цельсия: нижняя граница температуры, верхняя граница температуры и шаг. 
Программа выводит на экран таблицу соответствия градусов Цельсия градусам Фаренгейта от нижней до верхней 
границы с указанным шагом. Обеспечьте контроль ввода. Верхняя граница должна печататься, даже если 
последний шаг «перепрыгнул» её. Известно, что 0 °С соответствует 32 °F, а каждый градус Цельсия 
эквивалентен 1,8 градусам Фаренгейта.
Пример
Ввод:

Нижняя граница: 0.
Верхняя граница: 40.
Шаг: 20.

Вывод:

C F
0 32
20 68
40 104*/

#include <iostream>
#include <string>

using namespace std;

class task_6
{
    public:
        void run()
        {
            cout << "Enter lower bound: ";
            string lower_bound;
            getline(cin, lower_bound);
            int lower = stoi(lower_bound);
            cout << "Enter upper bound: ";
            string upper_bound;
            getline(cin, upper_bound);
            int upper = stoi(upper_bound);
            cout << "Enter step: ";
            string step_str;
            getline(cin, step_str);
            int step = stoi(step_str);
            cout << "C F" << endl;
            for (int i = lower; i <= upper; i += step)
            {
                cout << i << " " << i * 1.8 + 32 << endl;
            }
        }
};