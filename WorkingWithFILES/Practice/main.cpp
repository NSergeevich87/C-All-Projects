#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    string line{};
    //char c{};
    
    ifstream in_file;
    in_file.open("myfile.txt");
    
    if(!in_file)
    {
        cerr << "Error with file" << endl;
        return -1;
    }
    else cout << "File ready" << endl;
    
    //in_file >> line;              // 1 способ 
    //getline(in_file, line);       // 2 способ
    /*while(!in_file.eof())         // 3 способ
    {
        in_file >> line;
        cout << line << endl;
    }*/
    /*while(in_file.get(c))         // 4 способ
    {
        cout << c;
    }*/
    /*while(getline(in_file, line)) // 5 способ
    {
        in_file >> line;
        cout << line << endl;
    }*/
    while(in_file >> line)        // 6 способ
    {
        cout << line << endl;
    }
    
    in_file.close();
	return 0;
}		