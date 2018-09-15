#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;


int conv(int *start, int *current,int *size_current, int dimensions);


template <typename T>
struct Dimensions {      
    int operator()(int* coordinates, int* sizes, int dimensions) {
        return conv(coordinates, coordinates, sizes, dimensions);
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
    //system("pause");
    //=======TEST CASE==========
    int coordinates[] = {1,1,1,1};
    int sizes[] = {2,2,2,2};
    int *current_size = sizes;
    int *current = coordinates;
	Vector<Integer> myVector(4,current_size);
	myVector.set(2,current);
	cout << myVector.get(current) << endl;
    
  return EXIT_SUCCESS;
}

int conv(int *start, int *current,int *size_current, int dimensions)
{
	
	int p1 = *current, p2 = *size_current, p3 = 0;
	if((start+dimensions-1)!=(current+1))
	{
		p3 = conv(start,current+1,size_current+1,dimensions);
	}
	else
	{
		p3 = *(current+1);
	}

	return p1+p2*p3; 
}
