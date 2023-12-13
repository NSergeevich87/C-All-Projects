#include <iostream>
#include <string>

using namespace std;

void function_1();
void function_2();
void function_3();

void function_1()
{
    cout << "Start fun_1" << endl;
    function_2();
    cout << "End fun_1" << endl;
}

void function_2()
{
    cout << "Start fun_2" << endl;
    try
    {
       function_3(); 
    }
    catch (std::string &ex)
    {
        cerr << ex << endl;
    }
    cout << "End fun_2" << endl;
}

void function_3()
{
    cout << "Start fun_3" << endl;
    throw std::string("Error in function_3");
    cout << "End fun_3" << endl;
}

int main()
{
    cout << "Start main" << endl;
    try
    {
       function_1(); 
    }
    catch (int &ex)
    {
        std::cerr << "Error 100" << std::endl;
    }
    cout << "End main" << endl;
	
	cout << endl;
	return 0;
}	