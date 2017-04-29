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

	int source, target, weight;
	bool weighted;

	if (!edges)
	{
		cerr << "Graph::Graph() Error: could not open " << filePath << endl;
		exit(-1);
	}
	
	//Read in count at beginning of file
	edges >> _count;
	edges >> weighted;
	adjacenyList = new Node<Edge>*[_count];
	memset(adjacencyList, NULL, _count * sizeof(Node<Edge>*));

	//While there are still edges to be read
	while (edges >> source)
	{
		edges >> target;
		weight = 1;
		if (weighted) edges >> weight;

		Edge newEdge(source, target, weight);

		Node<Edge>* ptr = adjacencyList[i];
		while (ptr != NULL) ptr = ptr->GetNext();
		ptr = new Node(newEdge, NULL);
	}

	edges.close();	
}	

void Graph::PrintAdjacencyList()
{

}

void Graph::DFS(int source)
{
	//Examine a vertex
	//Examine each adjacent, unvisited vertex
	//Stop when there are no vertices to visit
};


void Graph::DFSHelper(int vertex)
{
}	
