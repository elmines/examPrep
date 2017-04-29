#include<iostream>
#include<fstream>
#include "Graph.h"
#include "Edge.h"
#include "Node.h"
using namespace std;

Graph::Graph(char* filePath)
{
	ifstream edges;
	edges.open(filePath);

	int source, target;

	if (!filePath)
	{
		cerr << "Graph::Graph() Error: could not open " << filePath << endl;
		exit(-1);
	}
	
	//Read in count at beginning of file
	cin >> _count;
	adjacenyList = new Node<Edge>[_count];
	memset(adjacencyList, NULL, _count * sizeof(Node<Edge>*));

	for (int i = 0; i < count; ++i)
	{
		cin >> source;
		cin >> target;


		Edge newEdge(source, target);

		Node<Edge>* ptr = adjacencyList[i];
		while (ptr != NULL) ptr = ptr->GetNext();
		ptr = new Node(newEdge, NULL);
	}

		
}	

void Graph::DFS()
{
	//Examine a vertex
	//Examine each adjacent, unvisited vertex
	//Stop when there are no vertices to visit
};


void Graph::DFSHelper(int vertex)
{
}	
