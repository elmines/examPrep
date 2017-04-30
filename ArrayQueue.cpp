#include "ArrayQueue.h"
#include<iostream>
using namespace std;

template<typename T>
ArrayQueue<T>::ArrayQueue(int capacity)
{
	this->length = 0;
	this->capacity = capacity;
	this->Array = new T[capacity];
	this->front = 0;
	this->back = 0;
}

template<typename T>
ArrayQueue<T>::~ArrayQueue()
{
	delete[] Array;
}

template<typename T>
bool ArrayQueue<T>::enqueue(T e)
{
	if (length == capacity) return false;

	Array[back] = e;
	back = (back + 1) % capacity;
	++length;
//cerr << "Finished enqueue(): back = " << back << ", length = " << length << endl;
	return true;
}

template<typename T>
T ArrayQueue<T>::dequeue()
{
	if (length == 0) return 0;

	T toReturn = Array[front];
	front = (front + 1) % capacity;
	--length;
	return toReturn;
}

template<typename T>
T ArrayQueue<T>::peek()
{
	if (length == 0) return 0;
	return Array[front];
}

template<typename T>
void ArrayQueue<T>::output()
{
	if (length == 0)
	{
		cout << endl;
		return;
	}

	int i = 0;
	for ( ; i < length - 1; ++i)
	{

		cout << Array[ (front + i) % capacity ] << ", ";

	}
	cout << Array[ (front + i) % capacity ] << endl;
}

template<typename T>
bool ArrayQueue<T>::isEmpty()
{
	return length == 0;
}

template class ArrayQueue<int>;
