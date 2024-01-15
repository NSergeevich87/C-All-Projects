#include <iostream>
#include <vector>

using namespace std;

enum class grosery_items { milk = 350, pan = 200, manzana = 250, naranja = 150 };

std::ostream &operator<<(std::ostream &os, const grosery_items &item)
{
    std::underlying_type_t<grosery_items> value = std::underlying_type_t<grosery_items>(item);
    switch (item)
    {
        case grosery_items::milk:
            os << "Milk";
            break;
        case grosery_items::pan:
            os << "Pan";
            break;
        case grosery_items::manzana:
            os << "Manzana";
            break;
        case grosery_items::naranja:
            os << "Naranja";
            break;
        default:
            os << "Invalid Item";
    }
    os << " : " << value;
    return os;
}

bool is_valid_grocery_item(const grosery_items &item)
{
    switch (item)
    {
        case grosery_items::milk:
        case grosery_items::pan:
        case grosery_items::manzana:
        case grosery_items::naranja:
            return true;
        default:
            return false;
    }
}

void display_grocery_list(const std::vector<grosery_items> &items)
{
    std::cout << "Grocety List" << "\n================================" << std::endl;
    int inv_count {0};
    int val_count {0};
    for(grosery_items i : items)
    {
        std::cout << i << std::endl;

        if (is_valid_grocery_item(i))
        {
            val_count++;
        }
        else
        {
            inv_count++;
        }
    }
    std::cout << "================================" << std::endl;
    std::cout << "Valid Items: " << val_count << std::endl;
    std::cout << "Invalid Items: " << inv_count << std::endl;
    std::cout << "Total Items: " << val_count + inv_count << std::endl;
}

void test1()
{
    std::cout << "\nTest1==============================" << std::endl;

    std::vector<grosery_items> items{};
    items.push_back(grosery_items::manzana);
    items.push_back(grosery_items::milk);
    items.push_back(grosery_items::naranja);

    int herramienta {1000};
    items.push_back(grosery_items(herramienta));
    items.push_back(grosery_items(200));

    display_grocery_list(items);
}

class Player
{
    friend std::ostream &operator<<(std::ostream &os, const Player &p);
    public:
        enum class Mode {Attack, Defence, Idle};
        enum class Direction {North, South, East, West};

        Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North) : name{name}, mode{mode}, direction{direction} {}
        
        std::string get_name() const { return name; }
        Mode get_mode() const { return mode; }
        Direction get_direction() const { return direction; }

        void set_name(std::string name) { this->name = name; }
        void set_mode(Mode mode) { this->mode = mode; }
        void set_direction(Direction direction) { this->direction = direction; }
    private:
        std::string name{};
        Mode mode{};
        Direction direction{};
};

std::string get_player_mode(Player::Mode mode)
{
    std::string result{};

    switch (mode)
    {
        case Player::Mode::Attack:
            result = "Attack";
            break;
        case Player::Mode::Defence:
            result = "Defence";
            break;
        case Player::Mode::Idle:
            result = "Idle";
            break;
    }

    return result;
}

std::string get_player_direction(Player::Direction direction)
{
    std::string result{};

    switch (direction)
    {
        case Player::Direction::East:
            result = "East";
            break;
        case Player::Direction::North:
            result = "North";
            break;
        case Player::Direction::South:
            result = "South";
            break;
        case Player::Direction::West:
            result = "West";
            break;
    }

    return result;
}

std::ostream &operator<<(std::ostream &os, const Player &p)
{
    std::cout << "Player name: " << p.get_name() << "\n"
              << "Player mode: " << get_player_mode(p.mode) << "\n"
              << "Player direction: " << get_player_direction(p.direction)
              << std::endl;
    return os; 
}

void test2()
{
    std::cout << "\nTest2==============================" << std::endl;

    Player p1 {"Nick", Player::Mode::Attack, Player::Direction::East};
    Player p2 {"Daniil", Player::Mode::Defence, Player::Direction::West};
    Player p3 {"Ksy", Player::Mode::Idle, Player::Direction::South};

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
}

int main()
{
    cout << "ScopedEnums" << endl;

    //test1();
    test2();

    return 0;
}