#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream in_file;
    in_file.open("poem.txt");
    
    if(!in_file)
    {
        cerr << "Some problem with opening file" << endl;
        return -1;
    }
    else cout << "File ready to read\n" << endl;
    
    std::string line{};
    
    while(std::getline(in_file, line))
    {
        cout << line << endl;
    }
	
    in_file.close();
	return 0;
}		