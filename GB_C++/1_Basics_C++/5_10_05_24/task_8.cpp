/** Входит... И выходит... И входит... Замечательно выходит! "Винни-Пух и день забот".
У Винни-Пуха есть кирпич размера A на B на C. А еще есть стена, в которой проделано прямоугольное 
отверстие размера X на Y. Прежде чем подарить все это ослику Иа, Винни-Пух хочет знать, 
получится ли просунуть этот кирпич в это отверстие? Напишите программу, которая по данным пяти числам 
отвечает на этот вопрос. Разумеется, кирпич можно поворачивать.*/

#include <iostream>

using namespace std;

class task_8
{
    public:
        void run()
        {
            int a, b, c, x, y;
            cout << "Enter the size of the brick: ";
            cin >> a >> b >> c;
            cout << "Enter the size of the hole: ";
            cin >> x >> y;
            
            if ((a <= x && b <= y) || (a <= y && b <= x) || (a <= x && c <= y) || (a <= y && c <= x) || (b <= x && c <= y) || (b <= y && c <= x))
            {
                cout << "The brick will pass through the hole\n";
            }
            else
            {
                cout << "The brick will not pass through the hole\n";
            }

            cin.ignore(32767, '\n');
        }
};