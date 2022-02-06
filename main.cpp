

#include <iostream>
#include <string>
#include "roster.hpp"


using namespace std;

int main() {
    const string studentData[5] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Jane,Doe,jDOE@ut.edu,29,30,40,21,SOFTWARE" };
   
    Roster classRoster;
    
    for (int j = 0; j < 5; ++j) {
        classRoster.parse(studentData[j]);
    };
    classRoster.printAll();
    
    cout << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();
    
    
    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
        cout << endl;
    }

    classRoster.printByDegreeProgram(SOFTWARE);
   
    cout << "Removing A3:" << endl << endl;
    classRoster.remove("A3");
    
   classRoster.printAll();
    
    cout << "Removing A3 again" << endl << endl;
    classRoster.remove("A3");
    
    classRoster.~Roster();
    
}
