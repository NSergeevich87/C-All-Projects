#include <iostream>

using namespace std;

class ExceptionDivByZero {};
class ExceptionNegValue {};

double calculate_mpg(int m, int g)
{
    if (g == 0) throw ExceptionDivByZero();
    if (m < 0 || g < 0) throw ExceptionNegValue();
    return static_cast<double>(m) / g;
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
        result = calculate_mpg(miles, gallons);
        cout << "Result: " << result << endl;
    }
    catch (const ExceptionDivByZero &ex)
    {
        cerr << "Division by zero" << endl;
    }
    catch (const ExceptionNegValue &ex)
    {
        cerr << "Negative value" << endl;
    }
	
	cout << endl;
	return 0;
}		