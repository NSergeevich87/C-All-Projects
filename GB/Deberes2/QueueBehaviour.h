#pragma once

#include "Actor.h"
#include "Human.h"
#include <iostream> 

class QueueBehaviour
{
	virtual void TakeInQueue(Human human) = 0;
	virtual void TakeOrders() = 0;
	virtual void GiveOrders() = 0;
	virtual void ReleaseFromQueue() = 0;
};

