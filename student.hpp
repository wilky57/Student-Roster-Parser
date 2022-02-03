
#include "degree.h"
#include <iostream>
#include <string>


using namespace std;

class Student
{
    public:
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int numDays[3], DegreeProgram degreeProgram);
        ~Student();
        string GetStudentID() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmailAddress() const;
        int GetAge() const;
        int* GetNumDays();
        DegreeProgram GetDegreeProgram() const;
        void SetStudentID(string studentId);
        void SetFirstName(string firstName);
        void SetLastName(string lastName);
        void SetEmailAddress(string emailAddress);
        void SetAge(int age);
        void SetNumDays(int numDays[3]);
        void SetDegreeProgram(DegreeProgram degreeProgram);
        void print();
    


    private:
        string studentId;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int numDays[3];
        DegreeProgram degreeProgram;

};
