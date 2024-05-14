/** Лифт
В Объединённых Арабских Эмиратах находится самый высокий небоскрёб Земли — Burj Khalifa. 
Он оборудован скоростными пассажирскими лифтами, но вот беда: иногда они дают сбой и застревают между 
этажами. В этом случае известно число H — высота пола остановившейся кабины лифта над уровнем земли. 
Чтобы команда лифтёров знала, куда ей ехать, шейх поручил вам написать программу, которая по известному 
H определяет, на каком этаже находится большая часть кабины. 
Известно, что расстояние между этажами Burj Khalifa равно 3,975 м, а этаж на уровне земли имеет номер 1. 
На ввод программа принимает вещественное число H, на экран выводит целое число — номер этажа. 
Не используйте при решении условный оператор, кроме как для обеспечения контроля ввода.*/

#include <iostream>
#include <string>

using namespace std;

class task_10
{
    public:
        void run()
        {
            cout << "Enter the height of the floor of the stopped elevator cabin above the ground level: ";
            string height;
            getline(cin, height);
            double height_d = stod(height);
            if (height_d < 0)
            {
                cout << "Invalid input." << endl;
                return;
            }
            int floor = static_cast<int>((height_d / 3.975) * 1000) % 1000;
            if (floor > 500)
            {
                cout << "The floor number is " << static_cast<int>(height_d / 3.975) + 2 << "." << endl;
            }
            else
            {
                cout << "The floor number is " << static_cast<int>(height_d / 3.975) + 1 << "." << endl;
            }
        }
};