//
//  roster.hpp
//  C867
//
//  Created by William Kee on 11/29/21.
//

#include <iostream>
#include <string>
#include "student.hpp"

using namespace std;

class Roster
{
public:
    Student *classRosterArray[5];
    void parse(string studentData);
    void printAll();
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
    
private:
    int num = -1;
    
};
