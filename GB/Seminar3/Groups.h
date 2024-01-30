#pragma once

#include <iostream>
#include <vector>
#include "Student.h"
#include "Iterator.h"

class Groups : public Iterator 
{
public:
	std::vector<Student> Students{};

	virtual void AddStudent(Student& obj) override final;
	virtual void DeleteStudent(std::string name) override final;
	virtual void PrintStudents() override final;
};

