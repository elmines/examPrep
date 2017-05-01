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
	g.BFS(0);
	return 0;
}
