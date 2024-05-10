/** Грустное совершеннолетие
Что нужно сделать
Напишите программу для бармена, который не умеет считать.

Условие:
Посетитель пришёл в бар и попросил кружку пива.
Напишите программу для бармена, который не умеет считать, чтобы по заданной дате рождения посетителя и 
текущей дате определить, можно ему продавать алкоголь или нет.
Программа должна попросить ввести сегодняшнюю дату и дату рождения покупателя, после чего ответить: 
«можно» или «нельзя».
Учтите, что в день восемнадцатилетия алкоголь продавать посетителю ещё нельзя, а вот на следующий день 
после этого — уже можно.*/

#include <iostream>

class task_15
{
    public:
        void run()
        {
            int day, month, year, birth_day, birth_month, birth_year;
            std::cout << "Enter today's date (day month year): ";
            std::cin >> day >> month >> year;
            std::cout << "Enter the visitor's date of birth (day month year): ";
            std::cin >> birth_day >> birth_month >> birth_year;

            if (year - birth_year > 18 || 
                (year - birth_year == 18 && month > birth_month) || 
                (year - birth_year == 18 && month == birth_month && day > birth_day))
            {
                std::cout << "You can sell alcohol\n";
            }
            else
            {
                std::cout << "You can't sell alcohol\n";
            }

            std::cin.ignore(32767, '\n');
        }
};