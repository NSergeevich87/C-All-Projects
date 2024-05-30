#pragma once

#include <iostream>

class Window
{
private:
    int x;
    int y;
    int width;
    int height;

public:
    Window(int x, int y, int width, int height);

    void move(int dx, int dy);

    void resize(int newWidth, int newHeight);

    void display();
};