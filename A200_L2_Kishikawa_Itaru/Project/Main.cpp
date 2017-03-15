/*
	Name header
*/

#include <iostream>
#include "QueueAsArray.h"
#include "QueueAsArray.cpp"	//need to add the cpp file because of template
#include "Student.h"

using namespace std;

int main()
{
	//QueueAsArray intQueue;			// When testing the non-template version,
										//  you need to uncomment #include "QueueAsArray.cpp"
	QueueAsArray<int> intQueue;
	intQueue.addToQueue(4);
	intQueue.addToQueue(5);
	cout << "Inserted 4 and 5...";
	cout << "\nFront of the queue: " << intQueue.front();
	cout << "\nRemove all elements...";
	intQueue.emptyTheQueue();	
	intQueue.addToQueue(9);
	intQueue.addToQueue(7);
	intQueue.addToQueue(3);
	intQueue.addToQueue(2);	

	cout << "\nInserted 9, 7, 3, 2";
	cout << "\nFront of the queue: " << intQueue.front();
	cout << "\nQueue Elements: ";
	while(!intQueue.isEmptyQueue())
	{
		cout <<" "<< intQueue.front();
		intQueue.popFromQueue();		
	}	

	cout << endl;

	QueueAsArray<Student> objQueue(30);

	Student bob;
	bob.setStudentInfo("Bob", "Peterson", 111);
	Student jane;
	jane.setStudentInfo("Jane", "Smith", 222);
	Student jill;
	jill.setStudentInfo("Jill", "Johnson", 333);
	Student dean;
	dean.setStudentInfo("Dean", "Grayson", 444);

	objQueue.addToQueue(bob);
	objQueue.addToQueue(jane);
	cout << "\nInserted bob and jane...";
	cout << "\nFront of the queue: " << objQueue.front();
	cout << "\nRemove all elements...";
	objQueue.emptyTheQueue();	
	objQueue.addToQueue(jill);
	objQueue.addToQueue(dean);
	objQueue.addToQueue(jane);
	objQueue.addToQueue(bob);
	cout << "\nInserted jill, dean, jane, bob";

	cout << "\nQueue Elements: ";

	while(!objQueue.isEmptyQueue())
	{
		cout << "\n" << objQueue.front();
		objQueue.popFromQueue();		
	}

	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}
