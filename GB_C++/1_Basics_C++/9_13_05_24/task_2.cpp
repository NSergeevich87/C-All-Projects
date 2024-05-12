/** Напишите программу, которая проверяет, верно ли, что данная строка представляет из себя некоторую 
 * другую строку, повторённую несколько раз. Например, строка dabudabudabu — это трижды повторённая 
 * строка dabu. Строка kapkap — это дважды повторённая строка kap. А вот строку abdabdab или строку 
 * gogolmogol нельзя представить как повторение некоторой другой строки.
На вход программа должна принимать строку и выдавать ответ Yes, если строка является повторением 
некоторой другой строки, и No, если это не так.*/

#include <iostream>
#include <string>

using namespace std;

class task_2
{
    public:
        void run()
        {
            string text;
            cout << "Enter text: ";
            getline(cin, text);

            string result = "No";
            for (size_t i = 1; i < text.length(); i++)
            {
                string sub = text.substr(0, i);
                size_t pos = 0;
                while ((pos = text.find(sub, pos)) != string::npos)
                {
                    pos += sub.length();
                    if (pos == text.length())
                    {
                        result = "Yes";
                        break;
                    }
                }
            }

            cout << "Answer: " << result << endl;
        }
};