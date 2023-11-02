//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

int main()
{
    bool Stop {false};
    while (!Stop)
    {
        cout << "Your message heare..." << endl;
        
        //for (int i {100}; i > 0; --i)
            //cout << i << endl;
        //for (int i {1}, j {5}; i < 11; ++i, ++j)
            //cout << i << " + " << j << " = " << i + j << endl;
        /*for (int i {1}; i <= 100; ++i)
        {
            cout << i;
            cout << ((i % 10 == 0) ? "\n" : " ");
        }*/
         vector<int> numbers { 10, 20, 30, 40, 50 };
         for (unsigned i {0}; i < numbers.size(); ++i)
             cout << numbers[i] << endl;
        
        cout << "For exit press 'Y': ";
        char answer {};
        cin >> answer;
        switch (answer)
        {
            case 'y':
            case 'Y':
                Stop = true;
                break;
        }
    }
    
    cout << endl;
    return 0;
}