#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

// Student class definition
// This class encapsulates all information about a student, including personal details, course days, and degree program.

class Student {

public:

    // Constructor: Initializes a new student with the provided details.
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeProgram degreeProgram);

    // Getter (Accessor) Functions:
    // These functions retrieve the corresponding student details.

    // Get the student ID.
    string getStudentID();

    // Get the first name of the student.
    string getFirstName();

    // Get the last name of the student.
    string getLastName();

    // Get the email address of the student.
    string getEmailAddress();

    // Get the age of the student.
    int getAge();

    // Get the array of course days (days spent on each course).
    int* getCourseDays();

    // Get the degree program of the student (e.g., Security, Network, Software).
    DegreeProgram getDegreeProgram();

    // Setter (Mutator) Functions:
    // These functions allow updating the student's details.

    // Set the student ID.
    void setStudentID(string studentID);

    // Set the first name of the student.
    void setFirstName(string firstName);

    // Set the last name of the student.
    void setLastName(string lastName);

    // Set the email address of the student.
    void setEmailAddress(string emailAddress);

    // Set the age of the student.
    void setAge(int age);

    // Set the array of course days for the student.
    void setCourseDays(int courseDays[]);

    // Set the degree program of the student.
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Print Function:
    // This function outputs all student details, including ID, name, email, age, course days, and degree program.
    void print();

private:

    // Private member variables to store the student's details.
    string studentID;         // The student's ID.
    string firstName;         // The student's first name.
    string lastName;          // The student's last name.
    string emailAddress;      // The student's email address.
    int age;                  // The student's age.
    int courseDays[3];        // Array storing the number of days the student spends in each of the three courses.
    DegreeProgram degreeProgram; // The degree program the student is enrolled in (Security, Network, or Software).
};
