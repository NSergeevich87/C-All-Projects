// Seminar3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "Groups.h"

using namespace std;

int main()
{
	Student Student_1{ "Nick", 7 };
	Student Student_2{ "Nikita", 2 };
	Student Student_3{ "Nikiforov", 7 };
	Student Student_4{ "Daniil", 4 };
	Student Student_5{ "Kseniia", 7 };
	
	Groups Students{};

	Students.AddStudent(Student_1);
	Students.AddStudent(Student_2);
	Students.AddStudent(Student_3);
	Students.AddStudent(Student_4);
	Students.AddStudent(Student_5);

	Students.PrintStudents();

	Students.DeleteStudent("Nick");

	Students.PrintStudents();

	return 0;
}