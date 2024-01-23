#pragma once
#include <iostream>
#include <string>

class ActorBehavoir
{
    virtual void setMakeOrder(bool value) = 0;
    virtual void setTakeOrder(bool value) = 0;
    virtual bool getMakeOrder() = 0;
    virtual bool getTakeOrder() = 0;
};

