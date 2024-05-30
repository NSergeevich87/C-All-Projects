#include "headers/Track.h"

Track::Track(std::string name_v, std::tm date_v, int duration_v)
    : name(name_v), date(date_v), duration(duration_v)
{
}

std::string Track::getName() const
{
    return name;
}

std::tm Track::getDate() const
{
    return date;
}

int Track::getDuration() const
{
    return duration;
}