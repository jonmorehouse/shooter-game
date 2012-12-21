#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "../header/utilities.hpp"

using namespace std;

int main(int argc, char ** argv) {
		

	for (int i = 0, z = 100; i < z; i++) 
		cout << utilities::random_integer(4,100) << endl;
	

}

