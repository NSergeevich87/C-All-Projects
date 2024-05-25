/** Пошаговая ролевая игра (дополнительное задание)
Что нужно сделать
Реализуйте упрощённую версию пошаговой ролевой игры.
Действие разворачивается на карте размером 20 на 20 клеток. По клеткам перемещаются игрок и его противники.
После каждого хода игрока карта показывается вновь со всеми противниками на ней:
• игрок помечается буквой P,
• противники — буквой E,
• пустые места — точкой.
Каждый персонаж игры представлен в виде структуры с полями:
• «Имя»,
• «Жизни»,
• «Броня»,
• «Урон».
Сначала создаётся пять противников в случайных клетках карты:
• Имена противникам задаются в формате Enemy #N, где N — порядковый номер.
• Уровень жизни противников задаётся случайно — от 50 до 150.
• Уровень брони варьируется от 0 до 50.
• Урон тоже выбирается случайно — от 15 до 30 единиц.
Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя. 
Все персонажи появляются в случайных местах карты.
Игрок ходит с помощью команд: L, R, U, D (по первым буквам слов left, right, up, down). 
В зависимости от команды выбирается направление перемещения: влево, вправо, вверх, вниз.
Противники перемещаются в случайном направлении.
Если игрок перемещается в сторону, где уже кто-то находится, он наносит этому персонажу урон. 
Противники при этом никогда не бьют друг друга: они просто пропускают ход и остаются на своём месте. 
За пределы карты (20 на 20 клеток) ходить нельзя никому. Если кто-то выбрал направление за границами, 
ход пропускается.
Жизни уменьшаются на размер урона - показатель брони. 
При этом броня тоже сокращается на приведённый урон.
Игра заканчивается тогда, когда умирают либо все противники, либо игрок. В первом случае на экран 
выводится сообщение о победе, во втором — о поражении.
Если в начале хода игрок вводит команду save или load вместо направления перемещения, то игра либо 
сохраняет своё состояние в файл, либо загружает это состояние из файла.

Советы и рекомендации
• Для определения команды персонажа можно внутри структуры данных о нём завести флаг.
• Для отображения координат персонажей можно использовать структуру вектора.
• Для сохранения параметров игры и их загрузки можно работать с текстовыми данными. Однако записать 
всё в двоичном формате проще, главное — соблюдать последовательность полей:

std::ofstream file("save.bin", std::ios::binary);
for (int i = 0; i < 6; ++i) {
file.write((char*)&(characters[i].position),
sizeof(characters[i].position));
…

• При загрузке используйте ifstream и ту же последовательность полей.
• При сохранении и загрузке не забывайте про количество противников на поле и их параметры.
• Корректно работает сохранение и загрузка в игре.
• После загрузки все атрибуты игрока, включая имя, восстанавливаются из файла.
• Все игроки после загрузки появляются в местах, где они находились при сохранении.
• При ходе игрока не появляются новые противники.
• Перед загрузкой файла сохранения проверяется, есть ли он в операционной системе.*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Character
{
    std::string name;
    int health;
    int armor;
    int damage;
    int x;
    int y;
    bool isPlayer;
    //bool isAlive = true;
};

struct Vector
{
    int x;
    int y;
};

void movePlayer(Character& player, std::string direction)
{
    if (direction == "L" && player.x > 0)
    {
        player.x--;
    }
    else if (direction == "R" && player.x < 19)
    {
        player.x++;
    }
    else if (direction == "U" && player.y > 0)
    {
        player.y--;
    }
    else if (direction == "D" && player.y < 19)
    {
        player.y++;
    }

    cout << "Player moved to: " << player.x + 1 << " " << player.y + 1 << endl;
}

void moveEnemy(Character& enemy)
{
    int direction = rand() % 4;
    if (direction == 0 && enemy.x > 0)
    {
        enemy.x--;
    }
    else if (direction == 1 && enemy.x < 19)
    {
        enemy.x++;
    }
    else if (direction == 2 && enemy.y > 0)
    {
        enemy.y--;
    }
    else if (direction == 3 && enemy.y < 19)
    {
        enemy.y++;
    }

    cout << "Enemy " << enemy.name << " moved to: " << enemy.x + 1 << " " << enemy.y + 1 << endl;
}

void attack(Character& attacker, Character& victim)
{
    victim.armor -= attacker.damage;
    if (victim.armor < 0)
    {
        victim.health += victim.armor;
        victim.armor = 0;
    }

    if (victim.health <= 0)
    {
        victim.health = 0;
    }

    cout << attacker.name << " attacked " << victim.name << ". " << victim.name << " health: " << victim.health << " armor: " << victim.armor << endl;
}

void printMap(std::vector<Character>& characters)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            bool isCharacter = false;
            for (int k = 0; k < characters.size(); k++)
            {
                if (characters[k].x == j && characters[k].y == i)
                {
                    if (characters[k].isPlayer)
                    {
                        std::cout << "P ";
                    }
                    else
                    {
                        if (characters[k].health > 0)
                        {
                            std::cout << "E ";
                        }
                        else
                        {
                            std::cout << "X ";
                        }
                    }
                    isCharacter = true;
                    break;
                }
            }
            if (!isCharacter)
            {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

void saveGame(std::vector<Character>& characters)
{
    std::ofstream file("save.bin", std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    for (int i = 0; i < characters.size(); i++)
    {
        int len = characters[i].name.length();
        file.write((char*)&len, sizeof(len));
        file.write(characters[i].name.c_str(), len);

        file.write((char*)&(characters[i].health), sizeof(characters[i].health));
        file.write((char*)&(characters[i].armor), sizeof(characters[i].armor));
        file.write((char*)&(characters[i].damage), sizeof(characters[i].damage));
        file.write((char*)&(characters[i].x), sizeof(characters[i].x));
        file.write((char*)&(characters[i].y), sizeof(characters[i].y));
        file.write((char*)&(characters[i].isPlayer), sizeof(characters[i].isPlayer));
    }
    file.close();

    std::cout << "Game saved" << std::endl;
}

void loadGame(std::vector<Character>& characters)
{
    std::ifstream file("save.bin", std::ios::binary);
    if (file.is_open())
    {
        characters.clear();
        while (!file.eof())
        {
            Character character;
            int len;
            file.read((char*)&len, sizeof(len));
            character.name.resize(len);
            file.read((char*)character.name.c_str(), len);

            file.read((char*)&character.health, sizeof(character.health));
            file.read((char*)&character.armor, sizeof(character.armor));
            file.read((char*)&character.damage, sizeof(character.damage));
            file.read((char*)&character.x, sizeof(character.x));
            file.read((char*)&character.y, sizeof(character.y));
            file.read((char*)&character.isPlayer, sizeof(character.isPlayer));

            if (file.eof())
            {
                break;
            }
            
            characters.push_back(character);
        }
        file.close();

        std::cout << "Game loaded" << std::endl;
    }
    else
    {
        std::cout << "Save file not found" << std::endl;
    }
}

int main()
{
    srand(time(0));
    std::vector<Character> characters;
    Character player;
    int enemyCount = 0;

    cout << "Enter 'new' to start a new game or 'load' to load the previous game: ";
    std::string command;
    getline(std::cin, command);

    if (command == "new")
    {
        cout << "Enter player name: ";
        getline(std::cin, player.name);
        cout << "Enter player health: ";
        cin >> player.health;
        cout << "Enter player armor: ";
        cin >> player.armor;
        cout << "Enter player damage: ";
        cin >> player.damage;
        cin.ignore(32767, '\n');
        player.x = rand() % 20;
        player.y = rand() % 20;
        player.isPlayer = true;
        characters.push_back(player);

        for (int i = 0; i < 5; i++)
        {
            Character enemy;
            enemy.name = "Enemy #" + std::to_string(i + 1);
            enemy.health = rand() % 101 + 50;
            enemy.armor = rand() % 51;
            enemy.damage = rand() % 16 + 15;
            enemy.x = rand() % 20;
            enemy.y = rand() % 20;
            enemy.isPlayer = false;
            characters.push_back(enemy);
            enemyCount++;
        }

        cout << "New game started" << endl;
        cout << "Characters created: " << characters.size() << "\n";
    }
    else if (command == "load")
    {
        loadGame(characters);

        if (characters.size() == 0)
        {
            std::cout << "Closing the game..." << std::endl;
            return 0;
        }

        cout << "Characters loaded: " << characters.size() << "\n";

        for (int i = 0; i < characters.size(); i++)
        {
            if (characters[i].isPlayer)
            {
                continue;
            }
            if (characters[i].health > 0 && !characters[i].isPlayer)
            {
                enemyCount++;
            }
        }
    }

    while (true)
    {
        printMap(characters);
        std::string direction;
        //cout << "Player position: " << player.x + 1 << " " << player.y + 1 << "\n";
        cout << "Plater health: " << characters[0].health << " armor: " << characters[0].armor << "\n";
        cout << "Enemies left: " << enemyCount << "\n";
        cout << "Enter direction (L, R, U, D) or 'save': ";
        getline(std::cin, direction);

        if (direction == "save")
        {
            saveGame(characters);
            continue;
        }

        movePlayer(characters[0], direction);

        // check if player is on the same cell with enemy and attack to enemy
        for (int i = 0; i < characters.size(); i++)
        {
            if (characters[i].isPlayer)
            {
                continue;
            }
            if (characters[i].x == characters[0].x && characters[i].y == characters[0].y && characters[i].health > 0)
            {
                attack(characters[0], characters[i]);
                if (characters[i].health <= 0)
                {
                    enemyCount--;
                }
            }
        }
        

        for (int i = 0; i < characters.size(); i++)
        {
            if (characters[i].isPlayer)
            {
                continue;
            }

            if (characters[i].health <= 0)
            {
                continue;
            }
            moveEnemy(characters[i]);
            if (characters[i].x == characters[0].x && characters[i].y == characters[0].y)
            {
                attack(characters[i], characters[0]);
            }
        }

        if (enemyCount == 0)
        {
            std::cout << "You win!" << std::endl;
            return 0;
        }

        if (characters[0].health <= 0)
        {
            std::cout << "You lose!" << std::endl;
            return 0;
        }
    }

    return 0;
}              