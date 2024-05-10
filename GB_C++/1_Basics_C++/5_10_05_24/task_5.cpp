/** Треугольник.
У меня есть три деревянных палочки, длины этих палочек равны A, B и C. 
Напишите программу, которая по данным длинам определяет, можно ли из этих трех палочек сложить треугольник.
Подсказка: треугольник сложить нельзя, если суммарная длина каких-либо двух палочек меньше или равна 
длины оставшейся палочки.*/

#include <iostream>

class task_5
{
    public:
        void run()
        {
            int a, b, c;
            std::cout << "Enter the length of the first stick: ";
            std::cin >> a;
            std::cout << "Enter the length of the second stick: ";
            std::cin >> b;
            std::cout << "Enter the length of the third stick: ";
            std::cin >> c;
            
            if (a + b > c && a + c > b && b + c > a)
            {
                std::cout << "You can make a triangle\n";
            }
            else
            {
                std::cout << "You can't make a triangle\n";
            }
            
            std::cin.ignore(32767, '\n');
        }
};