/********************************************************************
	Program tests number of comparisons performed 
	by Bubble sort (flagged version), Selection sort, 
	Insertion sort, and Merge Sort.

	Testing can be performed on either a 6-length
	array or a 1000-length random-numbers array.
********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Declaration function bubbleSort
// Running time = O(n^2)
// Uses function swap
void bubbleSort(int myArray[], int &count, int numOfElement);


// Declaration function selectionSort
// Running time = O(n^2)
// Uses function swap
// Uses function minLocation


// Declaration function minLocation
// Running time = O(n)


// Declaration function insertionSort
// Running time: O(n^2) 


// Declaration function mergeSort
// Running time: O(n log n) => this includes the call to function merge
// Uses function merge


// Declaration function merge
// Running time: O(n)


// Already implemented
void print(const int a[], int numOfElements);
void swap(int& n1, int& n2);
void testSmallArray(int a[], int numOfElements);  // testing cases
void testAllSmallArrays();
void testBigArray();

const int SMALL_CAP = 6;
const int BIG_CAP = 1000;

int main()
{
	testAllSmallArrays();

	testBigArray();
	
	cout << endl;
	system("Pause");
	return 0;
}

// Definition function bubbleSort
void bubbleSort(int myArray[], int &count, int numOfElement)
{

}

// Definition function selectionSort


// Definition function minLocation


// Definition function insertionSort


// Definition function mergeSort


// Definition function merge



void print(const int a[], int numOfElements)
{
	for (int i = 0; i < numOfElements; ++i)
		cout << a[i] << " ";
}

void swap(int& n1, int& n2)
{
	int	temp = n1;
	n1 = n2;
	n2 = temp;
}

void testAllSmallArrays()
{
	int numOfElements = SMALL_CAP;

	int a1[] = { 5, 4, 3, 2, 1, 0 };
	testSmallArray(a1, numOfElements);

	int a2[] = { 0, 1, 2, 3, 4, 5 };
	testSmallArray(a2, numOfElements);

	int a3[] = { 3, 4, 5, 0, 1, 2 };
	testSmallArray(a3, numOfElements);

	int a4[] = { 2, 1, 0, 3, 4, 5 };
	testSmallArray(a4, numOfElements);

	int a5[] = { 0, 1, 2, 5, 4, 3 };
	testSmallArray(a5, numOfElements);
}

void testSmallArray(int a[], int numOfElements)
{
	cout << "Array is:\n\n";
	print(a, numOfElements);
	cout << endl;

	int aBubble[SMALL_CAP];
	int aSelection[SMALL_CAP];
	int aInsertion[SMALL_CAP];
	int aMerge[SMALL_CAP];

	//copy arrays
	for (int i = 0; i < numOfElements; ++i)
	{
		aBubble[i] = a[i];
		aSelection[i] = a[i];
		aInsertion[i] = a[i];
		aMerge[i] = a[i];
	}

	//TESTING BUBBLE SORT
	int compBubble = 0;
	bubbleSort(aBubble, compBubble, numOfElements);
	cout << "\nBubble sort:       ";
	print(aBubble, numOfElements);

	//TESTING SELECTION SORT
	int compSelection = 0;
	selectionSort(aSelection, compSelection, numOfElements);
	cout << "\nSelection sort is: ";
	print(a, numOfElements);

	//TESTING INSERTION SORT
	int compInsertion = 0;
	insertionSort(aInsertion, compInsertion, numOfElements);
	cout << "\nInsertion Sort is: ";
	print(a, numOfElements);

	//TESTING MERGE SORT
	int compMergeSort = 0;
	mergeSort(aMerge, compMergeSort, numOfElements);
	cout << "\nMerge Sort is:     ";
	print(a, numOfElements);

	cout << "\n\nResults: " << endl
		<< "    BUBBLE SORT    NUMBER OF COMPARISONS:   " << compBubble
		<< "\n    SELECTION SORT NUMBER OF COMPARISONS:   " << compSelection
		<< "\n    INSERTION SORT NUMBER OF COMPARISONS:   " << compInsertion
		<< "\n    MERGE SORT     NUMBER OF COMPARISONS:   " << compMergeSort
		<< endl;
	cout << "\n\n--------------------------------------------\n";
}

void bigArray(int a[], int& numOfElements)
{
	numOfElements = BIG_CAP;

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < numOfElements; ++i)
		a[i] = 1 + rand() % (numOfElements * 10);
}

void testBigArray()
{
	int numOfElements = BIG_CAP;

	int a[BIG_CAP];

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < numOfElements; ++i)
		a[i] = 1 + rand() % (numOfElements * 10);

	cout << "BIG ARRAY\n";
	//print(a, numOfElements);
	//cout << endl;

	//copy arrays to use with all functions
	int aBubble[BIG_CAP];
	int aSelection[BIG_CAP];
	int aInsertion[BIG_CAP];
	int aMerge[BIG_CAP];

	for (int i = 0; i < numOfElements; ++i)
	{
		aBubble[i] = a[i];
		aSelection[i] = a[i];
		aInsertion[i] = a[i];
		aMerge[i] = a[i];
	}

	////TESTING BUBBLE SORT
	int compBubble = 0;
	bubbleSort(aBubble, compBubble, numOfElements);
	//cout << "\nBubble sort:\n";
	//print(aBubble, numOfElements);

	//TESTING SELECTION SORT
	int compSelection = 0;
	selectionSort(aSelection, compSelection, numOfElements);
	//cout << "\nSelection sort is:\n";
	//print(aSelection, numOfElements);

	////TESTING INSERTION SORT
	int compInsertion = 0;
	insertionSort(aInsertion, compInsertion, numOfElements);
	//cout << "\nInsertion Sort is:\n";
	//print(aInsertion, numOfElements);

	////TESTING MERGE SORT
	int compMergeSort = 0;
	mergeSort(aMerge, compMergeSort, numOfElements);
	//cout << "\nMerge Sort is:\n";
	//print(aMerge, numOfElements);

	cout << "\nResults: " << endl
		<< "    BUBBLE SORT    NUMBER OF COMPARISONS:   " << compBubble
		<< "\n    SELECTION SORT NUMBER OF COMPARISONS:   " << compSelection
		<< "\n    INSERTION SORT NUMBER OF COMPARISONS:   " << compInsertion
		<< "\n    MERGE SORT     NUMBER OF COMPARISONS:   " << compMergeSort
		<< endl;
}

