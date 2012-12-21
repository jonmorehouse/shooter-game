#ifndef LIST_BASE_CPP
#define LIST_BASE_CPP

// c++ libraries

// library includes
#include "list_base.hpp"

// namespaces
using namespace std;

/******** CONSTRUCTOR / DESTRUCTORS **********/
template <typename T> List_base<T>::List_base() {
	
	this->head = NULL;
	this->size = 0;
	this->length = 0;

}

template <typename T> List_base<T>::~List_base() {
		
	Node <T> * delete_node;

	for (Node<T> * _current = this->head; _current != NULL; _current = _current->next) {

		delete_node = _current;

		delete delete_node;
	}

}

/********** VIEWER / GETTER FUNCTIONS **********/
template <typename T>Node<T> * List_base<T>::front() {
	
	return this->head;

}

template <typename T>List_base<T> * List_base<T>::print() {
	
	// need to ensure that the cout >> operator is implemented
	// this will come later -- c++ does not compile if a function does not exist at compile time
	/*

	if (this->length > 0) {
	
		for (Node<T> * _current = this->head; _current != NULL; _current = _current->next)
			cout << _current->data << " ";
	}	

	else cout << "Empty List.";
	
	cout << endl;			
	*/
	return this;	
}



template <typename T> int List_base<T>::get_length() const {
	
	return this->length;

}

template <typename T> int List_base<T>::get_size() const {
	
	return 0;
}

template <typename T> Node<T> * List_base<T>::get_head() {
	
	return this->head;
}

/******** WORKER FUNCTIONS **************/

template <typename T>List_base<T> * List_base<T>::pop() {
	
	// remove from front of list

	Node <T> * delete_node = this->head;

	this->head = this->head->next;

	delete delete_node;

	this->length--;
}

template <typename T>List_base<T> * List_base<T>::clear() {
	
	Node<T> * temp;
	Node <T> * _current = this->head;

	if(this->length == 0) {

		return this;
	}

	while (_current != NULL) {

		temp = _current;//set the temp to current in the list
		_current = _current->next;//iterate through the next piece of the list

		delete temp;//delete this elemeent
	}
		
	this->length = 0;//reset the list length
	this->head = NULL;//set the head to null afterwards
}

#endif