#include<iostream>
#include "Node.h"
#include "Edge.h"
using namespace std;

template<typename T>
Node<T>::Node(T value, Node<T>* next) : _value(value), _next(next)
{
}

template<typename T>
Node<T>::~Node()
{
	if (this->_next != NULL) delete this->_next;
}

template class Node<int>;
template class Node<Edge>;
