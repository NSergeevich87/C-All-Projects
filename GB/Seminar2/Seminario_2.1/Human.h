#pragma once
#include "Actor.h"
#include <iostream>
#include <string>

class Human : public Actor
{
protected:
    std::string name{};
    bool isMakeOrder{};
    bool isTakeOrder{};

public:
    Human(std::string name_val) : Actor(name_val) {}

    virtual std::string get_name() override;
    virtual void setMakeOrder(bool value) override;
    virtual void setTakeOrder(bool value) override;
    virtual bool getMakeOrder() override;
    virtual bool getTakeOrder() override;

    ~Human() = default;
};

