#include "LinkedListGraph.h"

LinkedListGraph::LinkedListGraph()
{}

LinkedListGraph::~LinkedListGraph()
{}

// Declaration function getAdjacentVertices
void LinkedListGraph::getAdjacentVertices(int myArray[], int& numOfElements)
{
	Node* temp = LinkedListGraph::first;
	for (int i = 0; i < LinkedListGraph::length(); i++)
	{
		myArray[i] = temp->getInfo();
		temp++;
		numOfElements++;
	}
}
