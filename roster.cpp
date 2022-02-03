

#include <iostream>
#include <string>
#include "roster.hpp"
using namespace std;

Roster::~Roster() {
    
    cout << "DONE." << endl;
    return;
}

void Roster::parse(string studentData) {
    
    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    size_t lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    string first = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string last = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs +1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int num1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int num2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int num3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degreeProgram = studentData.substr(lhs, rhs - lhs);
    
    DegreeProgram program = DegreeProgram::SOFTWARE;
    
    if(degreeProgram == "SECURITY") {
        program = DegreeProgram::SECURITY;
    }
    else if (degreeProgram == "SOFTWARE") {
        program = DegreeProgram::SOFTWARE;
    }
    else if (degreeProgram == "NETWORK") {
        program = DegreeProgram::NETWORK;
    };
    
    this->add(studentID, first, last, email, age, num1, num2, num3, program);
    
        }

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
   this->classRosterArray[++num]=new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);         }
    
    



void Roster::printAll() {
    cout << "Displaying all students:" << endl;
    for (int i = 0; i < sizeof(classRosterArray)/ sizeof(classRosterArray[i]); ++i) {
        if (classRosterArray[i] == nullptr)
                {
                    continue;
                }
        else {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}
   
   
void Roster::remove(string studentID)
{
    bool remove = false;
    for (int i = 0; i < sizeof(classRosterArray)/ sizeof(classRosterArray[i]); i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[i + 1];
            delete classRosterArray[i + 1];
            classRosterArray[i + 1] = nullptr;
            remove = true;
        }
    }
    if (remove == false) {
        cout << "The student with the ID " << studentID << " was not found" << endl;
    }
}


void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < sizeof(classRosterArray)/ sizeof(classRosterArray[i]); ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            cout << "StudentID: " << studentID << ", average days in course is: " << (classRosterArray[i]->GetNumDays()[0] + classRosterArray[i]->GetNumDays()[1] + classRosterArray[i]->GetNumDays()[2]) / 3 << endl;
        }
    }
    
}

void Roster::printInvalidEmails() {
    //cout << "printInvalidEmails IS WORKING" << endl;
    bool atSign = false;
    bool period = false;
    bool noSpaces = true;
    bool invalidEmail = false;
    for (int i = 0; i < sizeof(classRosterArray)/ sizeof(classRosterArray[i]); ++i) {
        string email = classRosterArray[i]->GetEmailAddress();
        for (int j = 0; j < email.size(); ++j) {
            if (email[j] == '@') {
                atSign = true;
            }
            if (email[j] == '.') {
                period = true;
            }
            if (email[j] == ' ') {
                noSpaces = false;
            }
        }
        if (noSpaces == false) {
            invalidEmail = true;
        }
        if (atSign == false) {
            invalidEmail = true;
        }
        if (period == false) {
            invalidEmail = true;
        }
        if (invalidEmail == true) {
            cout << email << " - is invalid." << endl;
        }
        atSign = false;
        period = false;
        noSpaces = true;
        invalidEmail = false;
        }
    cout << endl;
}



void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < sizeof(classRosterArray)/ sizeof(classRosterArray[i]); ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();            
        }
    }
    cout << endl;
}
    
    

