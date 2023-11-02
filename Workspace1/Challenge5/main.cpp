#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool isExit {false};
    vector<double> data { 1, 9, 8, 7 };
    
    cout << "Welcome to Challenge 5" << endl;
    cout << "======================" << endl;
    
    while (!isExit)
    {
        char answer {};
        cout << endl;
        cout << "P - Print numbers";
        cout << "\nC - Clear numbers";
        cout << "\nA - Add a number";
        cout << "\nM - Display mean of the numbers";
        cout << "\nS - Display the smallest number";
        cout << "\nL - Display the largest number";
        cout << "\nQ - Quit" << endl;
        cout << "======================" << endl;
        cout << "Enter your choice: ";
        cin >> answer;
        
        switch (answer)
        {
            case 'P':
            case 'p':
            {
                if (data.size() == 0) cout << "\n[] - the list is empty" << endl;
                else
                {
                    cout << "\n[ ";
                    for (unsigned i {0}; i < data.size(); ++i)
                    {
                        cout << data[i] << " ";
                    }
                    cout << "]" << endl;
                }
                break;
            }
            case 'C':
            case 'c':
                data.clear();
                break;
            case 'A':
            case 'a':
            {
                double new_number {}; 
                cout << "\nEnter new number: ";
                cin >> new_number;
                data.push_back(new_number);
                break;
            }
            case 'M':
            case 'm':
            {
                if (data.size() == 0) cout << "\nThere is no data to calculate the mean value!" << endl;
                else
                {
                    double mean_value {};
                    double sum {};
                    for (unsigned i {0}; i < data.size(); ++i)
                    {
                        sum += data[i];
                    }
                    mean_value = sum / data.size();
                    cout << "\nThe mean value is : " << mean_value << endl;
                }
                break;
            }
            case 'S':
            case 's':
            {
                if (data.size() == 0) cout << "\nThere is no data to show the smallest number!" << endl;
                else
                {
                    double smallest = data[0];
                    for (unsigned i {1}; i < data.size(); ++i)
                    {
                        if (data[i] < smallest) smallest = data[i];
                    }
                    cout << "\nThe smallest value is : " << smallest << endl;
                }
                break;
            }
            case 'L':
            case 'l':
            {
                if (data.size() == 0) cout << "\nThere is no data to show the largest number!" << endl;
                else
                {
                    double largest = data[0];
                    for (unsigned i {1}; i < data.size(); ++i)
                    {
                        if (data[i] > largest) largest = data[i];
                    }
                    cout << "\nThe largest value is : " << largest << endl;
                }
                break;
            }
            case 'Q':
            case 'q':
            {
                cout << "\nGoodbye..." << endl;
                isExit = true;
                break;
            }
            default:
                cout << "\nIncorrect input. Please try again." << endl;
        }
    }
    
    cout << endl;
    return 0;
}