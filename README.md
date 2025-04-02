Class Roster Application
Overview
The Class Roster Application is designed to manage and manipulate student data in a class roster. It demonstrates the use of object-oriented principles in C++, such as classes, objects, encapsulation, dynamic memory management, and enumerations. This project helps you practice handling student information, detecting and correcting invalid email addresses, calculating average course completion times, filtering students by degree program, and managing memory with a custom destructor.

The program provides an interactive way to:

View a list of students with detailed information.

Detect and print invalid email addresses.

Calculate and display the average number of days each student spends completing their courses.

Filter students by their degree program (Security, Network, or Software).

Remove students from the roster by their student ID.

Demonstrate dynamic memory management by using a custom destructor.

Features
Roster Management: Create, update, and manage a class roster by adding and removing students.

Email Validation: Detect invalid email addresses based on basic email format rules.

Average Days in Course: Calculate the average number of days students spend in their courses and display the result.

Degree Program Filtering: Filter and list students based on their degree program (e.g., Software, Network, Security).

Student Removal: Remove students from the roster by their student ID, and handle attempts to remove non-existent students gracefully.

Dynamic Memory Management: The program uses dynamic memory allocation for student objects and properly deallocates memory using a custom destructor.

File Structure
The project includes the following files:

main.cpp: Contains the main program logic that interacts with the Roster and Student classes.

roster.cpp: Implementation file for the Roster class, managing the class roster and related operations.

student.cpp: Implementation file for the Student class, holding student information and operations.

roster.h: Header file for the Roster class, declaring its methods and member variables.

student.h: Header file for the Student class, declaring its methods and member variables.

degree.h: Header file that defines the DegreeProgram enum, listing available degree types (Security, Network, Software).

Requirements
To compile and run the program, you will need:

A C++ compiler that supports C++11 or later (e.g., GCC, Clang, MSVC).

An IDE or text editor for modifying the source code (optional).

For compiling the program, ensure your compiler supports C++11 or later, as certain features rely on C++11.

Instructions
1. Compilation
To compile the program, use the following command (assuming you have the necessary C++ development environment set up):

bash
Copy
g++ main.cpp roster.cpp student.cpp -o ClassRoster
This will generate an executable file named ClassRoster.

2. Running the Program
Once compiled, you can run the program with the following command:

bash
Copy
./ClassRoster
3. Program Behavior
Upon running the program, the following actions will occur:

Introduction: The program prints a brief introduction to the class roster.

Display Roster: The program displays the full roster of students, including details like student ID, name, email address, age, and days spent in courses.

Invalid Emails: It checks and prints out any invalid email addresses found in the roster.

Average Course Completion Time: The program calculates and displays the average number of days each student takes to complete their courses.

Filter by Degree Program: It filters and prints all students in the "Software" degree program (you can modify this to filter by other programs like Security or Network).

Student Removal: It removes a student with a specific student ID (e.g., A3) from the roster, then prints the updated roster.

Repeated Removal: It attempts to remove the same student again and prints a message if the student is not found.

Example Output:
![Screenshot of Output](ConsoleApplication1/images/Class%20Roster%20Application%20Output.jpg)

Functionality Overview
Student Data
The program uses a predefined array studentData[] to store sample student information. The data is parsed, and the class roster is populated using this information.

Class Roster
The Roster class manages the student data. Its key functions include:

add(): Adds a new student to the roster.

printAll(): Prints the details of all students in the roster.

printInvalidEmails(): Identifies and prints any invalid email addresses.

printAverageDaysInCourse(): Calculates and prints the average number of days a student takes to complete their courses.

printByDegreeProgram(): Filters students based on their degree program and prints those students.

remove(): Removes a student from the roster using their student ID.

Destructor
The program includes a destructor in the Roster class that ensures dynamic memory allocated for student objects is properly deallocated when the program finishes execution.

Known Issues
The current email validation logic checks only basic patterns, such as the presence of an "@" symbol and a "." symbol, which may not handle all edge cases. Future improvements could include more robust email validation.

If a student is removed from the roster and then an attempt is made to remove them again, the program will print a message indicating that the student was not found in the roster.

License
This project is open-source and free to use. Feel free to modify and extend it as needed. Contributions are welcome!

