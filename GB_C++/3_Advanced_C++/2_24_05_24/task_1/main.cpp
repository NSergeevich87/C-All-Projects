/** Задание 1. Реализация записи в ведомость учёта
Что нужно сделать
В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. 
Теперь требуется создать простую программу записи в эту ведомость.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее располагается 
дата выдачи в формате ДД.ММ.ГГГГ. Завершает запись сумма выплаты в рублях. Данные разделяются между 
собой пробелами. В конце каждой записи должен быть расположен перевод строки.
При старте программы пользователь последовательно вводит данные для новой записи, которые записываются 
затем в файл в текстовом режиме. Программа должна добавлять новые записи в конец файла, не удаляя его 
текущее содержимое.
Советы и рекомендации
Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.
Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr с корректно 
указанным диапазоном символов в дате. К примеру, вызов std::stoi(date.substr(3, 2)) вычленит из строковой 
даты целочисленный месяц для последующего анализа.*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string first_name;
    std::string second_name;
    std::string date;
    std::string sum;

    std::string line;
    std::ofstream file("file.txt", std::ios::app);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    std::cout << "Enter name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter second name: ";
    std::getline(std::cin, second_name);

    std::cout << "Enter date: ";
    std::getline(std::cin, date);

    try
    {
        int day = std::stoi(date.substr(0, 2));
        int month = std::stoi(date.substr(3, 2));
        int year = std::stoi(date.substr(6, 4));
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error with date format\n";
        return 1;
    }
    
    std::cout << "Enter sum: ";
    std::getline(std::cin, sum);

    line = first_name + " " + second_name + " " + date + " " + sum + "\n";
    file << line;
    file.close();
    return 0;
}