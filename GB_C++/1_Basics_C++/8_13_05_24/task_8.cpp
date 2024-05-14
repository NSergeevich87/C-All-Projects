/** Ход конём
В рамках разработки шахматного искусственного интеллекта стоит новая задача. 
По заданным вещественным координатам коня и второй точки программа должна определить, 
может ли конь ходить в эту точку. Используйте как можно меньше конструкций if и логических операторов. 
Обеспечьте контроль ввода.

Пример
Ввод:

Введите местоположение коня:
0.071;
0.118.
Введите местоположение точки на доске:
0.213;
0.068.

Вывод:

Конь в клетке (0, 1). Точка в клетке (2, 0).
Да, конь может ходить в эту точку.*/

#include <iostream>
#include <string>

using namespace std;

class task_8
{
    public:
        void run()
        {
            cout << "Enter knight location X: ";
            string location;
            getline(cin, location);
            float x = stof(location);
            cout << "Enter knight location Y: ";
            getline(cin, location);
            float y = stof(location);
            // шаг клетки шахматной доски 0.08
            int x1 = x / 0.08;
            int y1 = y / 0.08;
            cout << "Knight in cell (" << x1 << ", " << y1 << ")." << endl;
            string point;
            cout << "Enter point location X: ";
            getline(cin, point);
            float x2 = stof(point);
            cout << "Enter point location Y: ";
            getline(cin, point);
            float y2 = stof(point);
            int x3 = x2 / 0.08;
            int y3 = y2 / 0.08;
            cout << "Point in cell (" << x3 << ", " << y3 << ")." << endl;
            if (abs(x1 - x3) == 1 && abs(y1 - y3) == 2)
            {
                cout << "Yes, knight can move to this point." << endl;
            }
            else if (abs(x1 - x3) == 2 && abs(y1 - y3) == 1)
            {
                cout << "Yes, knight can move to this point." << endl;
            }
            else
            {
                cout << "No, knight can't move to this point." << endl;
            }
        }
};