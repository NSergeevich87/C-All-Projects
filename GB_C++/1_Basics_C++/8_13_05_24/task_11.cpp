/** Убийца Photoshop
Вы разрабатываете новый крутой графический редактор. 
Один из инструментов редактора позволяет делать градиент — плавный переход между двумя точками разной яркости.
Яркость точки определяется целым числом от 0 до 255, где 0 — чёрный, 255 — белый, а всё, 
что между ними — оттенки серого.
Напишите код для расчёта яркости точки градиента между двумя заданными точками. 
Пользователь вводит яркость левой границы градиента, потом яркость правой границы и параметр: 
число от 0 до 1, которое означает интересующую нас точку. Например, если параметр равен 0.5, 
то искомая точка находится ровно посередине между левой и правой границами, если параметр равен 0, 
то искомая точка совпадает с левой границей, и, наконец, если параметр равен 1, 
то искомая точка совпадает с правой границей. Программа должна вывести число — яркость искомой точки. 
Обеспечьте контроль ввода.

Пример
Ввод:

Введите яркость левой границы градиента: 10.
Введите правую границу градиента: 255.
Введите положение точки между границами: 0.7.

Вывод:
Яркость точки: 181.5.*/

#include <iostream>
#include <string>

using namespace std;

class task_11
{
    public:
        void run()
        {
            cout << "Enter the brightness of the left gradient border: ";
            string left;
            getline(cin, left);
            int left_i = stoi(left);
            if (left_i < 0 || left_i > 255)
            {
                cout << "Invalid input." << endl;
                return;
            }

            cout << "Enter the brightness of the right gradient border: ";
            string right;
            getline(cin, right);
            int right_i = stoi(right);
            if (right_i < 0 || right_i > 255)
            {
                cout << "Invalid input." << endl;
                return;
            }

            cout << "Enter the position of the point between the borders: ";
            string position;
            getline(cin, position);
            double position_d = stod(position);
            if (position_d < 0 || position_d > 1)
            {
                cout << "Invalid input." << endl;
                return;
            }

            double brightness = left_i + (right_i - left_i) * position_d;
            cout << "Brightness of the point: " << brightness << "." << endl;
        }
};