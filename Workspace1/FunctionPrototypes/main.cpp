//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);
#include <cmath>

//Здесь идея заключается в том что описание методов может быть ниже метода main() только в тогда когда перед мейном указываем прототипы методов.

using namespace std;

void area_rectangle();
void area_square();
void area_trapezoid();
double calc_area_rectangle(double, double);
double calc_area_square(double);
double calc_area_trapezoid(double, double, double);

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        area_rectangle();
        area_square();
        area_trapezoid();
        
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}

void area_rectangle()
{
    double height {};
    double wide {};
    cout << "Enter height of the rectangle: ";
    cin >> height;
    cout << "Enter wide of the rectangle: ";
    cin >> wide;
    
    cout << "The area of a rectangle with height " << height << " and " << wide << " is " << calc_area_rectangle(height, wide) << endl;
}

void area_square()
{
    double side {};
    cout << "Enter one side of the square: ";
    cin >> side;
    
    cout << "The area of a square with side " << side << " is " << calc_area_square(side) << endl;
}

void area_trapezoid()
{
    double first_fundation {};
    double second_fundation {};
    double height {};
    cout << "Enter first fundation of the trapezoid: ";
    cin >> first_fundation;
    cout << "Enter second fundation of the trapezoid: ";
    cin >> second_fundation;
    cout << "Enter height of the trapezoid: ";
    cin >> height;
    
    cout << "The area of a trapezoid with first fundation " << first_fundation << ", second fundation " << second_fundation << " and height " << height << " is " << calc_area_trapezoid(first_fundation, second_fundation, height) << endl;
}

double calc_area_rectangle(double height, double wide)
{
    return height * wide;
}

double calc_area_square(double side)
{
    return pow(side, 2);
}

double calc_area_trapezoid(double first_fundation, double second_fundation, double height)
{
    return (first_fundation + second_fundation) / 2 * height;
}