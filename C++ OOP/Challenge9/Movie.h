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
    std::string get_genre() const { return genre; }
    float get_rating() const { return rating; }
    int get_watched() const { return watched; }
};

#endif // _MOVIE_H_
