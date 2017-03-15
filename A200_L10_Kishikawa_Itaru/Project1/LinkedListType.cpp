#include "LinkedListType.h"

	// operator<<
ostream& operator<<(ostream& out, const LinkedListType& theList)
{
	if (theList.count == 0)
		out << "No elements in the list.";
	else
	{
		Node *current = theList.first;

		while (current != nullptr)
		{
			out << current->getInfo() << " ";
			current = current->getLink();
		}
	}

	return out;
}

	// default constructor
LinkedListType::LinkedListType() 
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

	// copy constructor
LinkedListType::LinkedListType(const LinkedListType& otherList)
{
	//implementation
}

	//overload the assignment operator
const LinkedListType& LinkedListType::operator=(const LinkedListType& otherList)
{
	//implementation

	return *this;
}

	// insertFirst
void LinkedListType::insertFirst(int newItem)
{
	first = new Node(newItem, first);
	++count;

	if (last == nullptr) last = first;
}

	// insertLast
void LinkedListType::insertLast(int newItem)
{
	Node *newNode = new Node(newItem, 0);
            								
	if(first == nullptr) first = newNode;	
	else last->setLink(newNode);		

	last = newNode;
	++count;
}

	// isEmptyList
bool LinkedListType::isEmptyList() const
{
	return (first == nullptr);
}

	// length
int LinkedListType::length() const
{
 	return count;
}

	// front
int LinkedListType::front() const
{   
   if (count == 0)
   {
		cerr << "No elements in the list.\n";
		system("Pause"); //to check error message
		exit(1);
   }
   else
   		return first->getInfo();	
}

	// back
int LinkedListType::back() const
{   
	if (count == 0)
    {
		cerr << "No elements in the list.\n";
		system("Pause"); //to check error message
		exit(1);
    }
	 else
   		return last->getInfo();		
}

	// initializeList
void LinkedListType::initializeList()
{
	destroyList();		//if the list has any nodes, delete them
}

	// destroyList
void LinkedListType::destroyList()
{
	while(first != nullptr)   
	{
	   Node *temp = first;
	   first = first->getLink();	
	   delete temp;					
	}

	last = nullptr;	                   
 	count = 0;
}

	// destructor
LinkedListType::~LinkedListType() 
{
	destroyList(); 
}




