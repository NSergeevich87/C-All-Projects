#pragma once

#include <iostream>

struct Point
{
    double x;
    double y;
};

void scalpel(Point start, Point end);

void hemostat(Point start);

void tweezers(Point start);

void suture(Point start, Point end);
