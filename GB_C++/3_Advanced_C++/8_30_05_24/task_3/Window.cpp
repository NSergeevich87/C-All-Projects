#include "headers/Window.h"

Window::Window(int x, int y, int width, int height) 
    : x(x), y(y), width(width), height(height) {}

void Window::move(int dx, int dy)
{
    x += dx;
    y += dy;
    std::cout << "Window moved to (" << x << ", " << y << ")" << std::endl;
}

void Window::resize(int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;
    std::cout << "Window resized to " << width << "x" << height << std::endl;
}

void Window::display()
{
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 80; ++j)
        {
            if (j >= x && j < x + width && i >= y && i < y + height)
            {
                std::cout << "1";
            }
            else
            {
                std::cout << "0";
            }
        }
        std::cout << std::endl;
    }
}