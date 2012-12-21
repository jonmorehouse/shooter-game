#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T=int>

class Node {

	public://constructors / destructors
		Node(T value);

		T data;

		Node <T> * next;
		Node <T> * prev;
};

#include "node.cpp"

typedef Node<int>Int_node;


#endif