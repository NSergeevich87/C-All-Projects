#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    std::string name;
    int num;
    double total;
    
    ifstream in_file;
    in_file.open("test.txt");
    
    if(!in_file)
    {
        cerr << "Problem with file" << endl;
        return -1;
    }
    cout << "File ready to read" << endl;
	
    while(!in_file.eof())
    {
        in_file >> name >> num >> total;
        cout << setw(10) << left << name
             << setw(10) << num
             << setw(10) << total << endl;
    }
    
	in_file.close();
	return 0;
}		