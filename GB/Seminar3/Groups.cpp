#include "Groups.h"
#include <algorithm>

void Groups::AddStudent(Student& obj)
{
	Students.push_back(obj);
}

void Groups::DeleteStudent(std::string name)
{
	auto it = Students.begin();
	while (it != Students.end())
	{
		if (it->GetName() == name)
		{
			Students.erase(it);
			break;
		}
		else it++;
	}
}

void Groups::PrintStudents()
{
	for (Student& i : Students)
	{
		std::cout << i << "\n";
	}
}
