#include <iostream>

using namespace std;

double calculate_mpg(int m, int g)
{
    if (g == 0) throw 0;
    return static_cast<double>(m) / g;
}

int main()
{
    int miles{};
    int gallons{};
    double result{};
    
    cout << "Enter miles: ";
    cin >> miles;
    cout << "Enter gallons: ";
    cin >> gallons;
    
    try
    {
        result = calculate_mpg(miles, gallons);
        cout << "Result: " << result << endl;
    }
    catch (int &ex)
    {
        cerr << "Division by zero" << endl;
    }
    
    cout << "Adios!" << endl;
	
	cout << endl;
	return 0;
}		