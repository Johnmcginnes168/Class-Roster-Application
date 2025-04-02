#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {

    // Output course information and student details
    cout << "Class Roster Application" << endl;
    cout << "Language: C++" << endl;
    cout << "Name: John McGinnes" << endl;

    // Create an instance of the Roster class to manage the student roster
    Roster classRoster;

    // Define student data, including personal information and course details
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,John,McGinnes,jmcgi98@wgu.org\t,36,15,17,18,SOFTWARE"
    };

    // Parse student data and populate the roster with individual student details
    for (int i = 0; i < 5; i++) {
        size_t rhs = 0;
        size_t lhs = 0;

        // Extract student ID, first name, last name, email, age, days in course, and degree program
        lhs = studentData[i].find(",", rhs); // Find and extract the student ID
        string studentID = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs); // Extract first name
        string firstName = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs); // Extract last name
        string lastName = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs); // Extract email address
        string emailAddress = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs); // Extract age
        int age = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs); // Extract days in course (for all three courses)
        int daysInCourse1 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs); // Extract second days in course
        int daysInCourse2 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs); // Extract third days in course
        int daysInCourse3 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs); // Extract degree program
        string degreeString = studentData[i].substr(rhs, lhs - rhs);

        // Determine the student's degree program
        DegreeProgram degreeProgram = SOFTWARE;
        if (degreeString == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else if (degreeString == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        else if (degreeString == "SECURITY") {
            degreeProgram = SECURITY;
        }

        // Add the parsed student data to the roster
        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }

    // Output all students currently in the roster
    cout << "\nAll students in the Roster:" << endl;
    cout << endl;
    classRoster.printAll();
    cout << endl;

    // Output invalid email addresses from the roster
    cout << "Detecting invalid emails:" << endl;
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    // Output the average days to complete the course for each student
    for (int i = 0; i < 5; i++) {
        cout << "Average days to complete course for Student ID " << classRoster.getSIDIndex(i) << ": ";
        classRoster.printAverageDaysInCourse(classRoster.getSIDIndex(i));
    }
    cout << endl;

    // Output all students enrolled in the Software degree program
    cout << "All students in the Software degree program: " << endl;
    cout << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;

    // Remove a student (A3) from the roster and output updated roster
    cout << "Removing Student A3 from the roster:" << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "All students in the roster:" << endl;
    cout << endl;
    classRoster.printAll();
    cout << endl;

    // Attempt to remove the same student again, output will indicate not found
    cout << "Removing Student A3 again:" << endl;
    cout << endl;
    classRoster.remove("A3");

    // The line above will print a message indicating that the student with ID A3 was not found.

    // Destructor is automatically called when the object goes out of scope, but we can explicitly call it to release resources if needed
    classRoster.~Roster();

    return 0;
};
