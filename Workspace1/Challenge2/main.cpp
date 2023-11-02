#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to Nikita's clining service!" << endl;
    
    const float price_large_room {35};
    const float price_small_room {25};
    const float tax {0.06};
    const int days {30};
    
    cout << "\nPrice for cleaning large rooms is: " << price_large_room << " $";
    cout << "\nPrice for cleaning small rooms is: " << price_small_room << " $";
    cout << "\nTax is: " << tax * 100 << " %" << endl;
    
    cout << "\nHow many large rooms would you like to clean? ";
    int large_rooms {0};
    cin >> large_rooms;
    
    cout << "\nHow many small rooms would you like to clean? ";
    int small_rooms {0};
    cin >> small_rooms;
    
    cout << "==================================================" << endl;
    
    cout << "Estimate for carpet cleaning service";
    cout << "\nNumber of small rooms: " << small_rooms;
    cout << "\nNumber of large rooms: " << large_rooms;
    double pay_cost = (price_large_room * large_rooms) + (price_small_room * small_rooms);
    cout << "\nCost: " << pay_cost << " $";
    double pay_tax = pay_cost * tax;
    cout << "\nTax: " << pay_tax << " $";
    
    cout << "\n==================================================" << endl;
    
    cout << "Total estimate: " << pay_tax + pay_cost << " $";
    cout << "\nThis estimate is valid for " << days << " days" << endl;
    
    return 0;
}