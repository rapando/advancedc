#include<stdio.h>
#include<stdbool.h>

// using bitflags
/*
typedef unsigned int t_flag;
#define FLAG_A (1 << 0) // only the first bit is set.	00000001
#define FLAG_B (1 << 1) // only the second bit is set.	00000010
#define FLAG_C (1 << 2) // only the third bit is set.	00000100
*/

// method 2
typedef enum {
	FLAG_A = (1 << 0),
	FLAG_B = (1 << 1),
	FLAG_C = (1 << 2)
} t_flag;

// this function's sole purpose is to print the binary representation of a number.
void print_binary_value(unsigned int x) {
	for (int i = 7; i >= 0; i--)
		printf("%d", (x >> i) & 1);
	printf("\n");
}

int f(int x, bool is_added, bool is_squared, bool is_not) {
	if (is_added)
		x += x;
	if (is_squared)
		x *= x;
	if (is_not)
		x = ~x;
	return x;
}


int f2(int x, t_flag flags) {
	if (flags & FLAG_A)
		x += x;
	if (flags & FLAG_B)
		x *= x;
	if (flags & FLAG_C)
		x = ~x;
	return x;
}


int main(void) {
	printf("%d\n", f(1234, false, false, false));
	printf("%d\n", f(1234, true, false, false));
	printf("%d\n", f(1234, false, true, true));

	// print_binary_value(FLAG_A);
	// print_binary_value(FLAG_B);
	// print_binary_value(FLAG_C);
	//
	printf("-----------\n");

	printf("%d\n", f2(1234, 0));				// no flag is true.
	printf("%d\n", f2(1234, FLAG_A));			// true, false, false
	printf("%d\n", f2(1234, FLAG_B | FLAG_C));	// false, true, true

	return 0;
}
