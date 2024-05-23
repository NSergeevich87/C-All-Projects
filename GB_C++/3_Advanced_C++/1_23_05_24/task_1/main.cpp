/** Задание 1. Разработка программы поиска слов в файле
Что нужно сделать
Составьте небольшой текстовый файл «words.txt», в котором последовательно, через пробелы и переносы строк 
расположены различные слова. Можете использовать любые англоязычные слова. Разработайте программу, которая 
искала бы среди этих слов нужное пользователю и выводила бы общее количество повторений этого слова. 
0 — если слово вообще не присутствует в файле.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("words.txt");
    if (!file.is_open()) {
        std::cerr << "File not found\n";
        return 1;
    }

    std::string word;
    std::cout << "Enter the word you are looking for: ";
    std::cin >> word;

    std::string temp;
    std::vector<std::string> words;
    while (!file.eof()) {
        file >> temp;
        words.push_back(temp);
    }

    int count = 0;
    for (const auto& w : words) {
        if (w == word) {
            count++;
        }
    }

    std::cout << "The word \"" << word << "\" is found " << count << " times\n";

    file.close();

    return 0;
}