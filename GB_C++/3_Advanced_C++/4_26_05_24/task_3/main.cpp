/** Задание 3. Анаграммы
Что нужно сделать
Напишите функцию, которая принимает две строки и возвращает true, если первая строка является 
анаграммой второй (то есть можно получить первую строку из второй путём перестановки букв местами), 
и false иначе. Для достижения хорошей асимптотики решения рекомендуется использовать std::map.
Пример анаграммы: лекарство — стекловар

Чек-лист для проверки задачи
• Функция принимает корректные типы данных, тип возвращаемого значения — bool.
• Функция не использует библиотек, кроме <iostream>, <map>, <string>.
• Функция корректно определяет, являются ли строки анаграммами.*/

#include <iostream>
#include <map>
#include <string>

bool isAnagram(const std::string& str1, const std::string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    std::map<char, int> map1;
    std::map<char, int> map2;
    for (const auto& ch : str1) {
        map1[ch]++;
    }
    for (const auto& ch : str2) {
        map2[ch]++;
    }
    return map1 == map2;
}

int main() {
    std::string str1;
    std::string str2;
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);
    if (isAnagram(str1, str2)) {
        std::cout << "The strings are anagrams" << std::endl;
    } else {
        std::cout << "The strings are not anagrams" << std::endl;
    }
    return 0;
}