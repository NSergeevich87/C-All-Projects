/** Меню ресторана
Что нужно сделать:
Напишите программу, которая выводит меню бизнес-ланча ресторана в зависимости от дня недели. 
В меню есть общая часть, а есть уникальная, которая зависит от дня недели. 
Пользователь должен ввести номер дня недели — от 1 (понедельник) до 7 (воскресенье), 
а программа должна вывести на экран день недели и меню этого дня.*/

#include <iostream>

using namespace std;

class task_11
{
    public:
        void run()
        {
            cout << "Enter day of the week (1-7): ";
            int day;
            cin >> day;
            switch (day)
            {
                case 1:
                    cout << "Monday\n";
                    cout << "Menu: soup_1, salad_1, main_course_1, dessert_1, drink_1.\n";
                    break;
                case 2:
                    cout << "Tuesday\n";
                    cout << "Menu: soup_2, salad_2, main_course_2, dessert_2, drink_2.\n";
                    break;
                case 3:
                    cout << "Wednesday\n";
                    cout << "Menu: soup_3, salad_3, main_course_3, dessert_3, drink_3.\n";
                    break;
                case 4:
                    cout << "Thursday\n";
                    cout << "Menu: soup_4, salad_4, main_course_4, dessert_4, drink_4.\n";
                    break;
                case 5:
                    cout << "Friday\n";
                    cout << "Menu: soup_5, salad_5, main_course_5, dessert_5, drink_5.\n";
                    break;
                case 6:
                    cout << "Saturday\n";
                    cout << "Menu: soup_6, salad_6, main_course_6, dessert_6, drink_6.\n";
                    break;
                case 7:
                    cout << "Sunday\n";
                    cout << "Menu: soup_7, salad_7, main_course_7, dessert_7, drink_7.\n";
                    break;
                default:
                    cout << "Invalid day of the week.\n";
                    break;
            }
            cin.ignore(32767, '\n');
        }
};