/** Задание 3. Реализация программы таймера
Что нужно сделать
Реализуйте работу точного таймера с визуальной отдачей.
В начале программы пользователь вводит количество минут и секунд, которые требуется засечь на таймере, 
и нажимает «Ввод».
После этого начинается обратный отсчёт времени, о чём незамедлительно и последовательно сообщается 
пользователю. Формат вывода такой же, как и при вводе интервала: минуты и секунды.
Как только отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль специального 
сообщения. Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!
Советы и рекомендации
Для ввода значения для засекания времени используйте std::get_time, но в качестве формата запросите 
только минуты и секунды. Целевое время для остановки таймера вычислите сами с помощью манипуляции 
над текущим std::time. Количество оставшегося времени выводите в цикле и вычислите его самостоятельно 
с помощью обращения с типом std::time_t как с секундами.*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>

// Функция для ввода времени
std::tm inputTime()
{
    std::tm time;
    std::cout << "Enter time (MM:SS): ";
    std::cin >> std::get_time(&time, "%M:%S");
    return time;
}

// Функция для вывода времени
void printTime(const std::tm& time)
{
    std::cout << "Time: " << std::put_time(&time, "%M:%S") << std::endl;
}

// Функция для вычисления времени
std::time_t calculateTime(const std::tm& time)
{
    return time.tm_min * 60 + time.tm_sec;
}

int main()
{
    // Ввод времени
    std::tm time = inputTime();
    std::time_t seconds = calculateTime(time);

    // Отсчёт времени
    while (seconds > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --seconds;
        time.tm_min = seconds / 60;
        time.tm_sec = seconds % 60;
        printTime(time);
    }

    // Сообщение об окончании времени
    std::cout << "DING! DING! DING!" << std::endl;

    return 0;
}