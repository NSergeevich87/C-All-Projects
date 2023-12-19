#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    char c{};
    ifstream in_file;
    in_file.open("poem.txt");
    
    if(!in_file)
    {
        cerr << "Some problem with opening file" << endl;
        return -1;
    }
    else cout << "File ready to read\n" << endl;
	
    while(in_file.get(c))
    {
        cout << c;
    }
    
	in_file.close();
	return 0;
}		