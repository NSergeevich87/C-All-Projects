/** Задание 3. Реализация симуляции игры «Рыбалка»
Что нужно сделать
Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки (river.txt) задаётся 
список из видов рыб, которые можно в ней поймать. Рыбок может быть сколько угодно, разных видов. 
Виды при этом могут повторяться.
В начале программы пользователь указывает, какую именно рыбу он сейчас будет ловить — вид этой рыбы. 
После этого из первого файла друг за другом осуществляется чтение его содержимого, вид за видом. 
Если на отдельных шагах вид совпал с указанным пользователем, в выходной файл basket.txt (корзинка) 
записывается этот вид.
В конце программы показывается, сколько было поймано рыб за текущую ловлю. Программу можно запускать 
несколько раз, при этом уже пойманные рыбы должны сохраняться в файле-корзинке.
Пример содержания исходного файла

sunfish
shad
carp
bass
bullhead
carp
walleye
catfish
carp*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string fish;
    std::cout << "Enter the fish you want to catch: ";
    std::getline(std::cin, fish);

    std::ifstream river("river.txt");
    if (!river.is_open()) {
        std::cerr << "Error: file river.txt not found." << std::endl;
        return 1;
    }
    std::ofstream basket("basket.txt", std::ios::app);
    if (!basket.is_open()) {
        std::cerr << "Error: file basket.txt not found." << std::endl;
        return 1;
    }

    std::vector<std::string> fish_list;
    std::string fish_in_river;
    while (river >> fish_in_river) {
        fish_list.push_back(fish_in_river);
    }
    river.close();

    int fish_caught = 0;
    for (const std::string& fish_in_river : fish_list) {
        if (fish_in_river == fish) {
            basket << fish_in_river << std::endl;
            ++fish_caught;
        }
    }
    basket.close();
    
    std::cout << "You caught " << fish_caught << " fish." << std::endl;
    return 0;
}