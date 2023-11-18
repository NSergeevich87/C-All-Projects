#include "Peliculas.h"

bool Peliculas::add_peli(std::string name, float rating, int watched)
{
    for(Pelicula peli : base)
    {
        if (peli.get_name() == name)
        {
            std::cout << "This name exists!" << std::endl;
            return false;
        }
    }
    
    Pelicula temp {name, rating, watched};
    base.push_back(temp);
    return true;
}

void Peliculas::display()
{
    if (base.size() == 0)
    {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    for (Pelicula peli : base)
    {
        peli.display();
    }
}

bool Peliculas::increment(std::string n)
{
    for (Pelicula &peli : base)
    {
        if (peli.get_name() == n)
        {
            peli.increment_watched();
            return true;
        }
    }
    std::cout << "No exist movie with this name!" << std::endl;
    return false;
}

Peliculas::Peliculas()
{
}

Peliculas::~Peliculas()
{
}

