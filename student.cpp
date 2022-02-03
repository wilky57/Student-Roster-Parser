
#include "student.hpp"
#include <iostream>
#include <string>

using namespace std;

//constructor and destructor;
    Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int numDays[3], DegreeProgram degreeProgram) {
        this->studentId = studentId;
        this->firstName = firstName;
        this->lastName = lastName;
        this->emailAddress = emailAddress;
        this->age = age;
        this->numDays[0] = numDays[0];
        this->numDays[1] = numDays[1];
        this->numDays[2] = numDays[2];
        this->degreeProgram = degreeProgram;
}

    Student::~Student() {}

// GETTER FUNCTIONS
    string Student::GetStudentID() const {
        return studentId;
        }

    string Student::GetFirstName() const {
        return firstName;
        }

    string Student::GetLastName() const {
        return lastName;
        }

    string Student::GetEmailAddress() const {
        return emailAddress;
        }

    int Student::GetAge() const {
        return age;
        }

    int* Student::GetNumDays() {
        return numDays;
        }

    DegreeProgram Student::GetDegreeProgram() const {
        return degreeProgram;
        }

//SETTER FUNCTIONS
    void Student::SetStudentID(string studentId) {
        this->studentId = studentId;
        }
    void Student::SetFirstName(string firstName) {
        this->firstName = firstName;
        }
    void Student::SetLastName(string lastName) {
        this->lastName = lastName;
        }
    void Student::SetEmailAddress(string emailAddress) {
        this->emailAddress = emailAddress;
        }
    void Student::SetAge(int age) {
        this->age = age;
        }
    void Student::SetNumDays(int numDays[3]) {
        this->numDays[0] = numDays[0];
        this->numDays[1] = numDays[1];
        this->numDays[2] = numDays[2];
        }
    void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
        this->degreeProgram = degreeProgram;
        }

//PRINT FUNCTION

    void Student::print() {
        string degPro;
        
        if (degreeProgram == DegreeProgram::SECURITY){
            degPro = "Security";
        }
        else if (degreeProgram == DegreeProgram::NETWORK) {
            degPro = "Network";
        }
        else if (degreeProgram == DegreeProgram::SOFTWARE){
            degPro = "Software";
        }
        cout << studentId << "\t" << "First Name: "<< firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t" << "daysInCourse: " << "{"<<  numDays[0] << ", " << numDays[1] << ", " << numDays[2] << "}" << "   Degree Program: " << degPro << endl;
    
}
