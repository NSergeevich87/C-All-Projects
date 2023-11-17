#include <iostream>
#include "Movies.h"

using namespace std;

int main()
{
    Movies my_list;
    my_list.display();
    my_list.add_movie("Star Wars", "Space Opera", 9.5, 0);
    my_list.add_movie("Terminator_2", "Terror", 9.0, 0);
    my_list.add_movie("Mask", "Comedy", 7.0, 0);
    my_list.display();
    my_list.increment_watched("Star Wars");
    my_list.increment_watched("Star");
    my_list.add_movie("Star Wars", "Space Opera", 9.5, 0);
    my_list.display();
    /*my_list.add_movie("Star Wars", "Space Opera", 9.5, 4);
    my_list.display();
    my_list.increment_watched("Star Wars");
    my_list.display();
    my_list.add_movie("Terminator_2", "Terror", 9.0, 6);
    my_list.display();
    my_list.increment_watched("Terminator_2");
    my_list.increment_watched("Terminator_2");
    my_list.add_movie("Mask", "Comedy", 7.0, 3);
    my_list.display();*/
    
    cout << endl;
    return 0;
}