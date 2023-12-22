#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream out_file2 {"name.txt", std::ios::app};
    
    std::ofstream out_file;
    out_file.open("outfile.txt", std::ios::app);
    
    if(!out_file || !out_file2)
    {
        std::cerr << "Some problem with file" << std::endl;
        return -1;
    }
    else std::cout << "File ready to write" << std::endl;
    
    std::string line{};
    std::cout << "Write somethin into the file: ";
    std::getline(std::cin, line);
    out_file << line << std::endl;
    out_file2 << line << std::endl;
    
    out_file.close();
    out_file2.close();
    return 0;
}