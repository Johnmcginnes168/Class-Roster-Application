//Section D.1: Creating Student Class Definitions

#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

class Student {

public:

	//Section D.2d: Constructor Definition

	Student(string studentID,string firstName,string lastName,string emailAddress,int age,int courseDays[],DegreeProgram degreeProgram);

	//Section D.2a: Getters (Accessors) Definition

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int	getAge();
	int* getCourseDays();
	DegreeProgram getDegreeProgram();

	//Section D.2b: Setters (Mutators) Definition

	void setStudentID (string studentID);
	void setFirstName (string firstName);
	void setLastName (string lastName);
	void setEmailAddress (string emailAddress);
	void setAge (int age);
	void setCourseDays(int courseDays[]);
	void setDegreeProgram (DegreeProgram degreeProgram);

	//Section D.2e: Print Function Definition

	void print();

	//Section D.2c: Functions set to private to ensure accesses and changes are done using the accessors and mutators

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[3];
	DegreeProgram degreeProgram;
};

