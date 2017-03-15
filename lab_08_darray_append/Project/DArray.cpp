#include "DArray.h"

DArray::DArray( )
{
    capacity = 50;
	a = new int[capacity];	
	numOfElements = 0;
}

DArray::DArray(int newCapacity) 
{
	capacity = newCapacity;
    a = new int[capacity];
	numOfElements = 0;	 
}

void DArray::addElement(int newElement)
{
    if (numOfElements >= capacity)
    {
        cerr << "Attempt to exceed capacity in DArray.\n";
        exit(0); 
    }
	else
	{
		a[numOfElements] = newElement;
		++numOfElements;
	}
}

int DArray::getNumOfElements() const
{
	return numOfElements;
}

void DArray::printArray() const
{
	if (numOfElements == 0)
		cerr << "Array is empty." << endl;
	else
	{
		for (int i = 0; i < numOfElements; ++i)
			cout << a[i] << " ";
		cout << endl;
	}
}

DArray::~DArray( )
{
    delete [] a; //delete the array
	a = NULL;	 //null the pointer (not necessary, but good practice)
}

/************************************************************/

// Definition function appendArray


// Definition copy constructor


// Definition overloaded assignment operator


// Definition function emptyArray

