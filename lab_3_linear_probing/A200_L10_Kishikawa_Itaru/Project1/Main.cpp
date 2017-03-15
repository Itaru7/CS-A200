/****************************************************************

	Test cases for functions in GraphType class:
		numberOfSuccessors()
		printSuccessors()
		numberOfPredecessors()
		printPredecessors()

	Use file graph_data.txt

****************************************************************/

#include "GraphType.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string fileName;
	cout << "Enter the input file name including the extension: ";
	cin >> fileName;
	cout << endl; 

	GraphType g1;
	g1.createGraph(fileName);
	g1.printGraph();

	int vertex = -1;
	char again = 'y';
	while (again != 'n')
	{
		cout << "\nEnter a vertex: ";
		cin >> vertex;

		if (vertex < 0 || vertex > 10)
		{
			cout << "There is no vertex " << vertex << "." << endl;
		}
		else
		{
			cout << "    Number of successors: ";
			cout << g1.numberOfSuccessors(vertex) << " -> ";
			g1.printSuccessors(vertex);
			cout << endl;

			cout << "    Number of predecessors: ";
			cout << g1.numberOfPredecessors(vertex) << " -> ";
			g1.printPredecessors(vertex);
			cout << endl;
		}

		cout << "\nTry again? (y/n) ";
		cin >> again;
	}

	cout << endl;
	system("Pause");
	return 0;
}
