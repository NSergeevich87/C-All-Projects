#include <iostream>

#include "vector3D.h"

int main()
{
    std::cout << "Hello to my 3D vector program!\n";

    vector3D v1(25.5, 30.5, 35.5);
    std::cout << "The norm of the vector is: " << v1.norm() << std::endl;

    return 0;
}