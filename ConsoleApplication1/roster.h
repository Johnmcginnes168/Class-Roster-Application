#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster {

public:

//Constructor Definition

	Roster();

//Destructor Definition

	~Roster();

//E.3a Adding to Class Roster Array, setting the instance variables and updating the roster (Definition)

	void add(string studentID,string firstName,string lastName,string emailAddress,int age,int	courseDays1,int	courseDays2,int	courseDays3,DegreeProgram degreeProgram);

//E.3b Removing from Class Roster Array by Student ID (Definition)

	void remove(string studentID);

//E.3c Printing the entire Student Roster (Definition)

	void printAll();

//E.3d Printing the Average Days in a Course (Definition)

	void printAverageDaysInCourse(string studentID);

//E.3e Verifies the Student Emails and Displays Invalid Entires (Definition)

	void printInvalidEmails();

//E.3f Prints out Students by Degree Program (Definition)

	void printByDegreeProgram(DegreeProgram degreeProgram);

//Student ID - Index Used for Loops (Definition)

	string getSIDIndex(int index);
	int SIDIndex;

//E.1 Creating an Array of Pointers called classRosterArray to hold the data provided in the studentData Table

	Student* classRosterArray[5];
};
