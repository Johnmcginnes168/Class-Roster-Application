#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

// Roster class definition
// This class manages a collection of students in the roster, allowing for adding, removing, and printing student information.

class Roster {

public:

    // Constructor: Initializes the Roster, setting up the array of pointers for student data.
    Roster();

    // Destructor: Cleans up dynamically allocated memory for the student objects in the roster.
    ~Roster();

    // Add a new student to the roster.
    // This function sets the student's details and updates the roster array.
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays1, int courseDays2, int courseDays3, DegreeProgram degreeProgram);

    // Remove a student from the roster by their student ID.
    // This function deletes the student from the roster array and shifts remaining students.
    void remove(string studentID);

    // Print all students in the roster.
    // This function loops through the array of students and prints each student’s information.
    void printAll();

    // Print the average number of days in a course for a specific student by their student ID.
    void printAverageDaysInCourse(string studentID);

    // Print invalid email addresses from the roster.
    // This function checks and displays emails that don't match proper formatting.
    void printInvalidEmails();

    // Print all students in a specific degree program (e.g., Security, Network, Software).
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // Get the student ID at a specific index in the roster array.
    // This function retrieves the student ID for a given index in the class roster.
    string getSIDIndex(int index);

    // Index variable to track the current number of students in the roster.
    int SIDIndex;

    // Array of student pointers (classRosterArray) to hold the roster of students.
    // This array stores the individual student objects.
    Student* classRosterArray[5];
};
