#include <iostream>
#include "Player.h"

using namespace std;

void display_players()
{
    cout << "Active players: " << Player::get_players_num() << endl;
}

int main()
{
    display_players();
    Player player1{"Nikita"};
    Player player2{"Kseniia"};
    display_players();
    
    {
        Player player3{"Daniil"};
        display_players();
    }
    
    display_players();
    
    Player *enemy = new Player("Super", 100, 100);
    display_players();
    delete enemy;
    display_players();
    
    cout << endl;
    return 0;
}