/** Задание 2. Иерархия геометрических фигур
Что нужно сделать
Спроектируйте иерархию классов различных фигур: круг, квадрат, равносторонний треугольник, прямоугольник.
Для всех этих фигур есть общие поля-данные — это координаты их центра и условный цвет фигуры: красный, 
синий или зелёный.
Для отдельных фигур есть и уникальные параметры: радиус для круга, длина ребра для квадрата и 
равностороннего треугольника, ширина и высота для прямоугольника. Все данные — это вещественные числа 
с удвоенной точностью.
Для каждой из фигур требуется определить метод нахождения площади фигуры, а также метод нахождения 
прямоугольника, описывающего фигуру полностью.

Для теста предусмотрите ввод пользователем команд: circle, square, triangle, rectangle, соответствующих 
фигурам. Команды должны получать параметры фигур и выводить их цвет, площадь и описывающий прямоугольник 
с координатами.

Советы и рекомендации
Для цвета фигуры вы можете использовать собственный тип enum, в котором может содержаться и константа 
отсутствия цвета — None.
Площадь треугольника считается как length * length * std::sqrt(3) / 4; где length — сторона. 
Площадь круга — как atan(1) * 4 * radius;*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

enum class Color
{
    None,
    Red,
    Green,
    Blue
};

class Figure
{
public:
    Figure(double inX, double inY, Color inColor) : x(inX), y(inY), color(inColor) {}
    virtual double getArea() = 0;
    virtual void getRectangle() = 0;
protected:
    double x;
    double y;
    Color color;
};

class Circle : public Figure
{
public:
    Circle(double inX, double inY, Color inColor, double inRadius) : Figure(inX, inY, inColor), radius(inRadius) {}
    double getArea() override
    {
        return atan(1) * 4 * radius;
    }
    void getRectangle() override
    {
        std::cout << "Circle: " << std::endl;
        std::cout << "Color: " << static_cast<int>(color) << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Rectangle: " << std::endl;
        std::cout << "x1: " << x - radius << " y1: " << y - radius << std::endl;
        std::cout << "x2: " << x + radius << " y2: " << y + radius << std::endl;
    }
private:
    double radius;
};

class Square : public Figure
{
public:
    Square(double inX, double inY, Color inColor, double inLength) : Figure(inX, inY, inColor), length(inLength) {}
    double getArea() override
    {
        return length * length;
    }
    void getRectangle() override
    {
        std::cout << "Square: " << std::endl;
        std::cout << "Color: " << static_cast<int>(color) << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Rectangle: " << std::endl;
        std::cout << "x1: " << x - length / 2 << " y1: " << y - length / 2 << std::endl;
        std::cout << "x2: " << x + length / 2 << " y2: " << y + length / 2 << std::endl;
    }
private:
    double length;
};

class Triangle : public Figure
{
public:
    Triangle(double inX, double inY, Color inColor, double inLength) : Figure(inX, inY, inColor), length(inLength) {}
    double getArea() override
    {
        return length * length * std::sqrt(3) / 4;
    }
    void getRectangle() override
    {
        std::cout << "Triangle: " << std::endl;
        std::cout << "Color: " << static_cast<int>(color) << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Rectangle: " << std::endl;
        std::cout << "x1: " << x - length / 2 << " y1: " << y - length / 2 << std::endl;
        std::cout << "x2: " << x + length / 2 << " y2: " << y + length / 2 << std::endl;
    }
private:
    double length;
};

class Rectangle : public Figure
{
public:
    Rectangle(double inX, double inY, Color inColor, double inWidth, double inHeight) : Figure(inX, inY, inColor), width(inWidth), height(inHeight) {}
    double getArea() override
    {
        return width * height;
    }
    void getRectangle() override
    {
        std::cout << "Rectangle: " << std::endl;
        std::cout << "Color: " << static_cast<int>(color) << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Rectangle: " << std::endl;
        std::cout << "x1: " << x - width / 2 << " y1: " << y - height / 2 << std::endl;
        std::cout << "x2: " << x + width / 2 << " y2: " << y + height / 2 << std::endl;
    }
private:
    double width;
    double height;
};

int main()
{
    std::vector<Figure*> figures;
    std::string command;
    while (true)
    {
        std::cout << "Enter command (circle, square, triangle, rectangle) or q for exit: ";
        std::cin >> command;
        if (command == "circle")
        {
            double x, y, radius;
            int color;
            std::cout << "Enter center x, y then number of color (0 - None, 1 - Red, 2 - Green, 3 - Blue) and radius: ";
            std::cin >> x >> y >> color >> radius;
            figures.push_back(new Circle(x, y, static_cast<Color>(color), radius));
        }
        else if (command == "square")
        {
            double x, y, length;
            int color;
            std::cout << "Enter center x, y then number of color (0 - None, 1 - Red, 2 - Green, 3 - Blue) and length: ";
            std::cin >> x >> y >> color >> length;
            figures.push_back(new Square(x, y, static_cast<Color>(color), length));
        }
        else if (command == "triangle")
        {
            double x, y, length;
            int color;
            std::cout << "Enter center x, y then number of color (0 - None, 1 - Red, 2 - Green, 3 - Blue) and length: ";
            std::cin >> x >> y >> color >> length;
            figures.push_back(new Triangle(x, y, static_cast<Color>(color), length));
        }
        else if (command == "rectangle")
        {
            double x, y, width, height;
            int color;
            std::cout << "Enter center x, y then number of color (0 - None, 1 - Red, 2 - Green, 3 - Blue) and width, height: ";
            std::cin >> x >> y >> color >> width >> height;
            figures.push_back(new Rectangle(x, y, static_cast<Color>(color), width, height));
        }
        else if (command == "q")
        {
            break;
        }
        else
        {
            std::cout << "Unknown command" << std::endl;
        }
    }
    for (auto figure : figures)
    {
        figure->getRectangle();
    }
    for (auto figure : figures)
    {
        delete figure;
    }
    return 0;
}