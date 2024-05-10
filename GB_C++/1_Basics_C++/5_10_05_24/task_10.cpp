/** Полёт нормальный!
Что нужно сделать
Напишите программу для аэропорта, проверяющую, правильным ли эшелоном летит самолёт.

Условие:
• скорость самолёта должна быть в диапазоне от 750 до 850 км/ч;
• высота — в диапазоне от 9 000 до 9 500 метров.*/

#include <iostream>

class task_10
{
    public:
        void run()
        {
            int speed, height;
            std::cout << "Enter the speed of the plane: ";
            std::cin >> speed;
            std::cout << "Enter the height of the plane: ";
            std::cin >> height;

            if ((speed >= 750 && speed <= 850) && (height >= 9000 && height <= 9500))
            {
                std::cout << "Flight is normal\n";
            }
            else
            {
                std::cout << "Flight is not normal\n";
            }

            std::cin.ignore(32767, '\n');
        }
};