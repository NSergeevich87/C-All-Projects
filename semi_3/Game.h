#include <iostream>
using namespace std;

class Game {
public:
    static const int SIZE = 3;
    static const int WIN = 3;
    enum Cell {
        EMPTY = 0,
        CROSS = 1,
        ZERO = 2
    };
    Cell field[SIZE][SIZE];
    Cell currentPlayer;
    Game();
    void print();
    bool checkWin(Cell player);
};

