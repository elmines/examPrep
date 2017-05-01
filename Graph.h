#ifndef graph_h
#define graph_h

#include<iostream>
#include "Node.h"
#include "Edge.h"
#include "Heap.h"
using namespace std;

class Graph
{
	public:
		Graph(char* filePath);
		void PrintAdjacencyList();
		void DFS(int source);
		void BFS(int source);
		Node<Edge>* PrimMST();

	private:
		//void DFSHelper(int vertex);

		int _numVertices, _numEdges;
		int *_visited;
		int *_predecessor; //For minimum spanning tree algorithms

		Node<Edge>** _adjacencyList; //Use array indices to index to the list for particular vertex, and Node::GetNext() to iterate over that list	


		void DFSHelper(int predecessor, int source, int depth);
		void AddEdge(Edge& e);
		Heap<Edge>* GenHeap();
		bool ExpandsMST(const Edge& e);

};
#endif
