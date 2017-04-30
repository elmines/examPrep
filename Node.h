#ifndef node_h
#define node_h

#include<iostream>
using namespace std;
template<typename T>
class Node
{
	public:
		//Node();
		Node<T>(T value, Node<T>* next);
		~Node();
		T GetValue() const {return _value;}

		Node<T>* GetNext() const {return _next;}
		void SetNext(Node<T>* next){_next = next;}

	private:
		T _value;
		Node<T>* _next;
};

#endif
