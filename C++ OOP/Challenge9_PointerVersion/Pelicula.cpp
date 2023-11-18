#include "Pelicula.h"

Pelicula::Pelicula(std::string name_val, float rating_val, int watched_val)
{
    name = new std::string;
    *name = name_val;
    rating = new float;
    *rating = rating_val;
    watched = new int;
    *watched = watched_val;
}

Pelicula::Pelicula(const Pelicula &source)
    : Pelicula{*source.name, *source.rating, *source.watched} {
        
    }
    
Pelicula::Pelicula(Pelicula &&source) noexcept
    : name{source.name}, rating{source.rating}, watched{source.watched} {
        source.name = nullptr;
        source.rating = nullptr;
        source.watched = nullptr;
    }

Pelicula::~Pelicula()
{
    delete name;
    delete rating;
    delete watched;
}

