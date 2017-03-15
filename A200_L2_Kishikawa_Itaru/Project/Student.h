#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student
{
	// friend function to overload the insertion operator
	friend ostream& operator<<(ostream& out, const Student& s);

public:
	// default constructor
	Student();

	// function setStudentInfo
	void setStudentInfo(const string& newFirst, const string& newLast, int newID);

	// destructor
	~Student();

private:
	int id;
	string fName;
	string lName;
};

#endif