#ifndef QUEUEASARRAY_H
#define QUEUEASARRAY_H

#include <iostream>

using namespace std;

template<class T>
class QueueAsArray
{
public:

	// Default constructor


	// Overloaded constructor

	
	// isEmptyQueue
		// Function returns true if the queue is empty;
		// otherwise, it returns false.


    // isFullQueue
		// Function returns true if the queue is full;
		// otherwise, it returns false.
	

    // front
		// Function to return the first element of the queue.
		// If queue is empty, program terminates;
 		// otherwise the first element of the queue is returned.  


   // addToQueue
		// Function to add queueElement to the queue.
		// If the queue is full, output error message;
		// otherwise add new element to the queue.


	// popFromQueue
		// Function to remove the first element from the queue.
		// If the queue is emtpy, output error message;
		// otherwise pop front element from the queue.


	// emptyTheQueue
		// Function to empty the queue.
	

	// destroyQueue
		// Function to delete queue from memory and
		// reset member variables to 0.


	// Destructor 
		// Calls function destroyQueue()

private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    T *queueArray;  	//pointer to the array that holds 
     					//the queue elements 
};

#endif
