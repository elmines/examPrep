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

	private:
		T _value;
		Node<T>* _next;
};
