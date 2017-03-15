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
void DArray::appendArray(const DArray& myArray)
{
	if (myArray.numOfElements > 0)
	{
		if (myArray.numOfElements > capacity - numOfElements)
			cerr << "Not enough space to append elements." << endl;
		else
		{
			for (int i = 0; i < myArray.numOfElements; i++)
				addElement(myArray.a[i]);
		}
	}
}

// Definition copy constructor
DArray::DArray(const DArray& myArray)
{
	a = myArray.a;
	numOfElements = myArray.numOfElements;
	capacity = myArray.capacity;
}


// Definition overloaded assignment operator
DArray& DArray::operator=(const DArray& otherArray)
{
	if (&otherArray != this)
	{
		if (capacity != otherArray.capacity)
		{
			delete[] a;
			a = new int[otherArray.capacity];
			capacity = otherArray.capacity;
		}
		for (int i = 0; i < otherArray.numOfElements; i++)
			a[i] = otherArray.a[i];
		numOfElements = otherArray.numOfElements;
	}
	return *this;
}


// Definition function emptyArray
void DArray::emptyArray()
{
	delete[] a;
	a = NULL;
	numOfElements = 0;
	capacity = 0;
}

//Heap sort
void DArray::heapSort(const DArray& myArray) const
{
	for (int i = myArray.numOfElements / 2 - 1; i >= 0; i--)
		heapify(myArray, myArray.numOfElements, i);

	for (int i = myArray.numOfElements - 1; i >= 0; i--)
	{
		swap(myArray.a[0], myArray.a[i]);
		heapify(myArray, i, 0);
	}
}

void DArray::heapify(const DArray& myArray, int size, int index) const
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && myArray.a[left] > myArray.a[largest])
		largest = left;

	 if (right < size && myArray.a[right] > myArray.a[largest])
		largest = right;

	if (largest != index)
	{
		swap(myArray.a[index], myArray.a[largest]);
		heapify(myArray, size, largest);
	}
}

//Radic Sort
void DArray::radicSort(const DArray& myArray) const
{
	int* bucket = new int[myArray.capacity];
	int maxVal = 0;
	int i = 0;
	int digitposition = 1;

	for (i = 0; i < myArray.numOfElements; i++)
		if (myArray.a[i] > maxVal)
			maxVal = myArray.a[i];

	while (maxVal / digitposition > 0)
	{
		int digitCount[10] = { 0 };
		
		for (i = 0; i < myArray.numOfElements; i++)
			digitCount[myArray.a[i] / digitposition % 10]++;

		for (i = 1; i < 10; i++)
			digitCount[i] += digitCount[i - 1];

		for (i = myArray.numOfElements - 1; i >= 0; i--)
			bucket[--digitCount[myArray.a[i] / digitposition % 10]] = myArray.a[i];

		for (i = 0; i < myArray.numOfElements; i++)
			a[i] = bucket[i];

		digitposition *= 10;
	}
	
	delete[] bucket;
	bucket = NULL;



	//int *bucket = new int[myArray.capacity];
	//int maxVal = 0;
	//int digitPosition = 1;
	//int i = 0;

	//for (i = 0; i < myArray.numOfElements; i++)
	//	if (myArray.a[i] > maxVal)
	//		maxVal = myArray.a[i];
	//
	//while (maxVal / digitPosition > 0)
	//{
	//	int digitCount[10] = { 0 };

	//	for (i = 0; i < myArray.numOfElements; i++)
	//		digitCount[myArray.a[i] / digitPosition % 10]++;

	//	for (i = 1; i < 10; i++)
	//		digitCount[i] += digitCount[i - 1];

	//	for (i = myArray.numOfElements - 1; i >= 0; i--)
	//		bucket[--digitCount[myArray.a[i] / digitPosition % 10]] = myArray.a[i];

	//	for (i = 0; i < myArray.numOfElements; i++)
	//		myArray.a[i] = bucket[i];

	//	digitPosition *= 10;
	//}

	//delete[] bucket;
	//bucket = NULL;
}

//Quick sort 1
void DArray::quickSort1(const DArray& myArray, int first, int last) const
{
	if (first < last)
	{
		int pivot = firstPartition(myArray, first, last);
		quickSort1(myArray, first, pivot - 1);
		quickSort1(myArray, pivot + 1, last);
	}
}

// 1. Partition
int DArray::firstPartition(const DArray& myArray, int first, int last) const
{
	int pivot = myArray.a[(first + last) / 2];
	
	while (first <= last)
	{
		while (myArray.a[first] < pivot)
			first++;
		while (myArray.a[last] > pivot)
			last--;

			swap(myArray.a[first], myArray.a[last]);
			first++;
			last--;
	}
	return first;
}

//Quick sort 2
void DArray::quickSort2(const DArray& myArray, int first, int last) const
{
	if (first < last)
	{
		int pivot = secondPartition(myArray, first, last);
		quickSort2(myArray, first, pivot - 1);
		quickSort2(myArray, pivot + 1, last);
	}
}
// 2. Partition
int DArray::secondPartition(const DArray& myArray, int first, int last) const
{
	int pivot = (first + last) / 2;
	swap(myArray.a[pivot], myArray.a[first]);
	pivot = first;

	int h = pivot;
	int k = pivot + 1;

	while (k <= last)
	{
		if (myArray.a[k] < myArray.a[pivot])
		{
			swap(myArray.a[h + 1], myArray.a[k]);
			h++;
			k++;
		}
		else
			k++;
	}
	swap(myArray.a[pivot], myArray.a[h]);
	return h;
}