#include "headers/Player.h"

#include <iostream>

void Player::addTrack(Track track)
{
    tracks.push_back(track);
}

void Player::play()
{
    if (tracks.empty())
    {
        std::cout << "No tracks to play" << std::endl;
        return;
    }

    if (currentTrackIndex != -1)
    {
        std::cout << "Track is already playing" << std::endl;
        return;
    }

    currentTrackIndex = rand() % tracks.size();
    std::cout << "Playing track: " << tracks[currentTrackIndex].getName() << std::endl;
}

void Player::pause()
{
    if (currentTrackIndex == -1)
    {
        std::cout << "No track is playing" << std::endl;
        return;
    }

    std::cout << "Track is paused" << std::endl;
    //currentTrackIndex = -1;
}

void Player::next()
{
    if (tracks.empty())
    {
        std::cout << "No tracks to play" << std::endl;
        return;
    }

    currentTrackIndex = rand() % tracks.size();
    std::cout << "Playing next track: " << tracks[currentTrackIndex].getName() << std::endl;
}

void Player::stop()
{
    if (currentTrackIndex == -1)
    {
        std::cout << "No track is playing" << std::endl;
        return;
    }

    std::cout << "Track is stopped" << std::endl;
    currentTrackIndex = -1;
}

void Player::exit()
{
    std::cout << "Exiting player" << std::endl;
}