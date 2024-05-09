/** Задача 2. Автомобиль.
Автомобиль выехал из Москвы в Рязань. 
Напишите программу, которая вычисляет сумеет ли добраться автомобиль до Рязани 
за два часа с заданной пользователем средней скоростью движения. 
Программа должна выводить вычисленное расстояние, а если автомобиль сумеет добраться до Рязани, 
- сообщение “Вы приехали”. Расстояние между городами - 200 км.*/

#include <iostream>

using namespace std;

class task_2
{
    public:
        void run()
        {
            cout << "Enter average speed of car: ";
            double speed;
            cin >> speed;
            double distance = 200;
            double time = 2;
            double timeToReach = distance / speed;
            if (timeToReach <= time)
            {
                cout << "You have reached the destination.\n";
            }
            else
            {
                cout << "You have not reached the destination.\n";
            }
            cin.ignore(32767, '\n');
        }
};