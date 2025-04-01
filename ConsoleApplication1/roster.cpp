#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

//Constructor Function

Roster::Roster() {
	SIDIndex = -1;
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr;
	}
}

//Destructor Function

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}

//E.3a Adding to Class Roster Array, setting the instance variables and updating the roster (Function)

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays1, int courseDays2, int courseDays3, DegreeProgram degreeProgram) {
	int courseDays[] = { courseDays1, courseDays2, courseDays3 };
	classRosterArray[++SIDIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
}

//E.3b Removing from Class Roster Array by Student ID (Function)

void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= SIDIndex; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[SIDIndex];
			classRosterArray[SIDIndex] = nullptr;
			SIDIndex--;
			break;
		}
	}
	if (!found) {
		cout << "Student with ID " << studentID << " was not found in the roster." << endl;
	}
}

//E.3c Printing the entire Student Roster (Function)

void Roster::printAll() {
	for (int i = 0; i <= SIDIndex; ++i) {
		classRosterArray[i]->print();
	}
}

//E.3d Printing the Average Days in a Course (Function)

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= SIDIndex; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* averageDays = classRosterArray[i]->getCourseDays();
			cout << (averageDays[0] + averageDays[1] + averageDays[2]) / 3.0 << endl;
			return;
		}
	}
}

//E.3e Verifies the Student Emails and Displays Invalid Entires (Function)

void Roster::printInvalidEmails() {
	for (int i = 0; i <= SIDIndex; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
			cout << "Invalid Email: " << email << endl;
		}
	}
}

//E.3f Prints out Students by Degree Program (Function)

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= SIDIndex; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

//Student ID - Index Used for Loops (Function)

string Roster::getSIDIndex(int index) {
	if (index <= SIDIndex) {
		return classRosterArray[index]->getStudentID();
	}
	return " ";
}