/*
	This program creates partially-filled 
	arrays of integers.
*/

#include "DArray.h"

#include <iostream>
using namespace std;

int main( )
{
	cout << "CLASS DARRAY\n\n";

	cout << "Append arrays with different number of elements...\n";
	DArray arr1(10);
	arr1.addElement(10);
	arr1.addElement(11);
	arr1.addElement(12);
	arr1.addElement(13);
	arr1.addElement(14);
	DArray arr2(30);
	arr2.addElement(20);
	arr2.addElement(21);
	arr2.addElement(22);
	arr2.addElement(23);
	cout << "arr1: ";
	arr1.printArray();
	cout << "arr2: ";
	arr2.printArray();
	arr1.appendArray(arr2);
	cout << "arr1 is now: ";
	arr1.printArray();

	cout << "\nAppend arrays with second array empty...\n";
	DArray arr3(15);
	arr3.addElement(10);
	arr3.addElement(11);
	arr3.addElement(12);
	arr3.addElement(13);
	arr3.addElement(14);
	cout << "arr3: ";
	arr3.printArray();
	DArray arr4(20);
	cout << "arr4: ";
	arr4.printArray();
	arr3.appendArray(arr4);
	cout << "arr3 is now: ";
	arr3.printArray();

	cout << "\nAppend arrays with first array empty...\n";
	DArray arr5(10);
	cout << "arr5: ";
	arr5.printArray();
	DArray arr6(20);
	arr6.addElement(10);
	arr6.addElement(11);
	arr6.addElement(12);
	arr6.addElement(13);
	arr6.addElement(14);
	arr6.addElement(15);
	cout << "arr6: ";
	arr6.printArray();
	arr5.appendArray(arr6);
	cout << "arr5 is now: ";
	arr5.printArray();

	cout << "\nTry and append arrays with not enough space...\n";
	DArray arr7(10);
	arr7.addElement(10);
	arr7.addElement(11);
	arr7.addElement(12);
	arr7.addElement(13);
	arr7.addElement(14);
	arr7.addElement(15);
	arr7.addElement(16);
	cout << "arr7: ";
	arr7.printArray();
	DArray arr8(20);
	arr8.addElement(20);
	arr8.addElement(21);
	arr8.addElement(22);
	arr8.addElement(23);
	cout << "arr8: ";
	arr8.printArray();
	arr7.appendArray(arr8);
	cout << "arr7 is now: ";
	arr7.printArray();

	cout << endl;
	system("Pause");
    return 0;
}

