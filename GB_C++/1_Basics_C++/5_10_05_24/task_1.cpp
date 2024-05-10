/** Координатная плоскость.
Напишите программу, которая принимает на вход координаты X, Y некоторой точки на плоскости и отвечает, 
в какой четверти плоскости лежит эта точка (а если она лежит на границе двух четвертей — то так и отвечает 
“на границе”). Напомним, что четверти на плоскости нумеруются так: первая четверть — если обе координаты 
положительны, вторая — если X отрицателен, а Y положителен, третья — если обе координаты отрицательны, 
четвертая — если X положителен, а Y отрицателен. Точка лежит на границе четвертей, 
если хотя бы какая-то из ее координат равна нулю.*/

#include <iostream>

using namespace std;

class task_1
{
    public:
        void run()
        {
            int x, y;
            cout << "Enter X: ";
            cin >> x;
            cout << "Enter Y: ";
            cin >> y;

            if (x > 0 && y > 0)
            {
                cout << "The point is in the first quarter" << endl;
            }
            else if (x < 0 && y > 0)
            {
                cout << "The point is in the second quarter" << endl;
            }
            else if (x < 0 && y < 0)
            {
                cout << "The point is in the third quarter" << endl;
            }
            else if (x > 0 && y < 0)
            {
                cout << "The point is in the fourth quarter" << endl;
            }
            else
            {
                cout << "The point is on the border of the quarters" << endl;
            }

            cin.ignore(32767, '\n');
        }
};