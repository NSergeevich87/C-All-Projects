#include "Game.h"

Game::Game() {
    currentPlayer = CROSS;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            field[i][j] = EMPTY;
        }
    }
}

void Game::print() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            switch (field[i][j]) {
                case EMPTY:
                    cout << " ";
                    break;
                case CROSS:
                    cout << "X";
                    break;
                case ZERO:
                    cout << "O";
                    break;
            }
            if (j < SIZE - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE - 1; j++) {
                cout << "-";
            }
            cout << endl;
        }
    }
}

bool Game::checkWin(Cell player) {
    for (int i = 0; i < SIZE; i++) {
        int count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (field[i][j] == player) {
                count++;
            }
        }
        if (count == WIN) {
            return true;
        }
    }
    for (int j = 0; j < SIZE; j++) {
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            if (field[i][j] == player) {
                count++;
            }
        }
        if (count == WIN) {
            return true;
        }
    }
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (field[i][i] == player) {
            count++;
        }
    }
    if (count == WIN) {
        return true;
    }
    count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (field[i][SIZE - i - 1] == player) {
            count++;
        }
    }
    if (count == WIN) {
        return true;
    }
    return false;
}