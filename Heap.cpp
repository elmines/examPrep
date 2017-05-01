#include<iostream>
#include<string>
#include "Heap.h"
#include "Edge.h"
using namespace std;


/*
 * CONSTRUCTORS AND DESTRUCTORS
 */
template<typename T>
Heap<T>::Heap()
{
	this->size = 0;
	this->capacity = 4;
	this->Array = new T[capacity];
	this->ordering = "min";
	//this->ordering = "max";
}

template<typename T>
Heap<T>::Heap(T Array[], int size, string ordering)
{
	this->size = size;
	this->capacity = size * 2;

	this->Array = new T[capacity];
	for (int i = 0; i < size; ++i) (this->Array)[i] = Array[i];

	this->ordering = ordering;

	orderHeap();
}


template<typename T>
Heap<T>::~Heap()
{
	delete[] Array;
}


/*
 * PUBLIC INTERFACE METHODS
 */
template<typename T>
void Heap<T>::insert(T value)
{
	Array[size] = value;
	++size;
	int parentIndex;

	//Initial parentIndex as the index of the parent of the newly added element
	//Continue until the parent index is 0 (we arrive at the root)
	//Move up to the next parent with each iteration
	for ( parentIndex = ((size - 1) - 1 ) / 2; parentIndex > 0; parentIndex = (parentIndex - 1) / 2)
	{
		orderSubtree(parentIndex);
	}

	orderSubtree(parentIndex);
	if (size == capacity) growArray();
}

template<typename T>
T Heap<T>::extract()
{
	T toReturn = Array[0];
	Array[0] = Array[size - 1];
	orderSubtree(0); //Move this newly swapped value down the tree as needed
	--size;
	if ( (size == capacity / 4) && (capacity > 4) ) shrinkArray();
	return toReturn;
}

template<typename T>
void Heap<T>::out()
{
	int i;
	for (i = 0; i < size - 1; ++i) cout << Array[i] << ' ';
	cout << Array[i] << endl;
}

/*
 * HELPER METHODS
 */
template<typename T>
void Heap<T>::shrinkArray()
{
	T* newArray = new T[capacity / 2];		
	for (int i = 0; i < size; ++i) newArray[i] = Array[i];
	delete[] Array;
	Array = newArray;
	capacity /= 2;
}

template<typename T>
void Heap<T>::growArray()
{
	T* newArray = new T[capacity * 2];		
	for (int i = 0; i < size; ++i) newArray[i] = Array[i];
	delete[] Array;
	Array = newArray;
	capacity *= 2;
}

template<typename T>
void Heap<T>::orderHeap()
{
	for (int subTreeRoot = size / 2 - 1; subTreeRoot >= 0; --subTreeRoot) orderSubtree(subTreeRoot);
}

template<typename T>
void Heap<T>::orderSubtree(int parentIndex)
{
	int childIndex;
	Action nextAction = swapType(parentIndex);
	while (nextAction != STAY) //While there are still heap-order violations. . .
	{
		childIndex = (nextAction == SWAP_LEFT) ? (2 * parentIndex + 1) : (2 * parentIndex + 2);
		swap(parentIndex, childIndex);
		parentIndex = childIndex;
		nextAction = swapType(parentIndex);
	}
}

template<typename T>
Action Heap<T>::swapType(int parentIndex)
{
	T leftChild, rightChild;
	if ( (2 * parentIndex + 1) < size) leftChild = Array[2 * parentIndex + 1]; //The node does have a left child
	else                          leftChild = Array[parentIndex];         //There is no right child, so we assign this to prevent swaps

	if ( (2 * parentIndex + 2) < size) rightChild = Array[2 * parentIndex + 2]; //The node does have a right child
	else                          rightChild = Array[parentIndex];         //There is no right child, so we assign this to prevent swaps

	if (ordering == "min")
	{
		if ( (leftChild < Array[parentIndex]) &&
				(leftChild <= rightChild) )
		{
			return SWAP_LEFT;
		}
		else if ( (rightChild < Array[parentIndex]) &&
				(rightChild <= leftChild) )
		{
			return SWAP_RIGHT;
		}
	}
	else if (ordering == "max")
	{
		if ( (leftChild > Array[parentIndex]) &&
				(leftChild >= rightChild) )
		{
			return SWAP_LEFT;
		}
		else if ( (rightChild > Array[parentIndex]) &&
				(rightChild >= leftChild) )
		{
			return SWAP_RIGHT;
		}
	}
	return STAY;
}

template<typename T>
void Heap<T>::swap(int indexA, int indexB)
{
	T temp = Array[indexA];
	Array[indexA] = Array[indexB];
	Array[indexB] = temp;
}

template class Heap<Edge>;
