#ifndef STACK_HPP
#define STACK_HPP

//project libraries

#include "list_base.hpp" //includes c++ libraries as well -- is an interface class

template <typename T = int>

class Stack : public List_base <T>{

	public: //constructors / destructors
		Stack();
		~Stack();
		
	public: //worker functions
		virtual Stack<T> * push(T value);
		virtual Stack<T> * pop();

	public: //getter / viewer functions
		virtual Node<T> * front();



};

#include "stack.cpp"

typedef Stack<int>Int_stack;

#endif