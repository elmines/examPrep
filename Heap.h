#ifndef heap_h
#define heap_h

#include<string>
using namespace std;

enum Action{STAY, SWAP_LEFT, SWAP_RIGHT};

template<typename T>
class Heap
{
	public:
		Heap();
		Heap(T Array[], int size, string ordering = "min");
		~Heap();
		void insert(T value);
		T extract();
		void out(); //Level-order output of the values in the heap

	private:
		T* Array;
		int size, capacity;
		string ordering;


		void shrinkArray();
		void growArray();
		void orderHeap();
		void orderSubtree(int parentIndex);
		Action swapType(int parentIndex);
		void swap(int indexA, int indexB);
};

#endif
