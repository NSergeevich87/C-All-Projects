/** Военкомат.
Для отбора летчиков устанавливаются жесткие критерии.
Напишите программу, проверяющую, подходит ли призывник. Его рост должен быть не меньше 145см и не больше 165см, 
вес не меньше 45кг и не больше 65кг, а количество рук и ног должно обязательно совпадать 
(мы не знаем, зачем, но так требует инструкция). При этом берут любого человека, 
налетавшего на самолетах больше 100 часов.
Дополнительно.
А еще зеленоглазых в летчики тоже не берут, поэтому проверьте и цвет их глаз.

Подсказка: для цвета глаз используйте строковый тип данных.*/

#include <iostream>

class task_7
{
    public:
        void run()
        {
            int height, weight, hours, hands, legs;
            std::string eyes;
            std::cout << "Enter the height: ";
            std::cin >> height;
            std::cout << "Enter the weight: ";
            std::cin >> weight;
            std::cout << "Enter the number of hands: ";
            std::cin >> hands;
            std::cout << "Enter the number of legs: ";
            std::cin >> legs;
            std::cout << "Enter the number of hours on the plane: ";
            std::cin >> hours;
            std::cout << "Enter the color of the eyes: ";
            std::cin >> eyes;
            
            if (hours > 100 && hands == 2 && legs == 2 && eyes != "green")
            {
                std::cout << "The recruit is suitable\n";
            }
            else if (height >= 145 && height <= 165 && weight >= 45 && weight <= 65 && hands == 2 && legs == 2 && eyes != "green")
            {
                std::cout << "The recruit is suitable\n";
            }
            else
            {
                std::cout << "The recruit is not suitable\n";
            }
            
            std::cin.ignore(32767, '\n');
        }
};