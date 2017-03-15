#include "QueueAsArray.h"

template<class T>
QueueAsArray<T>::QueueAsArray()
{
	maxQueueSize = 50;
	queueFront = 0;
	queueRear = 0;

	queueArray = new T[maxQueueSize];
}

// Overloaded constructor
template<class T>
QueueAsArray<T>::QueueAsArray(int newSize)
{
	maxQueueSize = newSize;
	queueFront = 0;
	queueRear = 0;

	queueArray = new T[maxQueueSize];
}

// isEmptyQueue
// Function returns true if the queue is empty;
// otherwise, it returns false.
template<class T>
bool QueueAsArray<T>::isEmptyQueue() const
{
	return (queueFront == queueRear);
}

// isFullQueue
// Function returns true if the queue is full;
// otherwise, it returns false.
template<class T>
bool QueueAsArray<T>::isFullQueue() const
{
	return ((maxQueueSize - queueFront + queueRear) % maxQueueSize) == (maxQueueSize - 1);
}

// front
// Function to return the first element of the queue.
// If queue is empty, program terminates;
// otherwise the first element of the queue is returned.  
template<class T>
T QueueAsArray<T>::front() const
{
	if (queueFront == queueRear)
	{
		cerr << "Queue is empty." << endl;
		system("Pause");
		exit(0);
	}
	else
		return queueArray[queueFront];
}

// addToQueue
// Function to add queueElement to the queue.
// If the queue is full, output error message;
// otherwise add new element to the queue.
template<class T>
void QueueAsArray<T>::addToQueue(const T& queueElement)
{
	if (isFullQueue())
		cerr << "The queue is full." << endl;
	else
	{
			queueArray[queueRear] = queueElement;
			queueRear = (queueRear + 1) % maxQueueSize;
	}
}

// popFromQueue
// Function to remove the first element from the queue.
// If the queue is emtpy, output error message;
// otherwise pop front element from the queue.
template<class T>
void QueueAsArray<T>::popFromQueue()
{
	if (isEmptyQueue())
		cerr << "The queue is empty." << endl;
	else
		queueFront = (queueFront + 1) % maxQueueSize;
}

// emptyTheQueue
// Function to empty the queue.
template<class T>
void QueueAsArray<T>::emptyTheQueue()
{
	queueFront = 0;
	queueRear = 0;
}

// destroyQueue
// Function to delete queue from memory and
// reset member variables to 0.
template<class T>
void QueueAsArray<T>::destroyQueue()
{
	delete[] queueArray;
	queueArray = NULL;
	queueFront = 0;
	queueRear = 0;
}

// Destructor 
// Calls function destroyQueue()
template<class T>
QueueAsArray<T>::~QueueAsArray()
{
	destroyQueue();
}

