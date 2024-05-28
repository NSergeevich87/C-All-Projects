/** Задание 2. Реализация программы напоминания о днях рождения
Что нужно сделать
Реализуйте простую программу по вычислению ближайшего дня рождения.
В начале программы пользователь последовательно вводит данные о днях рождения своих друзей: 
вводит имя друга и саму дату рождения полностью, включая месяц и год, в формате год/месяц/день. 
Сигналом окончания ввода дней рождения является “end” введённое в качестве имени.
После этого программа вычисляет ближайший день рождения по отношению к текущему времени и выводит 
его на экран вместе с именем в удобном, локальном формате - месяц/день. Если день рождения уже 
был в этом году, данные о пользователе пропускаются. Если у кого-то из друзей день рождения сегодня, 
то в консоль выводится специальное сообщение об этом. Учтите, что таких сообщений может быть несколько, 
ведь сразу несколько людей могут иметь дни рождения в один день.

Советы и рекомендации
Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

// Структура для хранения дня рождения
struct Birthday
{
    std::string name;
    std::tm date;
};

// Функция для ввода дня рождения
Birthday inputBirthday()
{
    Birthday birthday;
    std::cout << "Enter name: ";
    std::cin >> birthday.name;
    std::cout << "Enter birthday (YYYY/MM/DD): ";
    std::cin >> std::get_time(&birthday.date, "%Y/%m/%d");
    return birthday;
}

// Функция для вывода дня рождения
void printBirthday(const Birthday& birthday)
{
    std::cout << "Name: " << birthday.name << std::endl;
    std::cout << "Birthday: " << std::put_time(&birthday.date, "%Y/%m/%d") << std::endl;
}

// Функция для вычисления ближайшего дня рождения
std::tm nextBirthday(const std::tm& today, const Birthday& birthday)
{
    std::tm next = birthday.date;
    next.tm_year = today.tm_year;
    if (std::mktime(const_cast<std::tm*>(&next)) < std::mktime(const_cast<std::tm*>(&today)))
    {
        next.tm_year += 1;
    }
    return next;
}

// Функция для сравнения дней рождения
bool compareBirthday(const Birthday& a, const Birthday& b)
{
    return std::mktime(const_cast<std::tm*>(&a.date)) < std::mktime(const_cast<std::tm*>(&b.date));
}

int main()
{
    std::vector<Birthday> birthdays;
    while (true)
    {
        Birthday birthday = inputBirthday();
        if (birthday.name == "end")
        {
            break;
        }
        birthdays.push_back(birthday);
    }

    std::time_t now = std::time(nullptr);
    std::tm today = *std::localtime(&now);

    std::sort(birthdays.begin(), birthdays.end(), compareBirthday);

    for (const Birthday& birthday : birthdays)
    {
        std::tm next = nextBirthday(today, birthday);
        if (next.tm_mon == today.tm_mon && next.tm_mday == today.tm_mday)
        {
            std::cout << "Today is " << birthday.name << "'s birthday!" << std::endl;
        }
        else
        {
            std::cout << "Next birthday for " << birthday.name << " is " << std::put_time(&next, "%m/%d") << std::endl;
        }
    }

    return 0;
}