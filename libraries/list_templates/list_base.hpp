#ifndef LIST_BASE_HPP
#define LIST_BASE_HPP

//project includes
#include "node.hpp"

//c++ libraries
#include <iostream>

template <typename T = int>

class List_base {

	public://constructors / destructors
		List_base();
		~List_base();

	public://worker functions
		virtual List_base<T> * push(T value) = 0;
		virtual List_base<T> * pop();
		List_base<T> * clear();//clear the entire list

	public://getter / viewer functions
		virtual Node<T> * front();//in both stack and queue
		virtual List_base<T> * print();
		Node<T> * get_head();
		int get_length() const;
		int get_size() const;

	protected://class variables -- available in the children as well
		int length;
		int size;
		Node<T> * head;

};

#include "list_base.cpp"

#endif