#include <iostream>
#include <iomanip>

int main()
{
    int num {255};
    std::cout << "===================================================" << std::endl;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::oct << num << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::oct << num << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::oct << num << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::oct << num << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);
    std::cout << "===================================================" << std::endl;
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);
	return 0;
}		