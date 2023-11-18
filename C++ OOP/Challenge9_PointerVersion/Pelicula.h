#ifndef _PELICULA_H_
#define _PELICULA_H_

#include <iostream>
#include <string>

class Pelicula
{
private:
    std::string *name{};
    float *rating{};
    int *watched{};
    
public:
    //Constructor
    Pelicula(std::string name_val, float rating_val, int watched_val);
    //Deep copy constructor
    Pelicula(const Pelicula &source);
    //Move constructor
    Pelicula(Pelicula &&source) noexcept;
    //Destructor
    ~Pelicula();
    //Metods get/set
    std::string get_name() const { return *name; }
    void set_name(std::string n) { *name = n; }
    float get_rating() const { return *rating; }
    void set_rating(float r) { *rating = r; }
    int get_watched() const { return *watched; }
    void set_watched(int w) { *watched = w; }
    //Metod increment watched
    void increment_watched() { ++*watched; }
    //Metod display
    void display() const { std::cout << *name << " " << *rating << " " << *watched << std::endl; }
};

#endif // _PELICULA_H_
