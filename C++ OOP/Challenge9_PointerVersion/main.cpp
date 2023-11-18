#include "Peliculas.h"
#include <iostream>

using namespace std;

int main()
{
    Peliculas my_list{};
    my_list.display();
    my_list.add_peli("Star Wars", 9.5, 3);
    my_list.display();
    my_list.add_peli("Star Wars", 9.5, 3);
    my_list.add_peli("Wars", 5.4, 1);
    my_list.display();
    my_list.increment("Star Wars");
    my_list.increment("Star");
    my_list.display();
    
    cout << endl;
    return 0;
}