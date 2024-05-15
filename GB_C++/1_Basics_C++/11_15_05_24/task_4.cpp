/** Оценка результатов игры в крестики-нолики
Что нужно сделать
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь перед вами табличка 3 × 3, 
которая осталась после их поединка. Вы хотите понять, выиграл ли кто-то из них или они не доиграли.
На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля. 
Крестик обозначается символом X (английская заглавная буква X), нолик — символом O 
(заглавная английская буква O), пустая клетка — точкой.
Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, 
то надо написать в ответ слово Incorrect.
Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, 
если нолики — Vanya won, иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.

X..
OXO
OOO

X..
.X.
OO.

XXO
OOX
XOX

XO.
XO.
X.O

OX.
XOX
X.O

..X
OX.
X.O

0..
...
...*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class task_4
{
    public:
        void run()
        {
            vector<string> game_1 = {"X..", "OXO", "OOO"};
            vector<string> game_2 = {"X..", ".X.", "OO."};
            vector<string> game_3 = {"XXO", "OOX", "XOX"};
            vector<string> game_4 = {"XO.", "XO.", "X.O"};
            vector<string> game_5 = {"OX.", "XOX", "X.O"};
            vector<string> game_6 = {"..X", "OX.", "X.O"};
            vector<string> game_7 = {"0..", "...", "..."};

            cout << "Game 1: " << check_game(game_1) << endl;
            cout << "Game 2: " << check_game(game_2) << endl;
            cout << "Game 3: " << check_game(game_3) << endl;
            cout << "Game 4: " << check_game(game_4) << endl;
            cout << "Game 5: " << check_game(game_5) << endl;
            cout << "Game 6: " << check_game(game_6) << endl;
            cout << "Game 7: " << check_game(game_7) << endl;
        }

        string check_game(vector<string> game)
        {
            int x_count = 0;
            int o_count = 0;

            for (auto i : game)
            {
                for (auto j : i)
                {
                    if (x_count > 5 || o_count > 5)
                    {
                        return "Incorrect";
                    }
                    
                    if (j != 'X' && j != 'O' && j != '.')
                    {
                        return "Incorrect";
                    }

                    if (j == 'X')
                    {
                        x_count++;
                    }
                    else if (j == 'O')
                    {
                        o_count++;
                    }
                }
            }

            if (x_count < o_count || x_count > o_count + 1)
            {
                return "Incorrect";
            }

            if (check_winner(game, 'X'))
            {
                return "Petya won";
            }

            if (check_winner(game, 'O'))
            {
                return "Vanya won";
            }

            return "Nobody";
        }

        bool check_winner(vector<string> game, char player)
        {
            for (int i = 0; i < 3; i++)
            {
                if (game[i][0] == player && game[i][1] == player && game[i][2] == player)
                {
                    return true;
                }

                if (game[0][i] == player && game[1][i] == player && game[2][i] == player)
                {
                    return true;
                }
            }

            if (game[0][0] == player && game[1][1] == player && game[2][2] == player)
            {
                return true;
            }

            if (game[0][2] == player && game[1][1] == player && game[2][0] == player)
            {
                return true;
            }

            return false;
        }
};