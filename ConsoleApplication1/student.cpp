/* Constructor, accessor, mutator, and print functions for the Student class.*/

#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;


/* Constructor for the Student class.
   Initializes all member variables with provided values. */
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeProgram degreeProgram) {
    this->studentID = studentID;         // Set student ID.
    this->firstName = firstName;         // Set first name.
    this->lastName = lastName;           // Set last name.
    this->emailAddress = emailAddress;   // Set email address.
    this->age = age;                     // Set age.
    for (int i = 0; i < 3; i++) {       // Set course days for the student.
        this->courseDays[i] = courseDays[i];
    }
    this->degreeProgram = degreeProgram; // Set degree program (Security, Network, Software).
}


/* Getter (Accessor) functions.
   These functions return the respective values of the student's attributes. */

   // Return student ID.
string Student::getStudentID() {
    return studentID;
}

// Return first name.
string Student::getFirstName() {
    return firstName;
}

// Return last name.
string Student::getLastName() {
    return lastName;
}

// Return email address.
string Student::getEmailAddress() {
    return emailAddress;
}

// Return age.
int Student::getAge() {
    return age;
}

// Return array of course days.
int* Student::getCourseDays() {
    return courseDays;
}

// Return degree program (Security, Network, or Software).
DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}


/* Setter (Mutator) functions.
   These functions allow setting values for the student's attributes. */

   // Set student ID.
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

// Set first name.
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

// Set last name.
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

// Set email address.
void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

// Set age.
void Student::setAge(int age) {
    this->age = age;
}

// Set course days.
void Student::setCourseDays(int courseDays[]) {
    for (int i = 0; i < 3; i++) {
        this->courseDays[i] = courseDays[i]; // Set the course days array.
    }
}

// Set degree program (Security, Network, or Software).
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}


/* Print function.
   Displays the student's details, including ID, name, email, age, course days, and degree program. */
void Student::print() {
    cout << studentID << "\t"               // Print student ID.
        << "First Name: " << firstName << "\t"  // Print first name.
        << "Last Name: " << lastName << "\t"    // Print last name.
        << "Email Address: " << emailAddress << "\t"  // Print email address.
        << "Age: " << age << "\t\t"             // Print age.
        << "Days to Complete Course: {" << courseDays[0] << "," << courseDays[1] << "," << courseDays[2] << "}\t"  // Print course days.
        << "Degree Program:\t";                 // Print degree program label.

    // Determine and print degree program name.
    if (degreeProgram == 0) { cout << "Security"; }
    if (degreeProgram == 1) { cout << "Network"; }
    if (degreeProgram == 2) { cout << "Software"; }

    cout << endl;  // End of student info line.
}
