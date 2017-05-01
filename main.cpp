#include<iostream>
#include "Graph.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "No file given." << endl;
		return 1;
	}

	Graph g(argv[1]);
	g.PrintAdjacencyList();
	//g.BFS(0);
	//
	//
	Node<Edge>* MST = g.PrimMST();
	Node<Edge>* ptr = MST;

	cout << ptr << endl;

	cout << "Prim MST:" << endl;
	while (ptr)
	{
		Edge e = ptr->GetValue();
		cout << "At least obtained the first value." << endl;
		cout << e << endl;
		ptr = ptr->GetNext();
	}
		
	return 0;
}
