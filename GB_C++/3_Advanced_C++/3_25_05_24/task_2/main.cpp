/** Модель данных для посёлка
Что нужно сделать
Используя структуры данных, создайте подробную модель посёлка.
Что известно
• Посёлок состоит из участков, и у каждого участка есть свой номер.
• На любом участке может стоять жилой дом, а также могут быть и другие сооружения:
— гараж,
— сарай (бытовка),
— баня.
• У каждого здания есть информация о площади, которую оно занимает на участке.
• В доме может быть 1–3 этажа, на этаже — 2–4 комнаты:
— спальня,
— кухня,
— ванная,
— детская,
— гостиная.
• У каждого этажа есть информация о количестве комнат и высоте потолка на этаже.
• У каждой комнаты есть информация о занимаемой площади.
• В доме и бане может быть печь с трубой.
Для всех упомянутых сущностей нужно объявить структуры данных.

Обязательно для выполнения задания
Опишите структуры данных для создания модели посёлка. Структуры должны быть:
• связными и легко расширяемыми,
• без дублирующих конструкций.

Дополнительно
Реализуйте заполнение структур данных.
Пользователь заполняет данные о посёлке: вводит общее количество участков, а потом детализирует каждый.
Сначала указывается количество построек на участке, а затем — информация, какие это постройки, сколько 
этажей в доме, какие комнаты на этажах.
После ввода данных можно рассчитать суммарный параметр, например процент земли, занимаемой постройками, 
от общей площади посёлка. Главное в этой задаче не операция подсчёта, а структуры данных.

Советы и рекомендации
• Используйте свои знания о типах данных в C++.
• Можно применять перечисления и векторы, создавать структуры внутри структур и так далее.
• Перечислять комнаты и типы зданий нужно следующим образом:

enum room_type
{
living,
children,
…

• Затем нужно использовать полученный тип внутри структуры. Алгоритм заполнения каждого объекта одинаковый:
— создать объект нужного типа,
— ввести с клавиатуры значения,
— добавить объект в вектор при помощи push_back.*/

#include <iostream>
#include <vector>
#include <string>

enum room_type
{
    living,
    children,
    kitchen,
    bathroom,
    guest
};

struct Room
{
    room_type type;
    double area;
};

struct Floor
{
    int rooms_count;
    double ceiling_height;
    std::vector<Room> rooms;
};

struct Building
{
    double area;
    int floors_count;
    std::vector<Floor> floors;
};

struct Villahe
{
    double total_area;
    int buildings_count;
    std::vector<Building> buildings;
};

void checkArea(Villahe village)
{
    double buildings_area = 0;
    for (int i = 0; i < village.buildings_count; ++i)
    {
        buildings_area += village.buildings[i].area;
    }
    double percent = (buildings_area / village.total_area) * 100;
    std::cout << "The percentage of land occupied by buildings is " << percent << "%" << std::endl;
}

int main()
{
    Villahe village;
    std::cout << "Enter the total area of the village: ";
    std::cin >> village.total_area;
    std::cout << "Enter the number of buildings in the village: ";
    std::cin >> village.buildings_count;
    for (int i = 0; i < village.buildings_count; ++i)
    {
        Building building;
        std::cout << "Enter the area of the building " << i + 1 << " : ";
        std::cin >> building.area;
        std::cout << "Enter the number of floors in the building " << i + 1 << " : ";
        std::cin >> building.floors_count;
        for (int j = 0; j < building.floors_count; ++j)
        {
            Floor floor;
            std::cout << "Enter the number of rooms on the floor " << j + 1 << " : ";
            std::cin >> floor.rooms_count;
            std::cout << "Enter the ceiling height on the floor " << j + 1 << " : ";
            std::cin >> floor.ceiling_height;
            for (int k = 0; k < floor.rooms_count; ++k)
            {
                Room room;
                int type;
                std::cout << "Enter the type of " << k + 1 << " room (0 - living, 1 - children, 2 - kitchen, 3 - bathroom, 4 - guest): ";
                std::cin >> type;
                room.type = static_cast<room_type>(type);
                std::cout << "Enter the area of the room " << k + 1 << " : ";
                std::cin >> room.area;
                floor.rooms.push_back(room);
            }
            building.floors.push_back(floor);
        }
        village.buildings.push_back(building);
    }

    checkArea(village);

    return 0;
}