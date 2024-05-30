#pragma once

#include <string>
#include <ctime>

class Track
{
public:
    Track(std::string name_v, std::tm date_v, int duration_v);
    std::string getName() const;
    std::tm getDate() const;
    int getDuration() const;

private:
    std::string name;
    std::tm date;
    int duration;
};