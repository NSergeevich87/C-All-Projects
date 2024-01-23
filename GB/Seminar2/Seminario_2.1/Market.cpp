#include "Market.h"
#include <iostream>
#include <string>

void Market::TakeInQueue(Human human)
{
	queue.push_back(human);
}

void Market::TakeOrders()
{
	//бежим по списку queue и провер€ем ismakeorder у кого закан еще небыл сделан и проставл€ем на true
	for (auto item : queue)
	{
		if (item.getMakeOrder() == false)
		{
			item.setMakeOrder(true);
		}
	}
}

void Market::GiveOrders()
{
	//бежим по списку провер€ем у кого ismakeorder true и проставл€ем istakeorder true
	for (auto item : queue)
	{
		if (item.getMakeOrder() == true)
		{
			item.setTakeOrder(true);
		}
	}
}

void Market::ReleaseFromQueue()
{
	//составить новый список тех, кто готов выходить из магазина (по методу istakeorder) и вызвать метод releasefrommarket
	std::vector<Human> ready_to_leave{};
	for (auto item : queue)
	{
		if (item.getTakeOrder() == true)
		{
			ready_to_leave.push_back(item);
		}
	}
	ReleaseFromMarket(ready_to_leave);
}

void Market::AcceptToMarket(Human human)
{
	std::cout << human.get_name() << " ha entrado a la tienda!\n";
	TakeInQueue(human);
}

void Market::ReleaseFromMarket(std::vector<Human> humans)
{
	//удал€ем посетителей из магазина
	for (auto item : humans)
	{
		for (auto i : queue)
		{
			if (i.get_name() == item.get_name())
			{
				queue.pop_back(); // »—ѕ–ј¬»“№!
			}
		}
		std::cout << item.get_name() << " ha salido de la tienda!\n";

	}
}

void Market::Update()
{
	//содержит три метода takeorders, giveorders, и выйти из очереди
}
