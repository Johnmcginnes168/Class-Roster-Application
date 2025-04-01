#include <iostream>
#include <string>
#include "roster.h"
using namespace std;


int main() {
    
    //F.1 Printing out course title, programming language, my student ID, and name

    cout << "Class Roster Application" << endl;
    cout << "Language: C++" << endl;
    cout << "Name: John McGinnes" << endl;

    //F.2 Creating an instance of Roster class called classRoster

    Roster classRoster;


    //A. This section modifies the provided Student Data Table to include my information as the last line.

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,John,McGinnes,jmcgi98@wgu.org\t,36,15,17,18,SOFTWARE"
    };

    //E.2a,b Parsing studentData to populate the class roster
    
    for (int i = 0; i < 5; i++) {
        size_t rhs = 0;
        size_t lhs = 0;
        lhs = studentData[i].find(",", rhs);
        string studentID = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        string firstName = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        string lastName = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        string emailAddress = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        int age = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        int daysInCourse1 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        int daysInCourse2 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        int daysInCourse3 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        string degreeString = studentData[i].substr(rhs, lhs - rhs);
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
        
        //F.3 Adding students to Class Roster
    
        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
        }

        //F.4 Calling the classRoster.printAll() function;

        cout << "\nAll students in the Roster:" << endl;
        cout << endl;
        classRoster.printAll();
        cout << endl;


        //F.4 Calling the classRoster.printInvalidEmails() function;

        cout << "Detecting invalid emails:" << endl;
        cout << endl;
        classRoster.printInvalidEmails();
        cout << endl;

        //F.4 Looping through the classRoster array for each element and calling the classRoster.printAverageDaysInCourse (current_object's student id) function. Using the accessor as instructed

        for (int i = 0; i < 5; i++) {
            cout << "Average days to complete course for Student ID " << classRoster.getSIDIndex(i) << ": ";
            classRoster.printAverageDaysInCourse(classRoster.getSIDIndex(i));
        }
        cout << endl;

        //F.4 Calling the classRoster.printByDegreeProgram(SOFTWARE) function;

        cout << "All students in the Software degree program: " << endl;
        cout << endl;
        classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
        cout << endl;

        //F.4 Calling the classRoster.remove function for Student ID A3
        
        cout << "Removing Student A3 from the roster:" << endl;
        classRoster.remove("A3");

        cout << endl;

        cout << "All students in the roster:" << endl;
        cout << endl;
        classRoster.printAll();
        cout << endl;

        cout << "Removing Student A3 again:" << endl;
        cout << endl;
        classRoster.remove("A3");

        //F.4 The line above will print a message saying such a student with this ID was not found.

       //F.5 Implementing the destructor to release the dynamically allocated memory

        classRoster.~Roster();

        return 0;
    };



    