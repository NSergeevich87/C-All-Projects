#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "Movie.h"
#include <vector>

class Movies
{
private:
    std::vector<Movie> movies;
    
public:
    void add_movie(std::string name, std::string genre, float rating, int watched);
    void display();
    void increment_watched(std::string name);
    
    Movies();
    ~Movies();

};

#endif // _MOVIES_H_
