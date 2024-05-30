/** Задание 3. Реализация программы управления окном рабочего стола
Что нужно сделать
Реализуйте симуляцию работы окна в визуальном интерфейсе пользователя.
Окно располагается на виртуальном экране монитора, размером 80 × 50 точек. У окна есть несколько параметров, 
которые также задаются в пикселях: двумерные координаты левого верхнего угла и размеры, ширина и высота. 
Ширина и высота при этом не могут быть отрицательными, а координаты не могут выходить за область экрана.

Пользователь взаимодействует с программой с помощью команд:

• Команда move принимает вектор, на который надо сместить окно на экране. Сообщение с новыми координатами 
окна появляется на экране.
• Команда resize запрашивает из стандартного ввода новый размер окна. После изменения размера сообщение с 
новым размером выводится на экране.
• Команда display выводит текущее изображение монитора в консоль. 0 — это пиксель вне области окна, 1 — с 
окном.
• Команда close закрывает окно, выход из программы.*/

#include <iostream>
#include <string>
#include <vector>

#include "headers/Window.h"

int main()
{
    Window window(10, 10, 20, 10);

    std::string command;
    while (true)
    {
        std::cout << "Enter command (move, resize, display, close): ";
        std::cin >> command;
        if (command == "move")
        {
            int dx, dy;
            std::cout << "Enter dx: ";
            std::cin >> dx;
            std::cout << "Enter dy: ";
            std::cin >> dy;
            window.move(dx, dy);
        }
        else if (command == "resize")
        {
            int newWidth, newHeight;
            std::cout << "Enter new width: ";
            std::cin >> newWidth;
            std::cout << "Enter new height: ";
            std::cin >> newHeight;
            window.resize(newWidth, newHeight);
        }
        else if (command == "display")
        {
            window.display();
        }
        else if (command == "close")
        {
            break;
        }
    }

    return 0;
}