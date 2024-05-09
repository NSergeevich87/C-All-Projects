/** Калькулятор опыта
Что нужно сделать:
Напишите программу, которая определяет уровень персонажа в компьютерной игре. 
Пользователь вводит число «очков опыта», а программа вычисляет уровень. 
Новый уровень даётся при достижении 1000, 2500, 5000 и так далее «очков опыта». 
Начальный уровень равен 1.
Программа должна выводить текущий уровень персонажа для любого количества очков.*/

#include <iostream>

using namespace std;

class task_8
{
    public:
        void run()
        {
            cout << "Enter experience points: ";
            int exp;
            cin >> exp;
            int level = 1;
            int expToNextLevel = 1000;
            while (exp >= expToNextLevel)
            {
                exp -= expToNextLevel;
                expToNextLevel *= 2;
                level++;
            }
            cout << "Current level: " << level << endl;
            cout << "Experience points for next level: " << expToNextLevel << endl;
            cout << "Total experience points: " << exp << endl;
            cin.ignore(32767, '\n');
        }
};