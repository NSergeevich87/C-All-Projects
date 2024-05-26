/** Задание 1. Телефонный справочник
Что нужно сделать
Напишите программу «Телефонный справочник».
На вход программе поступают запросы трёх типов:
69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
69-70-30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии
Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты по разным 
номерам могут иметь одинаковые фамилии. В таком случае на запрос 3 необходимо выдать все номера 
через пробелы.
Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией).

Чек-лист для проверки задачи
• Программа корректно выводит фамилии и списки номеров.  
• Программа использует только заголовочные файлы <iostream>, <string>, <map> и, возможно, вектор.*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map<string, vector<string>> phoneBook;
    string input;
    while (true)
    {
        cout << "Enter name or phone number or 'exit': ";
        cin >> input;
        
        if (input == "exit")
        {
            break;
        }
        else if (input.find('-') != string::npos)
        {
            string phone;
            string name;
            cout << "Enter name: ";
            cin >> name;
            phone = input;
            phoneBook[phone].push_back(name);
        }
        else if (input.find('-') == string::npos)
        {
            if (phoneBook.find(input) != phoneBook.end())
            {
                for (auto &i : phoneBook[input])
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            else
            {
                for (auto &i : phoneBook)
                {
                    for (auto &j : i.second)
                    {
                        if (j == input)
                        {
                            cout << i.first << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}