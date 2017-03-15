#ifndef BST_H
#define BST_H

#include <string>		
#include <iostream>
#include <stack>
using namespace std;

class Node
{
	friend class BST;
public:
	Node(){}
	~Node(){}
private:
    int data;
    Node *rlink, *llink;
};

class BST
{
public:

	// Default constructor

	// Destructor  

	// Deallocates the memory space occupied by the BST

	// recursiveInorder

	// totalNodes

	// insert

	// nonRecursiveInorder

	// nonRecursivePreorder

	// nonRecursivePostorder

private:
	Node *root; //pointer to the root
	int count;  //number of nodes

	// destroy

	// recursiveInorder
};

#endif