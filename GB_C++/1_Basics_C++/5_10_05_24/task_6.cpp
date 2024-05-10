/** Совпадение чисел(необязательная).
Напишите программу, которая по трем введенным числам a, b, c определяет, сколько среди них совпадающих чисел.*/

#include <iostream>

class task_6
{
    public:
        void run()
        {
            int a, b, c;
            std::cout << "Enter the first number: ";
            std::cin >> a;
            std::cout << "Enter the second number: ";
            std::cin >> b;
            std::cout << "Enter the third number: ";
            std::cin >> c;
            
            if (a == b && b == c)
            {
                std::cout << "All numbers are equal\n";
            }
            else if (a == b || b == c || a == c)
            {
                std::cout << "Two numbers are equal\n";
            }
            else
            {
                std::cout << "All numbers are different\n";
            }
            
            std::cin.ignore(32767, '\n');
        }
};