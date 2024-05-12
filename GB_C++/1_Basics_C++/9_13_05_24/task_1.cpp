/** Напишите программу, которая принимает от пользователя текст (то есть некоторую строку) 
 * и ещё слово (то есть ещё строку) и подсчитывает, сколько раз слово встречается в тексте. 
 * Более точно: сколько в данном тексте существует позиций, начиная с которых можно прочитать данное слово.

Пример ввода:
mama myla ramu
my
Ответ: 1.
Пример ввода:
abudabudabdab
dab
Ответ: 3.*/

#include <iostream>
#include <string>

using namespace std;

class task_1
{
    public:
        void run()
        {
            string text;
            string word;
            cout << "Enter text: ";
            getline(cin, text);
            cout << "Enter word: ";
            getline(cin, word);

            int count = 0;
            size_t pos = 0;
            while ((pos = text.find(word, pos)) != string::npos)
            {
                pos += word.length();
                count++;
            }

            cout << "Answer: " << count << endl;
        }
};