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

void BST::deleteItem(int num)
{
	Node* current = root;
	Node* temp = root;
	if (current->data == num)
	{
		current = current->llink;
		while (current->rlink != NULL)
		{
			temp = current;
			current = current->rlink;
		}

		root->data = current->data;
		if (current->llink != NULL)
			temp->rlink = current->llink;
		else
			temp->rlink = NULL;

		current->llink = NULL;
		current->rlink = NULL;
		current = NULL;
		delete current;
		count--;
	}	
	else if (current->data > num)
	{
		current = current->llink;
		bool found = false;
		while (!found && current != NULL)
		{
			if (current->data == num)
				found = true;
			else if (current->data > num)
			{
				temp = current;
				current = current->llink;
			}
			else
			{
				temp = current;
				current = current->rlink;
			}
		}

		if (current == NULL)
			cerr << num << " is not in the tree." << endl;
		else
		{
			if (current->llink == NULL && current->rlink == NULL && temp->llink == current)
				temp->llink = NULL;
			else if (current->llink == NULL && current->rlink == NULL && temp->rlink == current)
				temp->rlink = NULL;
			else if (current->llink != NULL && current->rlink == NULL && temp->rlink == current)
				temp->rlink = current->llink;
			else if (current->llink != NULL && current->rlink == NULL && temp->llink == current)
				temp->llink = current->llink;
			else if (current->rlink != NULL && current->llink == NULL)
				temp->llink = current->rlink;
			else if (current->llink != NULL && current->rlink != NULL)
			{
				Node* origin = current;
				temp = current;
				current = current->rlink;

				while (current->llink != NULL)
				{
					temp = current;
					current = current->llink;
				}

				origin->data = current->data;
				if (current->rlink != NULL)
					temp->llink = current->rlink;
				else if (temp->llink == current)
					temp->llink = NULL;
				else
					temp->rlink = NULL;
			}
			current->llink = NULL;
			current->rlink = NULL;
			current = NULL;
			delete current;
			count--;
		}
	}
	else
	{
		current = current->rlink;
		bool found = false;
		while (!found && current != NULL)
		{
			if (current->data == num)
				found = true;
			else if (current->data > num)
			{
				temp = current;
				current = current->llink;
			}
			else
			{
				temp = current;
				current = current->rlink;
			}
		}
		if (current == NULL)
			cerr << num << " is not in the tree." << endl;
		else
		{
			if (current->llink == NULL && current->rlink == NULL && temp->rlink == current)
				temp->rlink = NULL;
			else if (current->llink == NULL && current->rlink == NULL && temp->llink == current)
				temp->llink = NULL;
			else if (current->llink != NULL && current->rlink == NULL && temp->rlink == current)
				temp->rlink = current->llink;
			else if (current->llink != NULL && current->rlink == NULL && temp->llink == current)
				temp->llink = current->llink;
			else if (current->rlink != NULL && current->llink == NULL && temp->llink == current)
				temp->llink = current->rlink;
			else if (current->rlink != NULL && current->llink == NULL && temp->rlink == current)
				temp->rlink = current->rlink;
			else if (current->llink != NULL && current->rlink != NULL)
			{
				Node* origin = current;
				temp = current;
				current = current->rlink;

				while (current->llink != NULL)
				{
					temp = current;
					current = current->llink;
				}

				origin->data = current->data;
				if (current->rlink != NULL)
					temp->rlink = current->rlink;
				else if (temp->rlink == current)
					temp->rlink = NULL;
				else
					temp->llink = NULL;
			}
			current->llink = NULL;
			current->rlink = NULL;
			current = NULL;
			delete current;
			count--;
		}
	}


	/*Node* current = root;
	Node* temp = current;
	if (current->data == num)
	{
		current = current->llink;
		while (current->rlink != NULL)
		{
			temp = current;
			current = current->rlink;
		}
		if (current->rlink == NULL && current->llink != NULL)
		{
			temp->rlink = current->llink;
			root->data = current->data;
			current = NULL;
			delete current;
		}
		else
		{
			temp->llink = current->rlink;
			root->data = current->data;
			current = NULL;
			delete current;
		}
	}
	else if (current->data > num)
	{
		temp = current;
		current = current->llink;
		bool found = false;
		while (!found)
		{
			if (current->data == num)
				found = true;

			else if (current->data < num)
			{
				temp = current;
				current = current->rlink;
			}
			else
			{
				temp = current;
				current = current->llink;
			}

		}
		
		if (current->llink == NULL && current->rlink == NULL)
		{
			current = NULL;
			delete current;
		}
		else if (current->rlink == NULL && current->llink != NULL)
		{
			temp->rlink = current->llink;
			root->data = current->data;
			current = NULL;
			delete current;
		}
		else if (current->llink == NULL && current->rlink != NULL)
		{
			temp->llink = current->rlink;
			root->data = current->data;
			current = NULL;
			delete current;
		}
		else
		{
			Node* origin = current;
			temp = current;
			current = current->rlink;
			while (current->llink != NULL)
			{
				temp = current;
				current = current->llink;
			}
			origin->data = current->data;
			temp->llink = NULL;
			current = NULL;
			delete current;
		}
	}
	else
	{
		
	}
	count--;*/
}