#pragma once

#include "Actor.h"
#include "Human.h"
#include <iostream>
#include <vector>

class MarketBehaviour
{
	virtual void AcceptToMarket(Human human) = 0;
	virtual void ReleaseFromMarket(std::vector<Human> actors) = 0;
	virtual void Update() = 0;
};

