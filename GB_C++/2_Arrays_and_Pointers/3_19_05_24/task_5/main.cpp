/** Задание 5. Пупырка
После посылки из Китая осталась спецплёнка для бережной перевозки груза — пупырка. Всего в пупырке 12 на 12 
шариков-пузырьков. Состояние любого пузырька: он либо целый, либо нет, то есть true или false 
(тип массива — bool). Для начала требуется реализовать отдельную функцию инициализации пупырки начальным 
состоянием: полностью целая пупырка, все элементы true.
Программа заключается в последовательном лопании целых регионов пузырьков. Перед каждым таким лопанием надо 
показывать пользователю полностью всю плёнку: o — это целый пузырёк, x — лопнутый. Это тоже надо выделить в 
отдельную функцию. Итак, как выглядит само лопание. Пользователь вводит две координаты: начала региона и 
конца региона. Процедура лопания пузырей должна быть реализована с помощью отдельной функции, все аргументы 
должны проверяться на валидность, что они в в рамках диапазона возможных значений, иначе должна быть 
выведена ошибка. После лопания каждого пузыря, который не был ещё лопнут до того, в консоль должно 
выводиться сообщение “Pop!”.
Лопание должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа заканчивает 
выполнение. Вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки, так как функция 
выполняется после каждого лопания.*/

#include <iostream>

using namespace std;

void printBubbleWrap(bool bubbleWrap[12][12])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (bubbleWrap[i][j] == true)
            {
                cout << "o ";
            }
            else
            {
                cout << "x ";
            }
        }
        cout << endl;
    }
}
bool checkBubbleWrap(bool bubbleWrap[12][12])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (bubbleWrap[i][j] == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    bool bubbleWrap[12][12] = {0};
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            bubbleWrap[i][j] = true;
        }
    }

    printBubbleWrap(bubbleWrap);

    while (checkBubbleWrap(bubbleWrap))
    {
        cout << "Enter the coordinates of the region to burst the bubbles: ";
        int x, y;
        cin >> x >> y;

        if (x < 0 || x > 11 || y < 0 || y > 11)
        {
            cout << "Error: invalid coordinates!" << endl;
            return 1;
        }

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                if (i == x && j == y)
                {
                    if (bubbleWrap[i][j] == true)
                    {
                        bubbleWrap[i][j] = false;
                        cout << "Pop!" << endl;
                    }
                    else
                    {
                        cout << "The bubble is already burst!" << endl;
                    }
                }
            }
        }

        printBubbleWrap(bubbleWrap);
    }

    cout << "All bubbles are burst!" << endl;

    return 0;
}