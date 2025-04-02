#include<stdio.h>

// if we want to get the length of an array, we can define this macro:
#define ARRAY_LEN(arr) (sizeof arr / sizeof arr[0])

int main() {
	printf("%zu\n", sizeof(int)); // prints 4 on 64 bit systems.
	
	int xs[] = {1,2,3,4};
	printf("size of arr is length * size of each element: %zu\n", sizeof xs);
	printf("length of array using macro: %zu\n", ARRAY_LEN(xs));

	int *xs_ptr = xs;
	printf("size of ptr to array: %zu\n", sizeof xs_ptr); // just the size of ptr

	

	return 0;

}
