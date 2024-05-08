#include <iostream>
#include <limits>

using namespace std;

class task_1
{
public:
    void run()
    {
        //task_1

        int number;
        cout << "Enter number: ";
        try
        {
            cin >> number;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Wrong number!" << '\n';
        }
        
        cout << "Your number: " << number << endl;
        cout << "Scuare of your number: " << number * number << endl;

        /** clean the input buffer from the previous input */
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};