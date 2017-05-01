#include<iostream>
#include<cstring>
#include<fstream>
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include "ArrayQueue.h"
#include "Heap.h"
using namespace std;

Graph::Graph(char* filePath)
{
	ifstream edges;
	edges.open(filePath);

	int source, target, weight;
	bool weighted, directed;

	if (!edges)
	{
		throw "Graph::Graph() error: Could not open file.\n";	
	}

	//Read in count at beginning of file
	edges >> _numVertices;
	edges >> weighted;
	edges >> directed;

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

		Edge forwards(source, target, weight);
		AddEdge(forwards);

		//Add the edge twice if the graph is undirected
		if (!directed)
		{
			Edge backwards(target, source, weight);
			AddEdge(backwards);
		}

	}

	edges.close();	
}	

void Graph::PrintAdjacencyList()
{
	Node<Edge>* ptr;
	for (int i = 0; i < _numVertices; ++i)
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




void Graph::DFS(int source)
{
	DFSHelper(-1, source, 0);

}

void Graph::BFS(int source)
{
	int* distance = new int[_numVertices];
	ArrayQueue<int> vertexQueue(_numVertices);

	vertexQueue.enqueue(source);
	_visited[source] = true;
	_predecessor[source] = -1;
	distance[source] = 0;

	while (!vertexQueue.isEmpty())
	{
		int currVertex = vertexQueue.dequeue();
		cout << "Visited vertex " << currVertex << ", " << distance[currVertex] << " edges from the source." << endl;
		//Could do a calculation on the vertex here

		Node<Edge>* edge = _adjacencyList[currVertex];
		while (edge != NULL)
		{
			int adjacentVertex = edge->GetValue().GetTarget();
			if (!_visited[adjacentVertex])
			{
				vertexQueue.enqueue(adjacentVertex);
				_visited[adjacentVertex] = true;
				_predecessor[source] = currVertex;			
				distance[adjacentVertex] = distance[currVertex] + 1;
			}
			edge = edge->GetNext();
		}
	}	
	delete[] distance;
}

Node<Edge>* Graph::PrimMST()
{
	Heap<Edge>* h = GenHeap();
	Node<Edge> *Source, *MST;
	int edgesAdded;

	cout << "Generated heap." << endl;
	h->out();
	cout << endl;

	MST = NULL;
       	edgesAdded = 0;

	while ( (edgesAdded < (_numVertices - 1)) && (!h->IsEmpty()) )
	{
		Edge nextEdge = h->extract();
		if (ExpandsMST(nextEdge)) 
		{
			if (MST == NULL) Source = MST = new Node<Edge>(nextEdge, NULL);
			else
			{
				MST->SetNext(new Node<Edge>(nextEdge, NULL));
				MST = MST->GetNext();
			}
		}
	}
	return Source;
}





void Graph::DFSHelper(int predecessor, int vertex, int depth)
{
	if (_visited[vertex]) return;

	_visited[vertex] = true;
	if (predecessor >= 0) _predecessor[vertex] = predecessor;

	for (int i = 0; i < depth; ++i) cout << '\t';
	cout << "Visited vertex " << vertex << endl;
	//Could do a calculation on the vertex here

	Node<Edge>* adjacentVertex = _adjacencyList[vertex];
	while (adjacentVertex != NULL)
	{
		DFSHelper(vertex, adjacentVertex->GetValue().GetTarget(), depth + 1);
		adjacentVertex = adjacentVertex->GetNext();
	}
}	

void Graph::AddEdge(Edge& e)
{

		if (_adjacencyList[e.GetSource()] == NULL) _adjacencyList[e.GetSource()] = new Node<Edge>(e, NULL);
		else
		{
			Node<Edge>* ptr = _adjacencyList[e.GetSource()];
			while (ptr->GetNext() != NULL) ptr = ptr->GetNext();
			ptr->SetNext(new Node<Edge>(e, NULL) );
		}
		++_numEdges;
}

Heap<Edge>* Graph::GenHeap()
{
	Heap<Edge>* h = new Heap<Edge>;

	for (int i = 0; i < _numVertices; ++i)
	{
		Node<Edge>* ptr = _adjacencyList[i];
		while (ptr != NULL)
		{
			h->insert(ptr->GetValue());
			ptr = ptr->GetNext();
		}
	}
	return h;
}	


/*
 * Helper function for Graph::PrimMST()
 * Returns true if adding e will expand the subtree while not creating a cycle
 */
inline bool Graph::ExpandsMST(const Edge& e)
{
	return (_visited[e.GetSource()] ^ _visited[e.GetTarget()]);

}


