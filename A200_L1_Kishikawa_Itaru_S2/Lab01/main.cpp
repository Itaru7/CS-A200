/*
	Itaru Kishikawa
	CS A200
	February 4, 2016

	Lab 01
*/

#include<iostream>

using namespace std;

void processStacks(int *&newp, int &newMax, int &newplace);
void printSmallValues(int *&a, int place, int max);
void printLargeValues(int *&a, int place);

int main()
{
	int *p = new int;
	int max = 0;
	int place = 0;
	processStacks(p, max,place);

	printSmallValues(p, place, max);
	printLargeValues(p, place);

	cout << endl;
	system("Pause");
	return 0;
}

void processStacks(int *&newp, int &newMax, int &newplace)
{
	cout << "Enter max number of intergers: ";
	cin >> newMax;
	newp = new int [newMax];
	
	int num = 0;
	newplace = newMax - 1;
	int i = 0;
	cout << "Enter integers (-1 to quit): ";
	int j = 0;
	while (num > -1 && j < newMax)
	{
		cin >> num;

		if (num >= 1000)
		{
			newp[i] = num;
			i++;
		}
		else if (num > -1 && num < 1000)
		{
			newp[newplace] = num;
			newplace--;
		}
		j++;
	}
}

void printSmallValues(int *&a, int place, int max)
{
	place++;
	cout << "Stack with small values: ";
	while (place < max)
	{
		cout << a[place] << " ";
		place++;
	}
	cout << endl;
}

void printLargeValues(int *&a, int place)
{
	cout << "Stack with large values: ";	
	while (place > -1)
	{
		if (a[place] >= 1000)
			cout << a[place] << " ";
		place--;
	}
	cout << endl;
}