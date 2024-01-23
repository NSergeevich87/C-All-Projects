#pragma once
#include "ActorBehavoir.h"
#include <iostream>
#include <string>

class Actor : public ActorBehavoir
{
protected:
    std::string name{};
    bool isMakeOrder{};
    bool isTakeOrder{};

public:
    Actor(std::string name_val) : name{ name_val } {}
    virtual std::string get_name() = 0;
    ~Actor() = default;
};

