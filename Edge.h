#ifndef edge_h
#define edge_h

#include<iostream>
using namespace std;

class Edge
{
	friend ostream& operator<<(ostream& out, Edge& e);
	friend bool operator>=(Edge& a, Edge& b);
	friend bool operator>(Edge& a, Edge& b);
	friend bool operator==(Edge& a, Edge& b);
	friend bool operator<(Edge& a, Edge& b);
	friend bool operator<=(Edge& a, Edge& b);
	friend bool operator!=(Edge& a, Edge& b);

	public:
		Edge(int source, int target);
		Edge(int source, int target, int weight);
		int GetSource() const{return _source;}
		int GetWeight() const{return _weight;}
		int GetTarget() const{return _target;}

	private:
		int _source; //Starting vertex of the edge
		int _target; //The vertex to which this edge leads
		int _weight;
};
#endif
