// simple calculator

#include <iostream>

template <typename T>
T average(T array[8])
{
    T sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += array[i];
    }
    return sum / 8;
}

template <typename T>
void input(T array[8])
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}

int main()
{
    int array[8];
    input(array);
    std::cout << "Average: " << average(array) << std::endl;
    return 0;
}