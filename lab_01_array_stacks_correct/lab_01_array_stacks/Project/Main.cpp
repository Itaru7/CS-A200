#include <iostream>
using namespace std;

// Declaration of function processStacks
void processStacks(int*, int, int&, int&);
// Declaration of function printSmallValues
void printSmallValues(int*, int);
// Declaration of function printLargeValues
void printLargeValues(int*, int, int);

int main()
{
	int cap, leftTop, rightTop;

	cout << "Enter max number of integers: ";	
	cin >> cap;

	int *a = new int[cap] ;

	// call to function processStacks
	processStacks(a, cap, leftTop, rightTop);
	// call to function printSmallValues
	printSmallValues(a, leftTop);
	// call to function printLargeValues
	printLargeValues(a, rightTop, cap);
	// what else?
	a = NULL;
	delete[] a;

	cout << endl;
	system("Pause");
	return 0;
}

// Definition of function processStacks
void processStacks(int* a, int cap, int &small, int &large)
{
	int num = 0;
	small = 0;
	large = cap - 1;
	int i = 0;
	cout << "Enter integers (-1 to quit): ";
	while (num >= 0 && i < cap)
	{
		cin >> num;
		if (num <= 1000 && num > 0)
		{
			a[small] = num;
			small ++;
		}
		else if (num > 1000)
		{
			a[large] = num;
			large--;
		}
		i++;
	}
}

// Definition of function printSmallValues
void printSmallValues(int* a, int small)
{
	small--;
	cout << "Stack with small values: ";
	while (small >= 0)
	{
		cout << a[small] << " ";
		small--;
	}
	cout << endl;
}

// Definition of function printLargeValues
void printLargeValues(int* a, int large, int cap)
{
	large++;
	cout << "Stack with large values: ";
	while (large < cap)
	{
		cout << a[large] << " ";
		large++;
	}
	cout << endl;
}