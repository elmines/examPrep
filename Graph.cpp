#include<iostream>
#include<cstring>
#include<fstream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
using namespace std;

Graph::Graph(char* filePath)
{
	ifstream edges;
	edges.open(filePath);

	int source, target, weight;
	bool weighted;

	if (!edges)
	{
		throw "Graph::Graph() error: Could not open file.\n";	
	}

	//Read in count at beginning of file
	edges >> _numVertices;
	edges >> weighted;

	_adjacencyList = new Node<Edge>*[_numVertices];
	_visited = new int[_numVertices];
	_predecessor = new int[_numVertices];

	memset(_adjacencyList, 0, _numVertices * sizeof(Node<Edge>*));
	memset(_visited, 0, _numVertices * sizeof(int) );
	memset(_predecessor, 0, _numVertices * sizeof(int) );

	_numEdges = 0;
	//While there are still edges to be read
	while (edges >> source)
	{
		edges >> target;
		weight = 1;
		if (weighted) edges >> weight;

		Edge newEdge(source, target, weight);

		if (_adjacencyList[source] == NULL) _adjacencyList[source] = new Node<Edge>(newEdge, NULL);
		else
		{
			Node<Edge>* ptr = _adjacencyList[source];
			while (ptr->GetNext() != NULL) ptr = ptr->GetNext();
			ptr->SetNext(new Node<Edge>(newEdge, NULL) );
		}
		++_numEdges;
	}

	edges.close();	
}	

void Graph::PrintAdjacencyList()
{
	Node<Edge>* ptr;
	for (int i = 0; i < _numEdges; ++i)
	{
		cout << "Vertex " << i << ": ";
		ptr = _adjacencyList[i];

		while (ptr != NULL)
		{
			Edge e = ptr->GetValue();
			cout << e << ", ";
			ptr = ptr->GetNext();
		}
		cout << endl;
	}
}



/*
   void Graph::DFS(int source)
   {
//Examine a vertex
//Examine each adjacent, unvisited vertex
//Stop when there are no vertices to visit
};


void Graph::DFSHelper(int vertex)
{
}	
*/
