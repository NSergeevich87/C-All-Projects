#ifndef _MOVIE2_H_
#define _MOVIE2_H_

#include <string>

class Movie2
{
private:
    std::string name{};
    float rating{};
    int watched{};
    
public:
    //Metods get/set
    std::string get_name() const { return name; }
    void set_name(std::string name) { this->name = name; }
    float get_rating() const { return rating; }
    void set_rating(float rating) { this->rating = rating; }
    int get_watched() const { return watched; }
    void set_watched(int watched) { this->watched = watched; }
    //Metod increment watched
    void increment_watched() { ++watched; }
    //Metod display
    void display() const { std::cout << name << " " << rating << " " << watched << std::endl;
    //Constructor
    Movie2();
    //Deep copy constructor
    //Move constructor
    //Destructor
    ~Movie2();

};

#endif // _MOVIE2_H_
