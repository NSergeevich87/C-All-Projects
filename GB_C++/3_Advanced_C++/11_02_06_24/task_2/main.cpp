/** Задача 2. Интерфейс Shape (дополнительное задание)
У вас есть набор классов различных геометрических фигур: 
круг(Circle), прямоугольник(Rectangle) и треугольник(Triangle), 
которые наследуются от общего класса геометрическая фигура (Shape). 
Каждый из этих классов имеет методы подсчёта площади, описывающего прямоугольника и взятия типа. 
Также есть общая функция printParams которая по переданному ей указателю 
на объект типа геометрическая фигура выводит на экран тип фигуры.

Что нужно сделать
Создайте интерфейс Shape (фигуру), который предоставляет следующие методы:
— virtual double square() = 0; — возвращает площадь конкретной фигуры;
— virtual BoundingBoxDimensions dimensions() = 0; — размеры описывающего прямоугольника;
BoundingBoxDimensions — простая структура, которая содержит ширину и высоту;
— virtual std::string type() = 0; — название конкретного типа, например, 
вернуть строку Triangle для класса Triangle;
void printParams(Shape *shape) — сюда можно будет передавать любые фигуры.

Создайте классы-наследники Shape: Circle, Rectangle и Triangle.
У каждого из классов будет разный набор полей: у треугольника будут три стороны в виде переменных double, 
у круга — радиус, а у прямоугольника — длина и ширина. Так как все они наследуются от Shape, 
в каждом из классов следует реализовать методы нахождения размерности, площади и метод, 
возвращающий название типа.
Площадь треугольника при известных длинах сторон находится при помощи формулы Герона:
sqrt(p * (p - a) * (p - b) * (p - c)), где p — полупериметр.
Размеры описывающего прямоугольника для треугольника находятся по похожей формуле — сначала находим радиус 
описанной окружности:
a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c))), где р — снова полупериметр.
Затем умножаем его на два и получаем сторону квадрата, в который помещён треугольник.
В функции main вызовите printParams со всеми типами, которые вы создали.
Пример

Triangle t(3,4,5);
printParams(&t);

Вывод

Type: Triangle
Square: 6
Width: 5
Height: 5*/

#include <iostream>
#include <string>
#include <cmath>

#define M_PI 3.14159265358979323846

class Shape
{
public:
    Shape() = default;
    virtual double square() = 0;
    virtual std::string type() = 0;
    struct BoundingBoxDimensions
    {
        double width;
        double height;
    };
    virtual BoundingBoxDimensions dimensions() = 0;
};

class Circle : public Shape
{
private:
    double m_radius;

public:
    Circle(double radius) : m_radius(radius) {}
    double square() override
    {
        return M_PI * m_radius * m_radius;
    }
    std::string type() override
    {
        return "Circle";
    }
    BoundingBoxDimensions dimensions() override
    {
        return {2 * m_radius, 2 * m_radius};
    }
};

class Rectangle : public Shape
{
private:
    double m_width;
    double m_height;

public:
    Rectangle(double width, double height) : m_width(width), m_height(height) {}
    double square() override
    {
        return m_width * m_height;
    }
    std::string type() override
    {
        return "Rectangle";
    }
    BoundingBoxDimensions dimensions() override
    {
        return {m_width, m_height};
    }
};

class Triangle : public Shape
{
private:
    double m_a;
    double m_b;
    double m_c;
    
public:
    Triangle(double a, double b, double c) : m_a(a), m_b(b), m_c(c) {}
    double square() override
    {
        double p = (m_a + m_b + m_c) / 2;
        return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
    }
    std::string type() override
    {
        return "Triangle";
    }
    BoundingBoxDimensions dimensions() override
    {
        double p = (m_a + m_b + m_c) / 2;
        double r = m_a * m_b * m_c / (4 * sqrt(p * (p - m_a) * (p - m_b) * (p - m_c)));
        return {2 * r, 2 * r};
    }
};

void printParams(Shape *shape)
{
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    auto dim = shape->dimensions();
    std::cout << "Width: " << dim.width << std::endl;
    std::cout << "Height: " << dim.height << std::endl;
}

int main()
{
    Circle c(5);
    Rectangle r(3, 4);
    Triangle t(3, 4, 5);
    printParams(&c);
    printParams(&r);
    printParams(&t);
    return 0;
}