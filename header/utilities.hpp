#ifndef UTILITIES_HPP
#define UTILITIES_HPP

// c++ libraries
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

namespace utilities {
	
	struct delete_ptr {
	    template <class T>
	    void operator()(T * element) {		
		
			delete element;
	    }
	};

	struct equal_strings {
		// this is a structure so that you can ensure that all data is protected -- constant declared function and all inputs are constant
		// structures can not have external functions -- gives an unknown storage error
		bool operator()(const char * input_1, const char * input_2) const {

        	return (input_1 == input_2) || (input_1 && input_2 && strcmp(input_1, input_2) == 0);
    	}
	};
}

namespace utilities {//seed / random functions

	extern bool seed;//whether or not the seed has been created
	extern void create_seed();//creates the seed for us if not allready created
	extern int random_integer(int low, int high);//
	extern float random_float(float low, float high);//remember that the range will be fixed before returning




}

#endif