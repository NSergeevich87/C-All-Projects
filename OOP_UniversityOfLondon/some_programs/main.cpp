#include <iostream>

int main()
{
    unsigned long long int a{};
    signed long long int b{};

    long double c{};
    double d{};

    float f{};
    signed short int e{};

    std::cout << "Unsigned long long int: " << sizeof(a) << " bytes\n";
    std::cout << "Long long int: " << sizeof(b) << " bytes\n";
    std::cout << "Long double: " << sizeof(c) << " bytes\n";
    std::cout << "Double: " << sizeof(d) << " bytes\n";
    std::cout << "Short int: " << sizeof(e) << " bytes\n";
    std::cout << "Float: " << sizeof(f) << " bytes\n";
}