#ifndef QUEUE_CPP
#define QUEUE_CPP

// project libraries

#include "queue.hpp"

template <typename T> Queue<T>::Queue() {
	


}

template <typename T> Queue<T>::~Queue() {
	


}

template <typename T> Queue<T> * Queue<T>::push(T value) {

	this->length++;

	Node <T> * new_node = new Node<T>(value);

	if (this->head == NULL) {

		this->head = new_node;
		return this;

	}

	for (Node <T> * current = this->head; current != NULL; current = current->next) {

		if (current->next == NULL) {//means we are on the last element
			current->next = new_node;
			break;
		}
	}

	return this;
}

#endif