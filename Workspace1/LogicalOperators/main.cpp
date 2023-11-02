#include <iostream>

using namespace std;

int main()
{
    /*cout << boolalpha;
    
    const int num1 {10};
    const int num2 {20};
    int check_num {};
    bool between_numbers {false};
    
    cout << "Enter number between " << num1 << " and " << num2 << " : ";
    cin >> check_num;
    
    between_numbers = (check_num > num1 && check_num < num2);
    cout << check_num << " between " << num1 << " and " << num2 << " : " << between_numbers;*/
    
    cout << boolalpha;
    bool stop {false};
    
    bool warm_wear {false};
    double temperature {};
    int wind_speed {};
    
    const int wind_speed_for_warm_wear {35};
    const double temperature_for_warm_wear {5};
    
    while (!stop)
    {
        cout << "Enter wind_speed: ";
        cin >> wind_speed;
        cout << "Enter temperature: ";
        cin >> temperature;
        
        warm_wear = (wind_speed >= wind_speed_for_warm_wear || temperature <= temperature_for_warm_wear);
        cout << "The weather for warm_wear is: " << warm_wear << endl;
        
        cout << "\nLet's one more time? (y/n): ";
        char answer {};
        cin >> answer;
        
        if (answer == 'n') stop = true;
    }
    
    cout << endl;
    return 0;
}