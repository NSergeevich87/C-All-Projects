//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);
#include <string>

using namespace std;

double calc_cost(double base_cost, double tax = 0.06, double ship = 3.5);
double calc_cost(double base_cost, double tax, double ship)
{
    return base_cost += (base_cost * tax) + ship;
}
void greetings(string name, string status = "Mr.", string postfix = "Super professor");
void greetings(string name, string status, string postfix)
{
    cout << "Hello " << status << name << " " << postfix << endl;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        double cost {0};
        cout << fixed << setprecision(2); //округляем до двух знаков
        
        cost = calc_cost(100, 0.08, 4.25);
        cout << "Cost is: " << cost << endl;
        
        cost = calc_cost(100, 0.08);
        cout << "Cost is: " << cost << endl;
        
        cost = calc_cost(200);
        cout << "Cost is: " << cost << endl;
        
        greetings("Nikita", "Mrs.", "Ph.D");
        greetings("Nikita", "Mr.");
        greetings("Nikita");
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}