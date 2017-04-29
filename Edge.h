#ifndef edge_h
#define edge_h

#include<iostream>
using namespace std;

class Edge
{
	public:
		Edge(int target);
		Edge(int target, int weight);
		int GetWeight() const{return _weight;}
		int GetTarget() const{return _target;}

	private:
		int _source; //Starting vertex of the edge
		int _target; //The vertex to which this edge leads
		int _weight;
};
#endif
