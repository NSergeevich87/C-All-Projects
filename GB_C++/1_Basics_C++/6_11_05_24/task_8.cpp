/** Кадастровые проблемы.

В столице программистов на квадратные участки дается скидка. 
А так как работать с целыми числами программисты начинают раньше, то и участки, 
площадь которых является точным квадратом (например, 25 или 49), являются самыми востребованными. 
Напишите программу, которая проверяет, является ли введенная площадь участка точным квадратом. 
Самый большой участок в городе имеет площадь в 1 000 000 м2.*/

#include <iostream>
#include <cmath>

using namespace std;

class task_8
{
    public:
        void run()
        {
            int s;
            cout << "Enter square of the plot: ";
            cin >> s;
            try
            {
                if (s < 0 || s > 1000000)
                {
                    throw std::invalid_argument("The square of the plot must be in the range from 0 to 1 000 000.");
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            int a = sqrt(s);
            if (a * a == s)
            {
                cout << "The plot is a square." << endl;
            }
            else
            {
                cout << "The plot is not a square." << endl;
            }

            cin.ignore(32767, '\n');
        }
};