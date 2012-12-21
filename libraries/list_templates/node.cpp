#ifndef NODE_CPP
#define NODE_CPP

#include "node.hpp"

using namespace std;

template <typename T> Node<T>::Node(T value) {
		
	this->data = value;

	this->next = NULL;
	this->prev = NULL;
}	


#endif
