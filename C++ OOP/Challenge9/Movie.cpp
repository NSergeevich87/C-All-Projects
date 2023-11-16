#include "Movie.h"

Movie::Movie(std::string name_val, std::string genre_val, float rating_val, int watched_val)
    : name{name_val}, genre{genre_val}, rating{rating_val}, watched{watched_val} {
        
    }
    
Movie::Movie(const Movie &source)
    : Movie{source.name, source.genre, source.rating, source.watched} {
        
    }

Movie::~Movie()
{
}

