#include<iostream>
using namespace std;
template<typename T>
class Node
{
	public:
		//Node();
		Node(T value, Node* next);
		T GetValue() const {return _value;}
		Node<T>* GetNext() const {return _next;}

	private:
		T _value;
		Node* _next;
}
