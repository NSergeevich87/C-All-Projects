#include "start_game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

void Game::start() {
    srand(time(0));
    int matches = rand() % 100 + 1;
    std::cout << "Matches: " << matches << std::endl;
    int player = 1;
    while (matches > 0) {
        int take = rand() % 3 + 1;
        std::cout << "Player " << player << " takes " << take << " matches" << std::endl;
        matches -= take;
        if (matches <= 0) {
            std::cout << "Player " << player << " wins!" << std::endl;
            break;
        }
        player = 3 - player;
    }
}