#include "Movies.h"
#include <iostream>

Movies::Movies()
{
}

Movies::~Movies()
{
}

/*Movies::Movies(std::vector<Movie> vec)
{
    movies = new std::vector<Movie>;
    *movies = vec;
}

Movies::Movies(const Movies &source)
    : Movies{*source.movies} {
        
    }
    
Movies::Movies(Movies &&source) noexcept
    : movies{source.movies} {
        source.movies = nullptr;
    }

Movies::~Movies()
{
    delete movies;
}*/

void Movies::add_movie(std::string name, std::string genre, float rating, int watched)
{
    for (const Movie &peli : movies)
    {
        if (peli.get_name() == name)
        {
            std::cout << "Movie with the name: " << peli.get_name() << " exists. Add other one." << std::endl;
            return;
        }
    }
    Movie movie { name, genre, rating, watched };
    movies.push_back(movie);
}

void Movies::display()
{
    if (movies.size() > 0)
    {
        for (const auto &peli : movies)
        {
            std::cout << "\t" << peli.get_name() << " ";
            std::cout << peli.get_genre() << " ";
            std::cout << peli.get_rating() << " ";
            std::cout << peli.get_watched() << std::endl;
        }
    }
    else
    {
        std::cout << "List is empty! Add one movie.\n" << std::endl;
    }
}

void Movies::increment_watched(std::string name)
{
    if (movies.size() > 0)
    {
        for(Movie &peli : movies)
        {
            if (peli.get_name() == name) 
            { 
                peli.increase_watched();
                std::cout << "Watched increased! " << peli.get_name() << std::endl;
                return;
            }
        }
        std::cout << "There are no movie with this name!" << std::endl;
    }
    else
    {
        std::cout << "There are no movie to increase watched! First add one." << std::endl;
    }
}