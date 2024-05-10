/** Майские — усложнение
Что нужно сделать
В предыдущем задании вы написали программу-календарь для мая. 
Теперь добавьте возможность начать месяц с любого дня недели.
Для этого нужно ввести число — номер дня недели, с которого начинается месяц. 
Убедитесь, что введённое число корректно.*/

#include <iostream>
#include <map>

class task_12
{
    public:
        void run()
        {
            std::map<int, std::string> weekDays = {
                {1, "Monday"},
                {2, "Tuesday"},
                {3, "Wednesday"},
                {4, "Thursday"},
                {5, "Friday"},
                {6, "Saturday"},
                {7, "Sunday"}
            };
            std::map<int, std::string> daysOfMay;

            int day;
            int is_weekend;
            std::cout << "Enter the day number of the week from which the month starts: ";
            std::cin >> day;
            std::cout << "Enter the day number of May to check is it the day of weekend: ";
            std::cin >> is_weekend;

            if (day >= 1 && day <= 7)
            {
                int dayNumber = 1;

                for (int i = 0; i < 31; i++)
                {
                    daysOfMay[i] = weekDays[day];
                    day == 7 ? day = 1 : day++;
                    dayNumber++;
                }

                for (auto day : daysOfMay)
                {
                    if (day.second == "Saturday" || day.second == "Sunday"
                        || (day.first >= 0 && day.first <= 4) || (day.first >= 7 && day.first <= 9))
                    {
                        if (day.first == is_weekend - 1)
                        {
                            std::cout << is_weekend << " day of May is: weekend\n";
                            break;
                        }
                        
                    }
                    else
                    {
                        if (day.first == 30)
                        {
                            std::cout << is_weekend << " day of May is: workday\n";
                        }
                    } 
                }
                std::cout << "\n";
                for (auto day : daysOfMay)
                {
                    if (day.second == "Saturday" || day.second == "Sunday"
                        || (day.first >= 0 && day.first <= 4) || (day.first >= 7 && day.first <= 9))
                    {
                        std::cout << day.first + 1 << " " << day.second << " - weekend\n";
                    }
                    else
                    {
                        std::cout << day.first + 1 << " " << day.second << " - workday\n";
                    } 
                }

                std::cout << "\n";
            }
            else
            {
                std::cout << "Incorrect day number\n";
            }

            std::cin.ignore(32767, '\n');
        }
};