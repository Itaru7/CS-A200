#include "GraphType.h"

     // default constructor
GraphType::GraphType()  
{
     maxSize = MAX_SIZE;
     graph = new LinkedListGraph[maxSize];
	 gSize = 0;
}

	// copy constructor
GraphType::GraphType(const GraphType& otherGraph)
{
	//implementation
}

	// operator==
GraphType& GraphType::operator=(const GraphType& otherGraph)
{
	//implementation

	return *this;
}

	// createGraph
void GraphType::createGraph(const string& fileName)
{
	//Your code here...

	ifstream infile;
	int vertex;
	int adjacentVertex;

	if (gSize != 0)		//if the graph is not empty, make it empty
		clearGraph();

	infile.open(fileName);

	if (!infile)
	{
		cerr << "Cannot open the input file." << endl;
		system("Pause"); //to check the error message
		exit(1);
	}

	infile >> gSize;  //get the number of vertices

	for (int index = 0; index < gSize; ++index)
	{
		//read the vertex in the graph and its adjacent vertices
		infile >> vertex;
		infile >> adjacentVertex;

		while (adjacentVertex != -999)
		{
			//graph is an array of linked lists
			graph[vertex].insertLast(adjacentVertex);
			infile >> adjacentVertex;
		}
	}

	infile.close();
}

	// printGraph
void GraphType::printGraph() const
{
	//Your code here...

	if (gSize == 0)
		cout << "Graph is empty.\n";
	else
	{
		for (int index = 0; index < gSize; ++index)
		{
			cout << index << " ";
			cout << graph[index];
			cout << endl;
		}
	}

	cout << endl;
}

	// clearGraph
void GraphType::clearGraph()
{
	for (int index = 0; index < gSize; ++index)
		graph[index].destroyList();

	gSize = 0;
}

	//destructor
GraphType::~GraphType()
{
	clearGraph();
}

