#pragma once

#include <iostream>
#include <string>

class Student
{
	friend std::ostream& operator<<(std::ostream& os, const Student& obj);

private:
	std::string name{};
	int group{};

public:
	Student(std::string name_val, int group_val);
	
	std::string GetName() const;
	int GetGroup() const;
	
	~Student() = default;
};

