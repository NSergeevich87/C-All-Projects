#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::string line;
    int num;
    double total;
    
    std::ifstream in_file;
    in_file.open("test.txt");
    
    if(!in_file)
    {
        cerr << "Problem with opening file" << endl;
        return -1;
    }
    cout << "File ready to read" << endl;
    
    in_file >> line >> num >> total;
    cout << line << endl;
    cout << num << endl;
    cout << total << endl;
	
	in_file.close();
	return 0;
}		