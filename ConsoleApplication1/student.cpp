/* Section D.2: Constructor, accessor, mutator, and print functions for the student class.*/

#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;


//Section D.2d: Constructor Function

	Student::Student (string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeProgram degreeProgram) {
		this->studentID = studentID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->emailAddress = emailAddress;
		this->age = age;
		for (int i = 0; i < 3; i++) {
			this->courseDays[i] = courseDays[i];
		}
		this->degreeProgram = degreeProgram;
	}


//Section D.2a: Getters (Accessors) Function

		string Student::getStudentID() {
			return studentID;
		};
		string Student::getFirstName() {
			return firstName;
		};
		string Student::getLastName() {
			return lastName;
		};
		string Student::getEmailAddress() {
			return emailAddress;
		};
		int	Student::getAge() {
			return age;
		};
		int* Student::getCourseDays() {
			return courseDays;
		};
		DegreeProgram Student::getDegreeProgram() {
			return degreeProgram;
		};


//Section D.2b: Setters (Mutators) Function

		void Student::setStudentID(string studentID) {
			this->studentID = studentID;
		}
		void Student::setFirstName(string firstName) {
			this->firstName = firstName;
		}
		void Student::setLastName(string lastName) {
			this->lastName = lastName;
		}
		void Student::setEmailAddress(string emailAddress) {
			this->emailAddress = emailAddress;
		}
		void Student::setAge(int age) {
			this->age = age;
		}
		void Student::setCourseDays(int courseDays[]) {
			for (int i = 0; i < 3; i++) {
				this->courseDays[i] = courseDays[i];
			}
		}
		void Student::setDegreeProgram(DegreeProgram degreeProgram) {
				this->degreeProgram = degreeProgram;
		}

//Section D.2e: Print Function

		void Student::print() {
			cout << studentID << "\t" 
				<< "First Name: " << firstName << "\t"
				<< "Last Name: " << lastName << "\t" 
				<< "Email Address: " << emailAddress << "\t"
				<< "Age: " << age << "\t\t" 
				<< "Days to Complete Course: {" << courseDays[0] << "," << courseDays[1] << "," << courseDays[2] << "}\t"
				<< "Degree Program:\t";
			if (degreeProgram == 0) { cout << "Security"; };
			if (degreeProgram == 1) { cout << "Network"; };
			if (degreeProgram == 2) { cout << "Software"; };
			cout << endl;
		}
	

