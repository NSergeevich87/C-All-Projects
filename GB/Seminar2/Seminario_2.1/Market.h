#pragma once

#include "QueueBehaviour.h"
#include "MarketBehaviour.h"
#include "iostream"

class Market : public QueueBehaviour, MarketBehaviour
{
private:
	std::vector<Human> queue; 

public:
	virtual void TakeInQueue(Human human) override;
	virtual void TakeOrders() override;
	virtual void GiveOrders() override;
	virtual void ReleaseFromQueue() override;
	virtual void AcceptToMarket(Human human) override;
	virtual void ReleaseFromMarket(std::vector<Human> humans) override;
	virtual void Update() override;
	void PrintQueue();
};

