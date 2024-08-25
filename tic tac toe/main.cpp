#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    Game game;
    while (true) {
        game.print();
        cout << "Enter row and column: ";
        int row, col;
        cin >> row >> col;
        if (row < 0 || row >= Game::SIZE || col < 0 || col >= Game::SIZE) {
            cout << "Invalid row or column" << endl;
            continue;
        }
        if (game.field[row][col] != Game::EMPTY) {
            cout << "Cell is not empty" << endl;
            continue;
        }
        game.field[row][col] = game.currentPlayer;
        if (game.checkWin(game.currentPlayer)) {
            game.print();
            cout << "Player " << game.currentPlayer << " wins!" << endl;
            break;
        }
        game.currentPlayer = (game.currentPlayer == Game::CROSS) ? Game::ZERO : Game::CROSS;
    }
    return 0;
}