#ifndef QUEUE_HPP
#define QUEUE_HPP

// project libraries
#include "list_base.hpp"


/*

	Queue = remove from front, put on back 


*/

template <typename T>

class Queue : public List_base<T> {

	public://functions
		Queue();
		~Queue();

	public://getter / viewer functions
		virtual Queue<T> * push(T value);

};

#include "queue.cpp"

typedef Queue<int> Int_queue;

#endif