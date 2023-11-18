#ifndef _PELICULAS_H_
#define _PELICULAS_H_

#include "Pelicula.h"
#include <vector>
#include <string>

class Peliculas
{
private:
    std::vector<Pelicula> base{};
    
public:
    bool add_peli(std::string name, float rating, int watched);
    void display();
    bool increment(std::string n);
    
    Peliculas();
    ~Peliculas();

};

#endif // _PELICULAS_H_
