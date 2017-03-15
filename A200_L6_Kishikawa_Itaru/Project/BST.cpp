/*
	Itaru Kishikawa
	CS A200
	March 3, 2016

	Lab 06
*/
#include "BST.h"

// default constructor
BST::BST()
{
	root = NULL;
	count = 0;
}

// destructor
BST::~BST()
{
	destroyTree();
}

// destroyTree
void BST::destroyTree()
{
	destroy(root);
	count = 0;
}

// destroy
void BST::destroy(Node *&p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

// recursiveInorder
void BST::recursiveInorder() const
{
	if (root == NULL)
		cerr << "There is no tree.";
	else
		recursiveInorder(root);
	
}

// recursiveInorder
void BST::recursiveInorder(Node *p) const
{
	if (p != NULL)
	{
		recursiveInorder(p->llink);
		cout << p->data << " ";
		recursiveInorder(p->rlink);
	}
}

// totalNodes
int BST::totalNodes() const
{
	return count;
}

/***************************************************************************************************

	Functions to implement:
			- insert (non-recursive)
			- nonRecursiveInorder
			- nonRecursivePreorder
			- nonRecursivePostorder

			-insert (recursive)
			-search (recursive)

***************************************************************************************************/

//insert (non-recursive)
void BST::insert(int num)
{
	Node *temp = new Node;
	temp->data = num;
	temp->llink = NULL;
	temp->rlink = NULL;

	if (count == 0)
	{
		root = temp;
		count++;
	}
	else
	{
		bool sameNum = false;
		bool insert = false;
		Node* current = root;

		while (current != NULL && !sameNum && !insert)
		{
			if (current->data == num)
				sameNum = true;
			else
			{
				if (num < current->data)
					if (current->llink == NULL)
					{
						current->llink = temp;
						insert = true;
					}
					else
						current = current->llink;
				else
				{
					if (current->rlink == NULL)
					{
						current->rlink = temp;
						insert = true;
					}
					else
						current = current->rlink;
				}
				count++;
			}
		}
		if (sameNum)
			cerr << "The item to insert is already in the list. Duplicates are not allowed.";
	}
}

//nonRecursiveInorder
void BST::nonRecursiveInorder() const
{
	if (count == 0)
		cerr << "There is no tree.";
	else
	{
		Node *current = root;
		stack <Node*> myStack;

		while (current != NULL || !myStack.empty())
		{
			if (current != NULL)
			{
				myStack.push(current);
				current = current->llink;
			}
			else
			{
				current = myStack.top();
				myStack.pop();
				cout << current->data << " ";
				current = current->rlink;
			}
		}
	}
}

//nonRecursivePreorder
void BST::nonRecursivePreorder() const
{
	if (count == 0)
		cerr << "There is no tree.";
	else
	{
		Node *current = root;
		stack <Node*> myStack;

		while (current != NULL || !myStack.empty())
		{
			if (current != NULL)
			{
				cout << current->data << " ";
				myStack.push(current);
				current = current->llink;
			}
			else
			{
				current = myStack.top();
				myStack.pop();
				current = current->rlink;
			}
		}
	}
}




//nonRecursivePostorder
void BST::nonRecursivePostorder() const
{
	if (count == 0)
		cerr << "There is no tree.";
	else
	{
		Node* current = root;
		stack <Node*> myStack;
		stack <int> myInt;
		int value = 0;
		myStack.push(current);
		myInt.push(1);
		current = current->llink;

		while (!myStack.empty() && !myInt.empty())
		{
			if (current != NULL && value == 0)
			{
				myInt.push(1);
				myStack.push(current);
				current = current->llink;
			}
			else
			{
				current = myStack.top();
				value = myInt.top();
				myStack.pop();
				myInt.pop();

				if (value == 1)
				{
					myStack.push(current);
					myInt.push(2);
					current = current->rlink;
					value = 0;
				}
				else
					cout << current->data << " ";
			}
		}
	}
}
