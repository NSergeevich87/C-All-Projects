#include "Market.h"
#include <iostream>
#include <string>
#include <algorithm>

void Market::TakeInQueue(Human human)
{
	queue.push_back(human);
	std::cout << human.get_name() << " esta en la cola\n";
}

void Market::TakeOrders()
{
	//����� �� ������ queue � ��������� ismakeorder � ���� ����� ��� ����� ������ � ����������� �� true
	for (Human &item : queue)
	{
		if (!item.getMakeOrder())
		{
			item.setMakeOrder(true);
			std::cout << item.get_name() << " ha pedido un orden -> " << item.getMakeOrder() << "\n";
		}
	}
}

void Market::GiveOrders()
{
	//����� �� ������ ��������� � ���� ismakeorder true � ����������� istakeorder true
	for (Human &item : queue)
	{
		if (item.getMakeOrder())
		{
			item.setTakeOrder(true);
			std::cout << item.get_name() << " ha resibido su orden -> " << item.getTakeOrder() << "\n";
		}
	}
}

void Market::ReleaseFromQueue()
{
	//��������� ����� ������ ���, ��� ����� �������� �� �������� (�� ������ istakeorder) � ������� ����� releasefrommarket
	std::vector<Human> ready_to_leave{};
	for (Human &item : queue)
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
	//������� ����������� �� ��������
	for (Human &item : humans)
	{
		for (int i = 0; i < queue.size(); i++)
		{
			if (item.get_name() == queue[i].get_name())
			{
				queue.erase(queue.begin() + i);
			}
		}

		std::cout << item.get_name() << " ha salido de la tienda!\n";
	}
}

void Market::Update()
{
	//�������� ��� ������ takeorders, giveorders, � ����� �� �������
	TakeOrders();
	GiveOrders();
	ReleaseFromQueue();
}

void Market::PrintQueue()
{
	std::cout << "\nPeople in the queue:\n";
	std::cout << "[ ";
	for (auto item : queue)
	{
		std::cout << item.get_name() << " ";
	}
	std::cout << "]\n\n";
}
