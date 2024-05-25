/** Ведомость учёта
Что нужно сделать
Вы уже создавали программу чтения и записи ведомости. Теперь её нужно обобщить и дополнить использованием 
структур.
Формат ведомости прежний:
• сначала — имя и фамилия получателя денег,
• далее — дата выдачи в формате ДД.ММ.ГГГГ,
• затем — сумма выплаты в рублях.
Данные разделяются пробелами. В конце каждой записи должен быть перевод строки. Структура данных должна 
соответствовать этому формату.

При старте программы пользователь отправляет команду: list или add. Команда list осуществляет чтение из 
файла ведомости, как и прежде, только уже в структуры данных, и отображает их на экране.
Команда add добавляет новую запись в конец ведомости.

Советы и рекомендации
• Чтобы определить, где заканчивается файл, используйте функцию file.eof().
• Из-за завершающего переноса строки при чтении данных из файла стоит отдельно прочитать имя получателя 
денег. Если после чтения имени получателя денег признак file.eof() принял значение true, значит, 
файл закончился.
• Используйте вектор структур. Для выбора команды потребуется подобная конструкция:

if (command == "list")
{
…
}*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Record
{
    std::string first_name;
    std::string last_name;
    std::string date;
    double sum;
};

void addRecord(std::ofstream& file, Record& record)
{
    file << record.first_name << " " << record.last_name << " " << record.date << " " << record.sum << std::endl;
}

void listRecords(std::ifstream& file)
{
    std::vector<Record> records;
    Record record;
    while (file >> record.first_name >> record.last_name >> record.date >> record.sum)
    {
        records.push_back(record);
    }
    for (const auto& record : records)
    {
        std::cout << record.first_name << " " << record.last_name << " " << record.date << " " << record.sum << std::endl;
    }
}

int main()
{
    std::string command;
    std::cout << "Enter command: list or add\n";
    std::cin >> command;
    if (command == "list")
    {
        std::ifstream file("records.txt", std::ios::binary);

        if (!file.is_open())
        {
            std::cout << "File not found\n";
            return 1;
        }

        listRecords(file);
    }
    else if (command == "add")
    {
        std::ofstream file("records.txt", std::ios::binary | std::ios::app);

        if (!file.is_open())
        {
            std::cout << "File not found\n";
            return 1;
        }

        Record record;

        std::cout << "Enter first name, last name, date and sum\n";
        std::cin >> record.first_name >> record.last_name >> record.date >> record.sum;
        addRecord(file, record);
    }
    return 0;
}

