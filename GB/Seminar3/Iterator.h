#pragma once

#include <iostream>
#include "Student.h"
#include <string>

class Iterator
{
public:
	virtual void AddStudent(Student& obj) = 0;
	virtual void DeleteStudent(std::string name) = 0;
	virtual void PrintStudents() = 0;
};

