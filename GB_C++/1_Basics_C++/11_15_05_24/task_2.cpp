/** Проверка корректности email-адреса
Что нужно сделать
Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.
Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых 
знаком @. Первая часть должна иметь длину не менее одного и не более 64 символов, 
вторая часть — не менее одного и не более 63 символов. 
Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. 
Точка не может быть первым или последним символом, а кроме того, две точки не могут идти подряд. 
В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:
!#$%&'*+-/=?^_{|}~`
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, 
а в противном случае — слово No.
Примеры
Корректные адреса:
simple@example.com
very.common@example.com
disposable.style.email.with+symbol@example.com
other.email-with-hyphen@example.com
fully-qualified-domain@example.com
user.name+tag+sorting@example.com (может на самом деле быть перенаправлен на user.name@example.com 
в зависимости от почтового сервиса)
x@example.com (однобуквенная локальная часть)
example-indeed@strange-example.com
admin@mailserver1
example@s.example
mailhost!username@example.org
user%example.com@example.org
Некорректные адреса:
John..Doe@example.com (две точки не могут идти подряд)
Abc.example.com (нет символа @)
A@b@c@example.com (символ @ должен быть только один)
a"b(c)d,e:f;g<h>i[j\k]l@example.com (есть недопустимые символы)
1234567890123456789012345678901234567890123456789012345678901234+x@example.com 
(первая часть длиннее 64 символов)

Рекомендации
• Активно используйте оператор индексации строки str[i], но помните, что индексы начинаются с нуля, 
а не с единицы.
• Создайте отдельные функции, которые выдают первую и вторую части адреса для их последующего анализа.
• Для валидации отдельных символов внутри части используйте дополнительные строки-словари, состоящие 
из всех корректных символов для соответствующей части.
При разработке вспомогательных функций получения первой и второй части адреса воспользуйтесь циклом, 
который проверяет текущий символ.
• Если символ равен ‘@’, значит мы нашли границу между частями адреса. В функции нахождения первой 
части в этом месте надо остановиться и вернуть все символы, что были раньше 
(их можно накапливать в std::string при помощи оператора +=). Во второй функции все символы после ‘@’ 
тем же оператором добавляются к результату.
• Строка-словарь — это строка, которая в нашем случае содержит весь английский алфавит и символы. 
Каждый символ адреса надо сравнить с каждым символом из этого списка «допустимых символов» в цикле.
В этом задании очень важно разбить код на отдельные функции, каждая из которых делает небольшую часть работы. */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class task_2
{
    public:
        static void run()
        {
            vector<string> emails = {
                "simple@example.com",
                "very.common@example.com",
                "disposable.style.email.with+symbol@example.com",
                "other.email-with-hyphen@example.com",
                "fully-qualified-domain@example.com",
                "user.name+tag+sorting@example.com",
                "x@example.com",
                "example-indeed@strange-example.com",
                "admin@mailserver1",
                "example@s.example",
                "mailhost!username@example.org",
                "user%example.com@example.org",
                //Некорректные адреса:
                "John..Doe@example.com",
                "Abc.example.com",
                "A@b@c@example.com",
                "ab(c)d,e:f;g<h>i[jk]l@example.com",
                "1234567890123456789012345678901234567890123456789012345678901234+x@example.com"
            };

            for (auto email : emails)
            {
                if (is_correct_email(email))
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }

        static bool is_correct_email(string email_val)
        {
            cout << "Entered email: " << email_val << endl;

            string first_part = get_first_part(email_val);
            string second_part = get_second_part(email_val);

            if (first_part.size() < 1 || first_part.size() > 64)
            {
                return false;
            }

            if (second_part.size() < 1 || second_part.size() > 63)
            {
                return false;
            }

            return true;
        }

        static string get_first_part(string email_val)
        {
            string allowed_symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-/=?^_{|}~`";
            string wrong_symbols = "(),:;<>[]";
            string first_part = "";

            if (email_val.find('@') == string::npos)
            {
                cout << "No '@' symbol" << endl;
                return "";
            }

            first_part = email_val.substr(0, email_val.find('@'));

            cout << "First part: " << first_part << endl;

            if (first_part[0] == '.' || 
                first_part[first_part.size() - 1] == '.')
                {
                    cout << "Wrong symbols" << endl;
                    return "";
                } 

            for (int j = 0; j < wrong_symbols.size(); j++)
            {
                for (int i = 0; i < first_part.size(); i++)
                {
                    if (first_part[i] == '.' && first_part[i + 1] == '.' || first_part[0] == '.' || first_part[first_part.size() - 1] == '.')
                    {
                        cout << "Wrong symbols" << endl;
                        return "";
                    }

                    if (first_part[i] == wrong_symbols[j])
                    {
                        cout << "Wrong symbols" << endl;
                        return "";
                    }
                    // if (!allowed_symbols.find(first_part[i]) == string::npos)
                    // {
                    //     cout << "Wrong symbols after checking in allowed symbols" << endl;
                    //     return "";
                    // }
                }
            }
            

            return first_part;
        }

        static string get_second_part(string email_val)
        {
            if (email_val.find('@') == string::npos)
            {
                cout << "No '@' symbol" << endl;
                return "";
            }

            string second_part = email_val.substr(email_val.find('@') + 1, email_val.size());
            string allowed_symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-";


            cout << "Second part: " << second_part << endl;

            for (int i = 0; i < second_part.size(); i++)
            {
                if (second_part[i] == '.' && second_part[i + 1] == '.' || second_part[second_part.size() - 1] == '.' || second_part[i] == '@')
                {
                    cout << "Wrong symbols" << endl;
                    return "";
                }

                if (!allowed_symbols.find(second_part[i]) == string::npos)
                {
                    cout << "Wrong symbols after checking in allowed symbols" << endl;
                    return "";
                }
            }

            return second_part;
        }
};