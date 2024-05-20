/** Задача 4
Что нужно сделать:
Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо вывести его на экран 
отсортированным в порядке возрастания модуля чисел.
Пример:
Массив {-100,-50, -5, 1, 10, 15}
Вывод: 1, -5, 10, 15, -50, -100*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a = {-100, -50, -5, 1, 10, 15};

    // variant 1
    // sort(a.begin(), a.end(), [](int x, int y) { return abs(x) < abs(y); });
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }

    // variant 2
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (abs(a[i]) > abs(a[j]))
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}