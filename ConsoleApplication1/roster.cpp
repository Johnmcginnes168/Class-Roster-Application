#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

// Default constructor for Roster class. Initializes SIDIndex and sets all elements of the roster array to nullptr.
Roster::Roster() {
	SIDIndex = -1; // Set the index of the last added student to -1, indicating the roster is empty.
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr; // Initialize each slot of the classRosterArray to nullptr.
	}
}

// Destructor for Roster class. Deletes dynamically allocated Student objects and sets their pointers to nullptr.
Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) { // Check if the current student pointer is not nullptr.
			delete classRosterArray[i]; // Delete the dynamically allocated Student object.
			classRosterArray[i] = nullptr; // Set the pointer to nullptr to avoid dangling references.
		}
	}
}

// Function to add a new student to the class roster. Initializes a new Student object and updates the roster array.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays1, int courseDays2, int courseDays3, DegreeProgram degreeProgram) {
	int courseDays[] = { courseDays1, courseDays2, courseDays3 }; // Store the course days in an array.
	classRosterArray[++SIDIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram); // Add the new Student object to the array.
}

// Function to remove a student from the class roster based on their student ID. Shifts the remaining students to fill the gap.
void Roster::remove(string studentID) {
	bool found = false; // Flag to check if the student was found.
	for (int i = 0; i <= SIDIndex; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) { // If the student with the given ID is found.
			found = true;
			delete classRosterArray[i]; // Delete the student object from memory.
			classRosterArray[i] = classRosterArray[SIDIndex]; // Replace the removed student with the last student in the roster.
			classRosterArray[SIDIndex] = nullptr; // Set the last position to nullptr.
			SIDIndex--; // Decrease the index to reflect the removal.
			break;
		}
	}
	if (!found) {
		cout << "Student with ID " << studentID << " was not found in the roster." << endl; // Notify if the student ID was not found.
	}
}

// Function to print the details of all students in the class roster.
void Roster::printAll() {
	for (int i = 0; i <= SIDIndex; ++i) {
		classRosterArray[i]->print(); // Call the print method of each Student object in the roster.
	}
}

// Function to print the average number of days students take to complete the course, based on their student ID.
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= SIDIndex; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) { // Find the student by ID.
			int* averageDays = classRosterArray[i]->getCourseDays(); // Get the student's course days array.
			// Calculate and display the average of the course days.
			cout << (averageDays[0] + averageDays[1] + averageDays[2]) / 3.0 << endl;
			return;
		}
	}
}

// Function to detect and display invalid email addresses in the roster.
void Roster::printInvalidEmails() {
	for (int i = 0; i <= SIDIndex; i++) {
		string email = classRosterArray[i]->getEmailAddress(); // Get the student's email address.
		// Check if the email is valid (contains '@', '.', and no spaces).
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
			cout << "Invalid Email: " << email << endl; // Output the invalid email.
		}
	}
}

// Function to print the details of students who belong to a specific degree program.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= SIDIndex; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) { // Check if the student matches the given degree program.
			classRosterArray[i]->print(); // Print the student's details.
		}
	}
}

// Function to get the student ID of a student at a given index in the class roster.
string Roster::getSIDIndex(int index) {
	if (index <= SIDIndex) {
		return classRosterArray[index]->getStudentID(); // Return the student ID at the given index.
	}
	return " "; // Return a blank string if the index is out of bounds.
}
