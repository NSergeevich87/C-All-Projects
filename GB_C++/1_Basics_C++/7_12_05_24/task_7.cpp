/** Кадастровые проблемы (цикл for).
Перепишите программу из прошлого модуля, только теперь вместо цикла while используйте цикл for. 
В столице программистов на квадратные участки дается скидка. 
А так как работать с целыми числами программисты начинают раньше, то и участки, 
площадь которых является точным квадратом (например, 25 или 49), являются самыми востребованными. 
Напишите программу, которая проверяет, является ли введенная площадь участка точным квадратом. 
Самый большой участок в городе имеет площадь в 1 000 000 м2.*/

#include <iostream>
#include <string>

using namespace std;

class task_7
{
    public:
        void cadastre()
        {
            cout << "Enter the area of the plot: ";
            string area;
            getline(cin, area);

            int plot_area = 0;
            try
            {
                plot_area = stoi(area);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Wrong number!" << '\n';
            }

            if (plot_area > 1'000'000 || plot_area < 1)
            {
                cout << "The area of the plot is out of range!" << endl;
                return;
            }

            for (int i = 1; i <= 1000; i++)
            {
                if (i * i == plot_area)
                {
                    cout << "The area of the plot is a perfect square!" << endl;
                    return;
                }
            }

            cout << "The area of the plot is not a perfect square!" << endl;
        }
};