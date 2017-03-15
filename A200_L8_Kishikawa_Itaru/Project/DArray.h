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
	void appendArray(const DArray& myArray);

	// Declaration copy constructor
	DArray(const DArray& myArray);

	// Declaration overloaded assignment operator
	DArray& operator=(const DArray& otherArray);

	// Declaration function emptyArray
	void emptyArray();

	//Heap sort
	void heapSort(const DArray& myArray) const;
	void heapify(const DArray& myArray, int size, int index) const;

	//Radic sort
	void radicSort(const DArray& myArray) const;

	//Quick sort
	void quickSort1(const DArray& myArray, int first, int last) const;
	void quickSort2(const DArray& myArray, int first, int last) const;
	// 1. Partition
	int firstPartition(const DArray& myArray, int first, int last) const;
	// 2. Partition
	int secondPartition(const DArray& myArray, int first, int last) const;
	

private:
    int *a;					//will point to an array of integers
    int capacity;			//capacity of the array
    int numOfElements;		//total number of elements in the array

};

#endif