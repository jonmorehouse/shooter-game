#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
	
// project libraries
#include "linked_list.hpp"

using namespace std;

/********** CONSTRUCTORS / DESTRUCTORS **********/
template <typename T> Linked_list<T>::Linked_list() : List_base<T>() {
	
	this->current = this->head;


}

template <typename T> Linked_list<T>::~Linked_list() {
	
	//calls the parent destructor to destroy all of the nodes -- pointers for each
}


/************* PUBLIC WORKER FUNCTIONS **************/
template <typename T>Linked_list<T> * Linked_list<T>::push(T input) {

	this->length++;

	Node<T> * new_node = new Node<T>(input);

	new_node->next = this->head;//make this new point point to the old head

	this->head = new_node;//reset the head to this part of the list 

	return this;
}

template <typename T>Linked_list<T> * Linked_list<T>::next() {
		
	if (this->current == NULL) this->current = this->head;

	if (this->current->next != NULL) //not the end of the list
		this->current = this->current->next;

	else //last element in the list	
		this->current = this->head;

	return this;//return the linked list itself
}

template <typename T>Linked_list<T> * Linked_list<T>::reset() {
	
	this->current = this->head;//reset the current element to the head

	return this;
}

template <typename T>Linked_list<T> * Linked_list<T>::pop_current() {
	
	Node<T> * temp = this->current;//store the location of current

	this->length--;

	if (this->length == 0) {
		this->current = NULL;
		this->head = NULL;
		delete temp;

		return this;
	}

	if (this->current == NULL) this->current = this->head;//validate the current pointer!

	if (this->current == this->head) {
		this->current = this->current->next;//reset the current pointer!
		this->head = this->current;//reset the head
	}

	for (Node<T> * iter = this->head; iter != this->current; iter = iter->next) {

		if (iter->next == this->current) {//find the node that points to the current node to delet
			
			if (this->current->next != NULL)
				iter->next = this->current->next;//make sure the previous pointer points in the correct diretion!

			else
				iter->next = this->head;

			break;
		}
	}

	// RESET THE CURRENT ELEMENT!
	if (this->current->next != NULL) this->current = this->current->next;//move the current position up one to the right!

	// the current should point back to zero
	else this->current = this->head;

	// delete the temporarily stored place in memoery
	delete temp;//delete the temp address

	
	return this;//return the linked list

}

template <typename T>Linked_list<T> * Linked_list<T>::erase(int index) {
	
	if (index >= this->length || index < 0) return this;

	this->length--;
	Node<T> * current = this->head;
	Node<T> * next = this->head->next;
	Node<T> * previous = NULL;

	if (index == 0) {

		this->head = next;
		delete current;
		return this;
	}

	while (index > 0) {

		index--;
		previous = current;
		current = current->next;
		next = current->next;

	}

	previous->next = next;
	delete current;

	return this;

}

/************ PUBLIC GETTER FUNCTIONS **************/

template <typename T>Node<T> * Linked_list<T>::get_current_node() const{
	
	return this->current;
	
}

template <typename T>T Linked_list<T>::get_current() const {
	
	if (this->current == NULL) return this->head->data;//the next method has not been called yet!

	return this->current->data;

}

template <typename T>T Linked_list<T>::get(int index) const {
	
			
	if (index < 0 || index >= this->length) return this->head->data;//error should not happen!

	if (index == 0) return this->head->data;

	// need to iterate up the list
	Node<T> * _current = this->head;

	for (; index > 0; index--)
		_current = _current->next;

	return _current->data;
}




#endif