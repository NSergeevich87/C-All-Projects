/** Многоквартирный дом

Что нужно сделать:
На вход программе поступают десять фамилий в формате строк. Это фамилии жильцов квартир с первой по десятую. 
Необходимо прочитать эти фамилии и записать в одномерный массив. Далее пользователь вводит три номера 
квартир. Необходимо вывести в консоль фамилию жильца, проживающего в этой квартире. Если пользователь введёт 
некорректный номер квартиры, необходимо сообщить ему об этом.

Пример:

← SidorovA
← IvanovA
← PetrovA
← SidorovB
← IvanovB
← PetrovB
← SidorovC
← IvanovC
← PetrovC
← SidorovD
←10
→SidorovD
←1
→SidorovA
←5
→IvanovB

Что оценивается:
• Используется массив строк для хранения данных.
• В коде не используются библиотеки, кроме <iostream> и <string>.
• Программа проверяет доступность элемента по индексу и выдаёт корректный результат.*/

#include <iostream>
#include <string>

using namespace std;

class task_1
{
    public:
        void run()
        {
            string surnames[10];
            for (int i = 0; i < 10; i++)
            {
                cout << "Enter surname: ";
                getline(cin, surnames[i]);
            }

            int flat_number;
            cout << "Enter flat number: ";
            cin >> flat_number;
            cin.ignore(32767, '\n');

            if (flat_number < 1 || flat_number > 10)
            {
                cout << "Incorrect flat number!" << endl;
                return;
            }

            cout << surnames[flat_number - 1] << endl;
        }
};