#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file{"FileWithSomeText.txt"};
    std::ofstream out_file{"CopyFile.txt"};
    
    if(!in_file)
    {
        std::cerr << "Some problem with in_file" << std::endl;
        return -1;
    }
    
    if(!out_file)
    {
        std::cerr << "Some problem with out_file" << std::endl;
        return -1;
    }
    
    /*std::string line{};
    while(std::getline(in_file, line))
    {
        out_file << line << std::endl;
    }*/
    
    char c{};
    while(in_file.get(c))
    {
        out_file.put(c);
    }
    
    std::cout << "File copied" << std::endl;
    
    in_file.close();
    out_file.close();
    return 0;
}