#include "D:\C-All-Projects\GB_C++\3_Advanced_C++\7_29_05_24\task_1\include\tools.h"

void scalpel(Point start, Point end)
{
    std::cout << "Cut between " << start.x << " " << start.y << " and " << end.x << " " << end.y << std::endl;
}

void hemostat(Point start)
{
    std::cout << "Clamp at " << start.x << " " << start.y << std::endl;
}

void tweezers(Point start)
{
    std::cout << "Tweezers at " << start.x << " " << start.y << std::endl;
}

void suture(Point start, Point end)
{
    std::cout << "Suture between " << start.x << " " << start.y << " and " << end.x << " " << end.y << std::endl;
}