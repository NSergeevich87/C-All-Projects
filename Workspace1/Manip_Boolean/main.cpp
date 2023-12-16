#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "noboolalpha 10 == 10 : " << (10 == 10) << std::endl;
    std::cout << "noboolalpha 10 == 20 : " << (10 == 20) << std::endl;
	
	std::cout << std::boolalpha;
    std::cout << "boolalpha 10 == 10 : " << (10 == 10) << std::endl;
    std::cout << "boolalpha 10 == 20 : " << (10 == 20) << std::endl;
    
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha 10 == 10 : " << (10 == 10) << std::endl;
    std::cout << "noboolalpha 10 == 20 : " << (10 == 20) << std::endl;
    
    std::cout.setf(std::ios::boolalpha);
    std::cout << "boolalpha 10 == 10 : " << (10 == 10) << std::endl;
    std::cout << "boolalpha 10 == 20 : " << (10 == 20) << std::endl;
    
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "noboolalpha 10 == 10 : " << (10 == 10) << std::endl;
    std::cout << "noboolalpha 10 == 20 : " << (10 == 20) << std::endl;
    
	return 0;
}		