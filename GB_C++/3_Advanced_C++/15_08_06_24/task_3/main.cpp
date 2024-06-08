/** Задание 3. Реестр данных на шаблонах
Что нужно сделать
С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные типы значений 
по ключам произвольного типа. Ключи при этом могут повторяться.
Реестр должен поддерживать следующие операции: добавление элемента с ключом, удаление элементов 
с заданным ключом, вывод всех значений с ключами в консоль, поиск элементов по ключу.
Для тестирования программы предусмотрите ввод данных и команд из стандартной консоли:
• add — добавить элемент с ключом;
• remove — удалить все элементы с заданным ключом;
• print — напечатать на экране все элементы с их ключами;
• find — найти все элементы по их ключу.
Данный словарь должен работать на значениях и ключах следующих типов: int, double, std::string.

Рекомендации
• Для реализации можете использовать стандартный шаблон std::vector, который в свою очередь 
уже будет хранить ваши пары ключей и значений.
• Сама пара ключа и значения как раз и будет классом (или струкурой), шаблонизированным двумя типами: 
типом значения и типом ключа.
• При желании вы можете создать отдельную шаблонизированную функцию с вводом команд и их данных. */

#include <iostream>
#include <vector>
#include <string>

template <typename T, typename K>
class Registry
{
private:
    std::vector<std::pair<K, T>> data;
    
public:
    void add(const K &key, const T &value)
    {
        data.push_back(std::make_pair(key, value));
    }

    void remove(const K &key)
    {
        for (auto it = data.begin(); it != data.end();)
        {
            if (it->first == key)
            {
                it = data.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void print()
    {
        for (const auto &item : data)
        {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }

    void find(const K &key)
    {
        for (const auto &item : data)
        {
            if (item.first == key)
            {
                std::cout << item.first << " " << item.second << std::endl;
            }
        }
    }
};

int main()
{
    Registry<int, std::string> reg;
    std::string command;
    while (true)
    {
        std::cout << "Enter command (add, remove, print, find): ";
        std::cin >> command;
        if (command == "add")
        {
            std::string key;
            int value;
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter value: ";
            std::cin >> value;
            reg.add(key, value);
        }
        else if (command == "remove")
        {
            std::string key;
            std::cout << "Enter key: ";
            std::cin >> key;
            reg.remove(key);
        }
        else if (command == "print")
        {
            reg.print();
        }
        else if (command == "find")
        {
            std::string key;
            std::cout << "Enter key: ";
            std::cin >> key;
            reg.find(key);
        }
    }
    return 0;
}