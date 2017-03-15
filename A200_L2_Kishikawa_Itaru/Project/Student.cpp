#include "Student.h"

// friend function to overload insertion operator
ostream& operator<<(ostream& out, const Student& s)
{
	out << s.id << " - " << s.lName << ", " << s.fName;
	return out;
}

// default constructor
Student::Student()
{
	id = 0;
}

// function setStudentInfo
void Student::setStudentInfo(const string& newFirst, const string& newLast, int newID)
{
	id = newID;
	fName = newFirst;
	lName = newLast;
}


// destructor
Student::~Student()
{}