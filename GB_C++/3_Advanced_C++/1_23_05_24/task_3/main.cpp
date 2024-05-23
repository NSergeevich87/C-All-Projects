/** Задание 3. Реализация программы чтения ведомости
Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой 
следующую таблицу:
• имя и фамилия человека;
• количество денег, которые были выплачены лицу;
• дата выплаты в формате ДД.ММ.ГГГГ.

На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить 
человека с максимальной суммой выплат.
Пример данных ведомости

Tom Hanks 35500 10.11.2020
Rebecca Williams 85000 1.1.2021
Sally Field 15600 15.8.2021
Michael Humphreys 29400 23.5.2020
Harold Herthum 74300 9.6.2019
George Kelly 45000 12.3.2018
Bob Penny 12500 13.5.2020
John Randall 23400 2.10.2020
Sam Anderson 6500 15.7.2020
Margo Moorer 12350 24.2.2019*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Paiment
{
    private:
        string name;
        string surname;
        int paiment;
        string date;

    public:
        Paiment(string name_val, string surname_val, int paiment_val, string date_val) :
            name(name_val), surname(surname_val), paiment(paiment_val), date(date_val) {}

        int getPaiment() { return paiment; }
        string getName() { return name; }
        string getSurname() { return surname; }
};

Paiment createObject(string line, char delimiter = ' ')
{
    size_t pos = 0;
    string token;
    vector<string> tokens;
    while ((pos = line.find(delimiter)) != string::npos)
    {
        token = line.substr(0, pos);
        tokens.push_back(token);
        line.erase(0, pos + 1);
    }
    tokens.push_back(line);

    string name = tokens[0];
    string surname = tokens[1];
    int paiment = stoi(tokens[2]);
    string date = tokens[3];

    return Paiment(name, surname, paiment, date);
}

void getSummary(vector<Paiment> paiments)
{
    int total = 0;
    int maxPaiment = 0;
    string maxName;
    string maxSurname;
    for (auto paiment : paiments)
    {
        total += paiment.getPaiment();
        if (paiment.getPaiment() > maxPaiment)
        {
            maxPaiment = paiment.getPaiment();
            maxName = paiment.getName();
            maxSurname = paiment.getSurname();
        }
    }

    cout << "Total paiments: " << total << endl;
    cout << "Max paiment: " << maxName << " " << maxSurname << " " << maxPaiment << endl;
}

int main()
{
    ifstream file("D:\\C-All-Projects\\GB_C++\\3_Advanced_C++\\1_23_05_24\\task_3\\paiments.txt");
    if (!file.is_open())
    {
        cout << "File not found!" << endl;
        return 1;
    }

    vector<Paiment> paiments;
    while(!file.eof())
    {
        string line;
        getline(file, line);
        if (line.empty())
            continue;

        Paiment paiment = createObject(line);
        paiments.push_back(paiment);
    }

    getSummary(paiments);

    file.close();

    return 0;
}