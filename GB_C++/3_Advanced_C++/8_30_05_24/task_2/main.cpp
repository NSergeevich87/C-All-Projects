/** Задание 2. Реализация программы симуляции мобильного телефона
Что нужно сделать
Реализуйте программу простой симуляции работы мобильного телефона.
По мобильному телефону можно звонить и отправлять СМС. Также мобильный телефон содержит адресную книгу. 
Телефон и отдельные записи адресной книги должны быть реализованы с помощью классов. Все номера 
телефонов задаются в формате +7 <10 цифр>.

Пользователь взаимодействует с программой с помощью команд:

• Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта. 
Оба эти параметра команда получает от пользователя через стандартный ввод.
• Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить. 
Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который 
осуществляется вызов.
• Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который требуется послать 
сообщение. Само сообщение также вводится через стандартный ввод.
• Команда exit — выход из программы.*/

#include "headers/Phone.h"
#include "headers/PhoneBook.h"

#include <iostream>
#include <string>

int main()
{
    PhoneBook phoneBook;
    Phone phone;

    std::string command;
    while (true)
    {
        std::cout << "Enter command (add, call, sms, exit): ";
        std::cin >> command;
        if (command == "add")
        {
            std::string name, phone;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter phone: ";
            std::cin >> phone;
            phoneBook.add(name, phone);
        }
        else if (command == "call")
        {
            std::string name;
            std::cout << "Enter name: ";
            std::cin >> name;
            phone.call(phoneBook.getNumber(name));
        }
        else if (command == "sms")
        {
            std::string name, message;
            std::cout << "Enter name: ";
            std::cin >> name;
            // Clear the input buffer
            std::cin.ignore();
            std::cout << "Enter message: ";
            getline(std::cin, message);
            phone.sendSMS(phoneBook.getNumber(name), message);
        }
        else if (command == "exit")
        {
            break;
        }
    }

    return 0;
}