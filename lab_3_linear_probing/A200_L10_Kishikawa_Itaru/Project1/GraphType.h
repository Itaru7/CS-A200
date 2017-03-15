#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H

#include "LinkedListGraph.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_SIZE = 50;

class GraphType
{
public:
	GraphType();
		//Default constructor

	GraphType(const GraphType& otherGraph);
		//Copy constructor

	GraphType& operator=(const GraphType& otherGraph);
		//Overloaded assignment operator

	void createGraph(const string& fileName);
		//Creates a graph using the adjacency list
		// representation.

	void printGraph() const;
		//Outputs the graph by showing for 
		// each vertex its successor.

	void clearGraph();
		//Deallocates the memory occupied by the 
		// linked lists and the array.
	
	~GraphType();
		//Destructor

	/*************************************************************************

		Function declarations

	**************************************************************************/

	//Declaration function numberOfSuccessors
	int numberOfSuccessors(int index)const;

	//Declaration function printSuccessors
	void printSuccessors(int index)const;

	//Declaration function numberOfPredecessors
	int numberOfPredecessors(int index) const;

	//Declaration function printPredecessors
	void printPredecessors(int index) const;

protected:
	int maxSize;    //maximum number of vertices
	int gSize;      //current number of vertices

	LinkedListGraph *graph; //array of objects 
							//of type LinkedListGraph to  
							//create the adjacency lists 
};

#endif