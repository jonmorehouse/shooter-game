#include <iostream>
#include <vector>

using namespace std;

struct delete_ptr
{
    template <class T>
    void operator()(T * p)
    {	
        delete p;
    }
};

int main(int argc, char **argv) {

	

	
}