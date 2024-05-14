/** Маятник
Что нужно сделать
Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4% от амплитуды прошлого колебания. 
Если качнуть маятник, он, строго говоря, никогда не остановится: его амплитуда будет уменьшаться до тех пор, 
пока мы не сочтём такой маятник остановившимся. Напишите программу, определяющую, сколько раз качнётся 
маятник, прежде чем он, по нашему мнению, остановится. Программа получает на вход начальную амплитуду 
колебания в сантиметрах и конечную амплитуду его колебаний, которая считается остановкой маятника. 
Обеспечьте контроль ввода.
Рекомендации по выполнению
Считаем, что затухание происходит на каждое качание.

Что оценивается
• Программа правильно считает количество затуханий.
• Цикл не бесконечный.*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class task_17
{
    public:
        void run()
        {
            cout << "Enter the initial amplitude of the pendulum: ";
            double initial_amplitude;
            cin >> initial_amplitude;

            cout << "Enter the final amplitude of the pendulum: ";
            double final_amplitude;
            cin >> final_amplitude;

            cin.ignore(32767, '\n');

            int swings = 0;
            while (initial_amplitude > final_amplitude)
            {
                initial_amplitude *= 0.916; // -8.4%
                swings++;
            }

            cout << "The pendulum will swing " << swings << " times before stopping." << endl;
        }
};