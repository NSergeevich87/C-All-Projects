#include <iostream>

int main()
{
    int favoriteNumber;
    std::cout << "Enter your favorite number between 1 and 100: ";
    std::cin >> favoriteNumber;
    std::cout << "Amazing!! That's my favorite number too!!" << std::endl;
    std::cout << "No, really! " << favoriteNumber << " is my favorite number!!" << std::endl;
    return 0;
}