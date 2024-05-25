/** Математический вектор
Что нужно сделать
Реализуйте структуру двумерного математического вектора и основные операции над ним. 
Обе координаты вектора (x и y) должны быть вещественными числами.
Начиная работу с программой, пользователь вводит команду. Затем в зависимости от команды 
пользователь вводит аргументы. Это могут быть как векторы, так и обычные скалярные значения. 
Результат помещается в стандартный вывод. Это тоже может быть или вектор, или скаляр.

Реализуйте в виде отдельных функций операции:
• сложение двух векторов — команда add;
• вычитание двух векторов — команда subtract;
• умножение вектора на скаляр — команда scale;
• нахождение длины вектора — команда length;
• нормализация вектора — команда normalize.

Советы и рекомендации
Для выбора команды используйте конструкцию вида if (operation == "add"). Тут так и напрашиваются 
отдельные функции для каждой операции.*/

#include <iostream>
#include <string>
#include <cmath>

struct Vector
{
    double x;
    double y;
};

Vector add(Vector a, Vector b)
{
    Vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Vector subtract(Vector a, Vector b)
{
    Vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

Vector scale(Vector a, double b)
{
    Vector result;
    result.x = a.x * b;
    result.y = a.y * b;
    return result;
}

double length(Vector a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

Vector normalize(Vector a)
{
    double len = length(a);
    Vector result;
    result.x = a.x / len;
    result.y = a.y / len;
    return result;
}

int main()
{
    bool quit = false;
    while (!quit)
    {
            std::string operation;
        std::cout << "Enter operation -> add, subtract, scale, length, normalize OR -> q for quit: ";
        std::cin >> operation;

        if (operation == "add")
        {
            Vector a, b;
            std::cout << "Enter two vectors -> a.x, a.y than b.x, b.y: ";
            std::cin >> a.x >> a.y >> b.x >> b.y;
            Vector result = add(a, b);
            std::cout << "Result: " << result.x << ' ' << result.y << std::endl;
        }
        else if (operation == "subtract")
        {
            Vector a, b;
            std::cout << "Enter two vectors -> a.x, a.y than b.x, b.y: ";
            std::cin >> a.x >> a.y >> b.x >> b.y;
            Vector result = subtract(a, b);
            std::cout << "Result: " << result.x << ' ' << result.y << std::endl;
        }
        else if (operation == "scale")
        {
            Vector a;
            double b;
            std::cout << "Enter vector -> a.x, a.y than scalar b: ";
            std::cin >> a.x >> a.y >> b;
            Vector result = scale(a, b);
            std::cout << "Result: " << result.x << ' ' << result.y << std::endl;
        }
        else if (operation == "length")
        {
            Vector a;
            std::cout << "Enter vector -> a.x, a.y: ";
            std::cin >> a.x >> a.y;
            double result = length(a);
            std::cout << "Result: " << result << std::endl;
        }
        else if (operation == "normalize")
        {
            Vector a;
            std::cout << "Enter vector -> a.x, a.y: ";
            std::cin >> a.x >> a.y;
            Vector result = normalize(a);
            std::cout << "Result: " << result.x << ' ' << result.y << std::endl;
        }
        else if (operation == "q")
        {
            quit = true;
        }
        else
        {
            std::cout << "Unknown operation";
        }
    }

    return 0;
}