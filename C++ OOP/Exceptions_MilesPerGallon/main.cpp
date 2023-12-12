#include <iostream>

using namespace std;

int main()
{
	int miles{};
    int gallons{};
    double result{};
    
    cout << "Enter miles: ";
    cin >> miles;
    cout << "Enter gallon: ";
    cin >> gallons;
    
    //result = miles / gallons;
    /*if(gallons != 0)
    {
        result = static_cast<double> (miles) / gallons;
    
        cout << "Result: " << result << endl;
    } else
    {
        cerr << "Sorry, can't divide by zero" << endl;
    }*/
    
    try
    {
        if (gallons == 0) throw 0;
        
        result = static_cast<double> (miles) / gallons;
        cout << "Result: " << result << endl;
    }
    catch (int &ex)
    {
        cerr << "Sorry, can't divide by zero" << endl;
    }
    
    cout << "Bye" << endl;
	
	cout << endl;
	return 0;
}		