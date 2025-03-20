#include<stdio.h>
#include<stddef.h>
#include<stdint.h>

// void pointers are more helpful when you're sending data into a function
// and you don't know ahead of time the size of data being passed.
void *my_memset(void *data, uint8_t c, size_t n) {
	uint8_t *data_as_bytes = (uint8_t*)data;
	for (size_t i = 0; i < n; i++)
		data_as_bytes[i] = c;
	return data;
}

void map(void *xs, size_t n, size_t size, void (*f)(void*)) {
	uint8_t *xs_as_bytes = (uint8_t*)xs;
	for (size_t i = 0; i < n; i++)
		f(&xs_as_bytes[i * size]); // multiple the value by its size.
}

void square(void *x) {
	int *p = x;
	*p = *p * *p;
}

void square_floats(void *x) {
	float *p = x;
	*p = *p * *p;
}

int main() {
	int a  = 3;
	void *p = &a;
	printf("%p\n", p); // print the value of the pointer (address)
	// printf("%d\n", *p); this fails because the compiler does not know the type/size of data referenced by this pointer.
	printf("%d\n", *(int*)p); // we need to specify the type/size of data referenced by the pointer.

	int xs[5] = {1,2,3,4,5};
	for (int i = 0; i < 5; i++)
		printf("%4d", xs[i]);
	printf("\n-----\n");

	/*
	my_memset(xs, 0, sizeof(xs)); // here we're setting each value as 0
	for (int i = 0; i < 5; i++)
		printf("%d ", xs[i]);
	printf("\n");
	*/

	// ----
	map(xs, 5, sizeof(int), square);
	for (int i = 0; i < 5; i++)
		printf("%4d", xs[i]);
	printf("\n-----\n");

	float ys[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	for (int i = 0; i < 5; i++)
		printf("%6.2f ", ys[i]);
	printf("\n");

	map(ys, 5, sizeof(float), square_floats);
	for (int i = 0; i < 5; i++)
		printf("%6.2f ", ys[i]);
	printf("\n");



	return 0;
}
