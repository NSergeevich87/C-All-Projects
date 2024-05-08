#include <iostream>
#include <string>
#include <limits>

using namespace std;

class task_5
{
    public:
        void run()
        {
            string stops[] = {"street programmers", "street algorithms", "square of code", "avenue of javists"};
            int all_passengers = 0;
            int passengers = 0;
            float salary = 0;
            float fuel = 0;
            float taxes = 0;
            float repair = 0;
            float income = 0;
            float earned = 0;

            for (int i = 0; i < 4; i++)
            {
                cout << "Next stop: " << stops[i] << ". All passengers: " << passengers << endl;
                cout << "How much passengers quit?: ";
                int out;
                cin >> out;
                if (out > passengers)
                {
                    cout << "Error! Can't quit more than all passengers!" << endl;
                    continue;
                }
                passengers -= out;
                cout << "How much passengers enter?: ";
                int in;
                cin >> in;
                passengers += in;
                all_passengers += in;
                cout << "Go from the station: " << stops[i] << ". All passengers: " << passengers << endl;
            }

            income = all_passengers * 20;
            earned = income;
            salary = income / 4;
            fuel = income / 5;
            taxes = income / 5;
            repair = income / 5;
            earned -= salary + fuel + taxes + repair;

            cout << "All money erned: " << income << " rub." << endl;
            cout << "Salary of driver: " << salary << " rub." << endl;
            cout << "Fuel price: " << fuel << " rub." << endl;
            cout << "Taxes: " << taxes << " rub." << endl;
            cout << "Repair car: " << repair << " rub." << endl;
            cout << "All income money: " << earned << " rub." << endl;

            /** clean the input buffer from the previous input */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
};