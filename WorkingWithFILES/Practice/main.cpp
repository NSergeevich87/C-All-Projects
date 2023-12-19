#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string text;
    float num;
    
    ifstream in_file;
    in_file.open("myfile.txt");
    
    if(!in_file)
    {
        cerr << "Problem with opening file" << endl;
        return -1;
    }
    
    cout << "File ready to read\n" << endl;
    
    in_file >> text >> num;
    cout << setw(10) << left << text 
         << setw(10) << num << endl;
    
	in_file.close();
	return 0;
}		