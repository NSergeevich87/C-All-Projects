/** Задача 1. Информация о фильме с кинопортала
Что нужно сделать
Запишите подробную информацию о киноленте в виде JSON-файла. Выберите понравившуюся вам картину на любимом портале, 
проанализируйте информацию о ней и составьте JSON-словарь.
В информации должны присутствовать: страна и дата создания киноленты, студия, которая вела съёмки, автор сценария, 
режиссёр и продюсер киноленты. Обязательно добавьте информацию обо всех главных действующих лицах и тех актёрах, 
которые их сыграли.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    json movieInfo;
    movieInfo["movie"] = {
        {"title", "The Shawshank Redemption"},
        {"country", "USA"},
        {"release_date", "1994"},
        {"studio", "Castle Rock Entertainment"},
        {"screenwriter", "Frank Darabont"},
        {"director", "Frank Darabont"},
        {"producer", "Niki Marvin"}
    };

    std::vector<std::map<std::string, std::string>> actors = {
        {{"name", "Tim Robbins"}, {"role", "Andy Dufresne"}},
        {{"name", "Morgan Freeman"}, {"role", "Ellis Boyd 'Red' Redding"}},
        {{"name", "Bob Gunton"}, {"role", "Warden Norton"}},
        {{"name", "William Sadler"}, {"role", "Heywood"}},
        {{"name", "Clancy Brown"}, {"role", "Captain Hadley"}},
        {{"name", "Gil Bellows"}, {"role", "Tommy"}},
        {{"name", "Mark Rolston"}, {"role", "Bogs Diamond"}},
        {{"name", "James Whitmore"}, {"role", "Brooks Hatlen"}},
        {{"name", "Jeffrey DeMunn"}, {"role", "1946 D.A."}},
        {{"name", "Larry Brandenburg"}, {"role", "Skeet"}}
    };

    movieInfo["movie"]["actors"] = actors;

    std::ofstream file("movie_info.json");
    file << movieInfo.dump(4);
    file.close();

    return 0;
}

