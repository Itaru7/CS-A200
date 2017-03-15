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

	cout << endl << endl;
	DArray arr9(4);
	arr9.addElement(345);
	arr9.addElement(9);
	arr9.addElement(71);
	arr9.addElement(1);
	cout << "arr9 is now: ";
	arr9.printArray();
	cout << "After Radic Sort" << endl;
	arr9.radicSort(arr9);
	arr9.printArray();

	cout << endl << endl;
	DArray arr10(4);
	arr10.addElement(345);
	arr10.addElement(9);
	arr10.addElement(71);
	arr10.addElement(1);
	cout << "arr10 is now: ";
	arr10.printArray();
	cout << "After Quick Sort 1" << endl;
	arr10.quickSort1(arr10, 0, 3);
	arr10.printArray();

	cout << endl << endl;
	DArray arr11(4);
	arr11.addElement(345);
	arr11.addElement(9);
	arr11.addElement(71);
	arr11.addElement(1);
	cout << "arr11 is now: ";
	arr11.printArray();
	cout << "After Quick Sort 2" << endl;
	arr11.quickSort2(arr11, 0, 3);
	arr11.printArray();

	cout << endl << endl;
	DArray arr12(4);
	arr12.addElement(345);
	arr12.addElement(9);
	arr12.addElement(71);
	arr12.addElement(1);
	cout << "arr12 is now: ";
	arr12.printArray();
	cout << "After Heap Sort 2" << endl;
	arr12.heapSort(arr12);
	arr12.printArray();


	cout << endl;
	system("Pause");
    return 0;
}

