#include "vector3D.h"
#include <cmath>

vector3D::vector3D(double x, double y, double z)
    : _x(x), _y(y), _z(z)
{
}

double vector3D::norm() const
{
    return sqrt(_x * _x + _y * _y + _z * _z);
}