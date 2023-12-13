#include <iostream>
#include <string>

using namespace std;

double division_mpg(int miles, int gallons)
{
    if (gallons == 0) throw 0;
    if (miles < 0 || gallons < 0) throw std::string{"Negative values!"};
    return static_cast<double>(miles) / gallons;
}

int main()
{
    int miles{};
    int gallons{};
    int result{};
    
    cout << "Enter miles: ";
    cin >> miles;
    cout << "Enter gallons: ";
    cin >> gallons;
    
    try
    {
        result = division_mpg(miles, gallons);
        cout << "Result: " << result << endl; 
    }
    catch (int &ex)
    {
        //cerr << ex << endl;
        cerr << "Division by zero" << endl;
    }
    catch (std::string &ex)
    {
        cerr << ex << endl;
    }
	
	cout << "Adios!" << endl;
	return 0;
}		