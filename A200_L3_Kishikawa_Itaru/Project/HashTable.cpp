#include "HashTable.h"

ostream& operator<<(ostream& out, const HashTable& myTable)
{
	for (int i = 0; i < CAPACITY; i++)
	{
		out << "Index " << i << ": ";

		if (myTable.table[i] != -1)
			out << myTable.table[i];
		else
			out << "E";

		cout << endl;
	}
	return out;
}

HashTable::HashTable()
{
	numOfElements = 0;
	capacity = CAPACITY;

	table = new int[capacity];

	for (int i = 0; i < capacity; i++)
		table[i] = -1;
}

HashTable::HashTable(int newCapacity)
{
	capacity = newCapacity;
	numOfElements = 0;
	table = new int[capacity];

	for (int i = 0; i < capacity; i++)
		table[i] = -1;
}

HashTable::HashTable(const HashTable& otherTable)
{
	numOfElements = otherTable.numOfElements;
	capacity = otherTable.capacity;

	table = new int[capacity];

	for (int i = 0; i < capacity; i++)
		table[i] = otherTable.table[i];
}

bool HashTable::search(int key) const
{
	int i = 0;
	bool result = false;
	while (i < capacity && table[i] != -1 && !result)
	{
		if (key == table[i])
			result = true;
		i++;
	}
	return result;
}

void HashTable::insert(int key)
{
	if (numOfElements == capacity)
		cerr << "Table is full. Cannot insert." << endl;
	else
	{
		int index = hashValue(key, 0);
		int i = 1;
		while (table[index] != -1)
		{
			index = hashValue(key, i);
			i++;
		}
		
		table[index] = key;
		numOfElements++;
	}
}

int HashTable::getCapacity() const
{
	return capacity;
}

HashTable& HashTable::operator=(const HashTable& otherTable)
{
	if (&otherTable != this)
	{
		if (capacity != otherTable.capacity)
		{
			delete[] table;
			table = new int[otherTable.capacity];

				capacity = otherTable.capacity;
		}

		numOfElements = otherTable.numOfElements;
		for (int i = 0; i < capacity; i++)
			table[i] = otherTable.table[i];
	}
	else
	{
		cerr << "Attempted assignment to itself." << endl;
	}

	return *this;
}

int& HashTable::operator[](int index)
{
	return table[index];
}

HashTable::~HashTable()
{
	delete []table;
	table = NULL;
}

int HashTable::hashValue(int key, int j) const
{
	return ((key + (j * STEPSIZE)) % capacity);
}