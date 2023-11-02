//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);
#include <cstdlib> //required for rand()
#include <ctime>   //required for time()

using namespace std;

int main()
{
    char selection {};
    int random_number {};
    size_t count {10}; //сколько рандомных чисел будем создавать
    int min{1};
    int max{6}; //здесь указываем диапазон
    
    do 
    {
        cout << "==========================================" << endl;
        
        cout << "RAND_MAX on my system is: " << RAND_MAX << endl;
        srand(time(nullptr)); //это нужно для того, чтобы рандомные числа обновлялись
        for (size_t i{0}; i < count; ++i)
        {
            random_number = rand() % max + min; //generate a random number [min, max]
            cout << random_number << endl;
        }  
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}