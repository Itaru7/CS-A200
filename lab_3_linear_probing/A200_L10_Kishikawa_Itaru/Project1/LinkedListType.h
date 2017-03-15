#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	Node() : info(0), link(nullptr){}
    Node(int theInfo, Node *theLink) : info(theInfo), link(theLink){}
    Node *getLink( ) const { return link; }
    int getInfo( ) const { return info; }
    void setInfo(int theInfo) { info = theInfo; }
    void setLink(Node *theLink) { link = theLink; }
	~Node(){}
private:
    int info;		
    Node *link;	
};

class LinkedListType
{
	friend ostream& operator<<(ostream& out, const LinkedListType& theList);

public:	
	
	LinkedListType(); 
   		//Default constructor initializes the list to an empty state.

	LinkedListType(const LinkedListType& otherList);
		//Copy constructor

	const LinkedListType& operator=(const LinkedListType& otherList);
		//Overloaded assignment operator
	
	void insertFirst(int newItem);
		//Inserts newItem at the beginning of the list.

	void insertLast(int newItem);
		//Inserts newItem at the end of the list.

    bool isEmptyList() const;
 		//Returns true if the list is empty, false otherwise.

	int length() const;
		//Returns the number of nodes in the list.

    int front() const; 
 		//Returns the first element of the list.
		//If list is empty, terminates the program.

    int back() const; 
		//Returns the last element of the list.
		//If list is empty, terminates the program.

    void initializeList(); 
 		//Initializes the list to an empty state.
	
	void destroyList();
		//Deletes all nodes in the list and resets all
		// member variables to a default value.
	
	~LinkedListType();   
    	//Destructor 
	
protected:
    int count;		//variable to store the number of 
 						//elements in the list
    Node *first;	//pointer to the first node of 
						//the list
    Node *last;		//pointer to the last node of 
                        //the list 

};

#endif

