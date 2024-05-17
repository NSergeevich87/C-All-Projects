/** Ряд чисел* (дополнительное задание)

Что нужно сделать:
В программе инициализирован массив из 15 целых положительных чисел. 
Эти числа являются множеством из 14 последовательных чисел, начиная с Х (Х может быть любым), 
а одно число из ряда повторяется. Необходимо найти повторяющееся число и вывести его в консоль. 
По возможности используйте минимум дополнительной памяти и проходов по массиву.

Пример:

int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118}
В данном примере Х — это 105, а повторяющееся число — 108.


Рекомендации по выполнению
Это задание с подвохом. Подумайте, как его можно было бы легко решить за O(n). 
На всякий случай оставляем для вас подсказку. Рекомендуем воспользоваться при необходимости.*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class task_4
{
    public:
    void run()
    {
        int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
        //int numbers[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
        int sum = 0;

        sort(numbers, numbers + 15);
        int reference_sum = numbers[0];
        int compare_sum = 0;

        // каждое следующее чесло reference_sum увеличивается на 1, подсчитаем сумму для 15 чисел
        for (int i = 1; i < 15; i++)
        {
            reference_sum += 1;
            compare_sum += reference_sum;
            cout << compare_sum << " ";
        }
        cout << "Reference sum: " << reference_sum << endl;

        for (int i = 0; i < 15; i++)
        {
            cout << numbers[i] << " ";
            sum += numbers[i];
        }
        
        cout << "Sum: " << sum << endl;

        if (compare_sum == sum)
        {
            cout << "No repeating numbers" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < 15; i++)
            {
                if (numbers[i] == numbers[i + 1])
                {
                    cout << "Repeating number: " << numbers[i] << endl;
                    break;
                }
            }
        }
    }
};