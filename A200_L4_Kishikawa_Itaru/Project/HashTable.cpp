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
	int hValue = hashValue(key, i);
	while (table[hValue] != -1 && i < (capacity + 1) / 2) // linear probing
	{
		if (key == table[hValue])
			return true;
		else
		{
			i++;
			hValue = hashValue(key, i);
		}
	}
	return false;
}

void HashTable::insert(int key)
{
	if (numOfElements == capacity)
		cerr << "Table is full. Cannot insert." << endl;
	else
	{
		int j = 0;
		int index = hashValue(key, j);
		bool inserted = false;

		while (!inserted &&j < (capacity + 1) / 2)
		{
			if (table[index] == -1 || table[index] == -2)
			{
				table[index] = key;
				inserted = true;
			}
			else
			{
				j++;
				index = hashValue(key, j);
			}
		}
		
		//table[index] = key;
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
	//return ((key + (j * STEPSIZE)) % capacity); // linear probing
	return ((2 * key + 5) + (j * j)) % capacity;
}

//deletekey
void HashTable::deleteKey(int key)
{
	if (numOfElements == 0)
		cerr << "Hash table is empty. Cannot delete." << endl;
	else
	{
		int idx = searchKeyIdx(key);

		if (idx == -999)
			cout << "Key not found." << endl;
		else
		{
			table[idx] = -2;
			--numOfElements;
		}
	}
}

//searchKeyIdx
int HashTable::searchKeyIdx(int key) const
{
	int j = 0;
	int hValue = hashValue(key, j);

	while ((table[hValue] != -1) && (j < ((capacity + 1) / 2)))
	{
		if (table[hValue] == key)
			return hValue;
		else
			hValue = hashValue(key, ++j);
	}
	return -999;
}