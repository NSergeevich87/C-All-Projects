/** Задание 5. Реализация игры «Что? Где? Когда?»
Что нужно сделать
Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?».
Как происходит игра
В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет. 
Всего таких секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение) относительно 
текущего сектора на барабане. Исходя из этого офсета вычисляется новый активный сектор, который и будет 
играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий не игравший за ним. В начале всей 
игры стрелка установлена на первом секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла 
данного сектора. Вопрос показывается на экране.
После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью 
стандартного ввода. То, что он ввёл, сравнивается с ответом, который хранится во втором файле, 
ассоциированном с активным сектором. Данный файл должен содержать лишь одно слово-ответ.

Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит 
телезрителям.
Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого называется 
победитель и программа заканчивает работу.*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Sector
{
    string question;
    string answer;
};

int main()
{
    vector<Sector> sectors;
    for (int i = 1; i <= 13; i++)
    {
        string path = "D:\\C-All-Projects\\GB_C++\\3_Advanced_C++\\1_23_05_24\\task_5\\sector" + to_string(i) + ".txt";
        ifstream file(path);
        if (!file.is_open())
        {
            cout << "Error opening file " << path << endl;
            return 1;
        }

        Sector sector;
        getline(file, sector.question);

        getline(file, sector.answer);

        sectors.push_back(sector);
    }

    int activeSector = 0;
    int playerScore = 0;
    int audienceScore = 0;

    while (playerScore < 6 && audienceScore < 6)
    {
        cout << "Active sector: " << activeSector + 1 << endl;
        cout << "Question: " << sectors[activeSector].question << endl;

        string answer;
        cout << "Your answer: ";
        getline(cin, answer);

        if (answer == sectors[activeSector].answer)
        {
            cout << "Correct answer! You get 1 point!" << endl;
            playerScore++;
            cout << "Player score: " << playerScore << endl;
            cout << "Audience score: " << audienceScore << endl;
        }
        else
        {
            cout << "Wrong answer! Audience gets 1 point!" << endl;
            audienceScore++;
            cout << "Player score: " << playerScore << endl;
            cout << "Audience score: " << audienceScore << endl;
        }

        int offset = rand() % 13;
        activeSector = (activeSector + offset) % 13;
    }

    if (playerScore == 6)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "Audience wins!" << endl;
    }

    return 0;
}

