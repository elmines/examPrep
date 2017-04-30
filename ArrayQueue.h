#include "Queue.h"
template<typename T>
class ArrayQueue : public Queue<T>
{
	public:
		ArrayQueue(int capacity);
		~ArrayQueue();
		bool enqueue(T e);
		T dequeue();
		T peek();
		void output();
		bool isEmpty();

	private:
		int capacity, length, front, back;
		T *Array;
};
