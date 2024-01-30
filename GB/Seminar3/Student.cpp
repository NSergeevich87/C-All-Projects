#include "Student.h"

Student::Student(std::string name_val, int group_val) : name{name_val}, group{group_val}
{
}

std::string Student::GetName() const
{
	return name;
}

int Student::GetGroup() const
{
	return group;
}

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	// TODO: insert return statement here
	os << "Name: " << obj.name << " group: " << obj.group;
	return os;
}
