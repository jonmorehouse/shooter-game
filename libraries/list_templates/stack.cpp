#ifndef STACK_CPP
#define STACK_CPP

//project libraries
#include "stack.hpp"

// namespaces
using namespace std;


/******* CONSTRUCTORS / DESTRUCTORS *******/
template <typename T> Stack<T>::Stack() : List_base<T>() {
	
	

	
}

template <typename T> Stack<T>::~Stack() {

	
		
}

/********** VIEWER / GETTER FUNCTIONS **********/

template <typename T> Node<T> * Stack<T>::front() {
	
	return this->head;

}


/************ WORKER FUNCTIONS ************/

template <typename T> Stack<T> * Stack<T>::push(T value) {
	
	Node<T> * new_node = new Node<T>(value);
	
	this->length++;

	new_node->next = this->head;

	this->head = new_node;

	return this;
}

template <typename T> Stack<T> * Stack<T>::pop() {
	
	this->length--;

	Node<T> * delete_node = this->head;

	this->head = this->head->next;

	delete delete_node;

	return this;

}



#endif