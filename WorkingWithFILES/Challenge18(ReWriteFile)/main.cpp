#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::string line{};
    int number{0};
    
    //int width{50};
    int left_width{6};
    //int right_width{25};
    
    std::ifstream in_file{"romeoandjuliet.txt"};
    std::ofstream out_file{"copypoemwithnumbers.txt"};
    
    if(!in_file)
    {
        std::cerr << "Problem with 'in_file'" << std::endl;
        return -1;
    }
    
    if(!out_file)
    {
        std::cerr << "Problem with 'out_file'" << std::endl;
        return -1;
    }
    
    while(std::getline(in_file, line))
    {
        if(line != "")
        {
            ++number;
            out_file << std::setw(left_width) << std::left << number 
                 << line << std::endl;
        }
        else
        {
            out_file << std::endl;
        }
        
        /*++number;
        out_file << std::setw(left_width) << std::left << number 
                 << line << std::endl;*/
    }
    
    
    std::cout << "All done, thanks" << std::endl;
    in_file.close();
    out_file.close();
    return 0;
}