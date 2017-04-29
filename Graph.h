#ifndef graph_h
#define graph_h

#include<iostream>
#include "Node.h"
#include "Edge.h"
using namespace std;

class Graph
{
	public:
		Graph(char* filePath);

	private:
		int _count;
		int *_visited;
		int *_predecessor; //For minimum spanning tree algorithms

		Node<Edge>** adjacencyList; //Use array indices to index to the list for particular vertex, and Node::GetNext() to iterate over that list	
};
#endif
