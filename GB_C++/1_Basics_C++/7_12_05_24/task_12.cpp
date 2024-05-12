/** Рамка
Что нужно сделать
Напишите программу, которая рисует с помощью символьной графики прямоугольную рамку. 
Для вертикальных линий используйте символ вертикального штриха «|», а для горизонтальных — дефис «-». 
Пусть пользователь вводит ширину и высоту рамки.

Пример выполнения
6 — ширина, 4 — высота:

Рекомендации по выполнению
Ширину и высоту удобно вводить с помощью одной операции std::cin:

int width, height;
std::cin >> width >> height;

Что оценивается
Рамка рисуется в соответствии с заданными размерами и с помощью условных конструкций и циклов.*/

#include <iostream>
#include <string>

using namespace std;

class task_12
{
    public:
        void frame()
        {
            int width, height;
            cout << "Enter width and height of the frame: ";
            cin >> width >> height;
            cin.ignore(32767, '\n');
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (i == 0 || i == height - 1)
                    {
                        cout << "-";
                    }
                    else if (i > 0 && i < height - 1 && (j == 0 || j == width - 1))
                    {
                        cout << "|";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
};