//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector<char> chars{}; or vector<char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

int main()
{
    bool Stop {false};
    while (!Stop)
    {
        cout << fixed << setprecision(1);
        cout << boolalpha;
        
        cout << "Your message heare..." << endl;
        
        int scores[] { 10, 20, 30 };
        for (int score : scores)
            cout << score << " ";
            
        vector<double> temperature { 56.3, 23.7, 98.5, 86.8 };
        double total_temp {};
        double aver_temp {};
        for (auto temp : temperature)
            total_temp += temp;
            
        if (temperature.size() != 0)
            aver_temp = total_temp / temperature.size();
            
        cout << "\nTotal: " << total_temp << endl;
        cout << "Aver: " << aver_temp << endl;
        
        for (auto c : "This is the champion !")
            if (c == ' ') cout << '\t';
            else cout << c;
        
        cout << "\nFor exit press 'Y': ";
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