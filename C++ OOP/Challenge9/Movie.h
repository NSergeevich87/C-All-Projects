#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
private:
    std::string name{};
    std::string genre{};
    float rating{};
    int watched{};
    
public:
    //Constructor
    Movie(std::string name_val, std::string genre_val, float rating_val, int watched_val);
    //Copy constructor
    Movie(const Movie &source);
    //Destructor
    ~Movie();

    std::string get_name() const { return name; }
    void set_name(std::string name) { this->name = name; }
    std::string get_genre() const { return genre; }
    void set_genre(std::string genre) { this->genre = genre; }
    float get_rating() const { return rating; }
    void set_rating(float rating) { this->rating = rating; }
    int get_watched() const { return watched; }
    void set_watched(int watched) { this->watched = watched; }
    
    void increase_watched() { ++watched; }
};

#endif // _MOVIE_H_
