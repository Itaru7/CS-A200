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
	BST();

	// Destructor  
	~BST();

	// destroyTree
	void destroyTree();

	// recursiveInorder
	void recursiveInorder() const;

	// totalNodes
	int totalNodes() const;

	// insert
	void insert(int num);

	// nonRecursiveInorder
	void nonRecursiveInorder() const;

	// nonRecursivePreorder
	void nonRecursivePreorder() const;

	// nonRecursivePostorder
	void nonRecursivePostorder() const;

	//deleteItem
	void deleteItem(int num);

private:
	Node *root; //pointer to the root
	int count;  //number of nodes

	// destroy
	void destroy(Node *&p);

	// recursiveInorder
	void recursiveInorder(Node *p) const;
};

#endif