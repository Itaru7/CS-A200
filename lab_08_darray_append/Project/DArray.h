#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray
{
public:
    DArray( );

    DArray(int newCapacity);

    void addElement(int newElement);

	int getNumOfElements() const;

	void printArray() const;
	
	~DArray( ); 

	/************************************************************/

	// Declaration function appendArray


	// Declaration copy constructor


	// Declaration overloaded assignment operator


	// Declaration function emptyArray

private:
    int *a;					//will point to an array of integers
    int capacity;			//capacity of the array
    int numOfElements;		//total number of elements in the array

};

#endif