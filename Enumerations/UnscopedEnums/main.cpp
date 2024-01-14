#include <iostream>
#include <vector>
#include <string>

enum Direction { North, South, East, West };
//enum Street { Carme, Rambla };

std::string direction_to_string(Direction direction)
{
    std::string result;

    switch (direction)
    {
    case North:
        result = "North";
        break;
    case South:
        result = "South";
        break;
    case East:
        result = "East";
        break;
    case West:
        result = "West";
        break;
    default:
        result = "Unknown direction";
        break;
    }

    return result;
}

void test1()
{
    std::cout << "\nTest1=======================================" << std::endl;

    Direction direction {North};
    std::cout << "Direction: " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = West;
    std::cout << "Direction: " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = Direction(100);
    std::cout << "Direction: " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = static_cast<Direction>(100);
    std::cout << "Direction: " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;
}

enum Comida { Pan, Leche, Pollo, Manzana };
std::ostream &operator<<(std::ostream &os, const Comida comida)
{
    switch (comida)
    {
        case Pan:
            os << "Pan";
            break;
        case Leche:
            os << "Leche";
            break;
        case Pollo:
            os << "Pollo";
            break;
        case Manzana:
            os << "Manzana";
            break;
        default:
            os << "Invalid item";
    }

    return os;
}
bool is_valid_comida(Comida comida)
{
    switch (comida)
    {
        case Pan:
        case Leche:
        case Pollo:
        case Manzana:
            return true;
        default:
            return false;
    }
}
void display_comida(const std::vector<Comida> &comida)
{
    std::cout << "Comida List" << "\n==================================" << std::endl;
    int valid_item{};
    int invalid_item{};

    for(Comida item : comida)
    {
        std::cout << item << std::endl;

        if(is_valid_comida(item)) valid_item++;
        else invalid_item++;
    }

    std::cout << "=====================================" << std::endl;
    std::cout << "Valid Item: " << valid_item << std::endl;
    std::cout << "Invalid Item: " << invalid_item << std::endl;
    std::cout << "Total Items: " << valid_item + invalid_item << std::endl;
}

void test2()
{
    std::cout << "\nTest2=======================================" << std::endl;

    std::vector<Comida> comida;
    comida.push_back(Leche);
    comida.push_back(Manzana);
    comida.push_back(Manzana);
    comida.push_back(Pan);
    comida.push_back(Pollo);

    int Termos {100};
    comida.push_back(Comida(Termos));
    comida.push_back(Comida(0));

    display_comida(comida);
}

enum State { Engine_Failure, Inclement_Weather, Nominal, Unknown};
enum Sequence { Abort, Hold, Launch };
std::istream &operator>>(std::istream &is, State &state)
{
    std::underlying_type_t<State> user_input;
    is >> user_input;

    switch (user_input)
    {
        case Engine_Failure:
        case Inclement_Weather:
        case Nominal:
        case Unknown:
            state = State(user_input);
            break;
        default:
            std::cout << "User input is not a valid launch state." << std::endl;
            state = Unknown;
    }

    return is;
}
std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
    switch (sequence)
    {
        case Abort:
            os << "Abort";
            break;
        case Hold:
            os << "Hold";
            break;
        case Launch:
            os << "Launch";
            break;
    }

    return os;
}
void initiate(Sequence sequence)
{
    std::cout << "Initiate " << sequence << " sequence!" << std::endl;
}

void test3()
{
    std::cout << "\nTest3=======================================" << std::endl;

    State state;
    std::cout << "Launch state: ";
    std::cin >> state;

    switch (state)
    {
        case Engine_Failure:
        case Unknown:
            initiate(Abort);
            break;
        case Inclement_Weather:
            initiate(Hold);
            break;
        case Nominal:
            initiate(Launch);
            break;
    }
}

int main()
{
    std::cout << "Unscoped Enums" << std::endl;

    //test1();
    //test2();
    test3();

    return 0;
}