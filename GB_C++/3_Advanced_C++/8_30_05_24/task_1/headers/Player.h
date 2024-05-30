#pragma once

#include "Track.h"

#include <vector>

class Player
{
private:
    std::vector<Track> tracks;
    int currentTrackIndex = -1;

public:
    void addTrack(Track track);
    void play();
    void pause();
    void next();
    void stop();
    void exit();
};