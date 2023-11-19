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
    
    /*Movies(std::vector<Movie> vec);
    Movies(const Movies &source);
    Movies(Movies &&source) noexcept;
    ~Movies();*/

};

#endif // _MOVIES_H_
