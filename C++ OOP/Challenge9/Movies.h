#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "Movie.h"
#include <vector>

class Movies
{
private:
    std::vector<Movie> all_movies;
    
public:
    void add_movie();
    
    Movies();
    ~Movies();

};

#endif // _MOVIES_H_
