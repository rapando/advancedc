#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

int foo(int x, int y) {
	return x + y;
}

// this function returns true if the passed value is even and false if not.
bool p(int x) {
	return x % 2 == 0;
}

// this function takes in an array of ten integers and a pointer to a function.
// we loop through the array and apply the function to each element in the array
// In this case, the function returns true if the element is even.
// If the returned value is true, we print the value in the array.
void print_if(int xs[10], bool (*predicate)(int)) {
	for (int i = 0; i < 10; i++) {
		if (predicate(xs[i]))
			printf("%2d ", xs[i]);
	} 
}

// this comparison function gets the difference between two values.
// We cast them into integers because we know beforehand we'll be sorting integers.
// If the first one is larger, a positive value is returned.
// This sorts in ascending order.
int compar(const void *x1, const void *x2) {
	return (*(int*)x1) - (*(int*)x2);
}

int compar_desc(const void *x1, const void *x2) {
	return (*(int*)x2) - (*(int*)x1);
}

int main(void) {
	int xs[] = {1,5,3,10,9,2,4,8,7,6};
	printf("Array before sorting:\t");
	for (int i = 0; i < 10; i++)
		printf("%2d ", xs[i]);
	

	// perform quicksort.
	qsort(xs, 10, sizeof(int), compar);

	printf("\nArray after sorting:\t");
	for (int i = 0; i < 10; i++)
		printf("%2d ", xs[i]);

	// perform quicksort in descending order.
	qsort(xs, 10, sizeof(int), compar_desc);
	printf("\nArray after sorting:\t");
	for (int i = 0; i < 10; i++) 
		printf("%2d ", xs[i]);

	printf("\nPrinting even numbers:\t");
	
	// int (*f)(int, int) = foo;	// how to assign a function to a function pointer.
	// printf("%d\n", f(3,4));		// how to call the function.

	print_if(xs, p);

	// another example is the qsort function (quicksort.)
	// https://linux.die.net/man/3/qsort 
	
	printf("\n");
	return 0;

}
