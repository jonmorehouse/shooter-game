#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

// project libraries
#include "list_base.hpp"

template <typename T>

class Linked_list : public List_base <T> {


	public://
		Linked_list();
		~Linked_list();

	public://accessor functions

		Linked_list<T> * next();//go to the next element in the list
		Node<T> * get_current_node() const;//return the current node
		T get_current() const;//get the current data
		T get(int index) const;//this will get the specified index and will return the data it holds

	public://worker functions
		Linked_list<T> * push(T value);//push a value into the front of the list
		Linked_list<T> * pop_current();//deletes the current_node--resets the current as the next element in the list!
		Linked_list<T> * reset();//this resets the current to the front of the list
		Linked_list<T> * erase(int index);

	private://variables
		Node<T> * current;//store the current node


};

#include "linked_list.cpp"//grab the template implementation file


#endif