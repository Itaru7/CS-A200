#include "GraphType.h"

// Definition function numberOfSuccessors
int  GraphType::numberOfSuccessors(int index)const
{
	int *myArray = new int[gSize];
	int sucesors = 0;
	//graph->getAdjacentVertices(myArray[index], sucesors);
	return sucesors;
}


// Definition function printSuccessors
void GraphType::printSuccessors(int index)const
{
	if (numberOfSuccessors(index) > 0)
		cout << numberOfSuccessors(index) << endl;
	else
		cout << "No successors." << endl;
}

// Definition function numberOfPredecessors
int GraphType::numberOfPredecessors(int index) const
{

}

// Definition function printPredecessors
void GraphType::printPredecessors(int index) const
{
	if (numberOfPredecessors(index) > 0)
		cout << numberOfPredecessors(index) << endl;
	else
		cout << "No successors." << endl;
}