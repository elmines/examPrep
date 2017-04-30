#include <iostream>
#include "Edge.h"
using namespace std;

Edge::Edge(int source, int target) : _source(source), _target(target), _weight(1)
{
}

Edge::Edge(int source, int target, int weight) : _source(source), _target(target), _weight(weight)
{
}

ostream& operator<<(ostream& out, Edge& e)
{
	out << '(' << e._source << ")--" << e._weight << "--(" << e._target << ')';
	return out;
}
