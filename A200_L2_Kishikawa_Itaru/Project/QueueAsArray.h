#ifndef QUEUEASARRAY_H
#define QUEUEASARRAY_H

#include <iostream>

using namespace std;

template<class T>
class QueueAsArray
{
public:

	// Default constructor
	QueueAsArray();

	// Overloaded constructor
	QueueAsArray(int newSize);
	
	// isEmptyQueue
		// Function returns true if the queue is empty;
		// otherwise, it returns false.
	bool isEmptyQueue() const;

    // isFullQueue
		// Function returns true if the queue is full;
		// otherwise, it returns false.
	bool isFullQueue() const;

    // front
		// Function to return the first element of the queue.
		// If queue is empty, program terminates;
 		// otherwise the first element of the queue is returned.  
	T front() const;

   // addToQueue
		// Function to add queueElement to the queue.
		// If the queue is full, output error message;
		// otherwise add new element to the queue.
	void addToQueue(const T& queueElement);

	// popFromQueue
		// Function to remove the first element from the queue.
		// If the queue is emtpy, output error message;
		// otherwise pop front element from the queue.
	void popFromQueue();

	// emptyTheQueue
		// Function to empty the queue.
	void emptyTheQueue();

	// destroyQueue
		// Function to delete queue from memory and
		// reset member variables to 0.
	void destroyQueue();

	// Destructor 
		// Calls function destroyQueue()
	~QueueAsArray();

private:
    int maxQueueSize;
	int queueFront;
    int queueRear;
    T *queueArray;  	//pointer to the array that holds 
     					//the queue elements 
};

#endif
