#include<iostream>
#include "Node.h"
using namespace std;



int main(void)
{
	Node<int>* head = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, NULL)))));
	Node<int>* ptr = head;

	while (ptr != NULL)
	{
		cout << ptr->GetValue();
		ptr = ptr->GetNext();
	}
	return 0;
}
