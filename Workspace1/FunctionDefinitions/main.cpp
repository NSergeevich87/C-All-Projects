//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);
#include <cmath>

using namespace std;

const double pi {3.14159};

void SayHello()
{
    cout << "Welcome to my program!" << endl;
    return;
}

double calc_area_circle(double radius)
{
    return pi * pow(radius, 2);
}
  
double calc_volume_cylinder(double radius, double height)
{
    //return pi * pow(radius, 2) * height;
    return calc_area_circle(radius) * height;
}
  
void area_circle()
{
    cout << "Enter the radius of the circle: ";
    double radius {};
    cin >> radius;
    
    cout << "Area of the circle con radius " << radius << " is " << calc_area_circle(radius) << endl;
}
  
void volume_cylinder()
{
    double radius {};
    double height {};
    cout << "Enter radius of the cylinder: ";
    cin >> radius;
    cout << "Enter height of the cylinder: ";
    cin >> height;
    
    cout << "Volume of the cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}
  
int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        SayHello();
        area_circle();
        volume_cylinder();
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}

