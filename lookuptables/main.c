/*
 * A lookup table is basically a hashmap
 * */ 

#include<stdio.h>

enum foo {
	foo_2 = 0,
	foo_3,
	foo_4,
};

static int squares[] = {
	4,
	9,
	16
};

static int squares_map[] = {
	[foo_2] = 4,
	[foo_3] = 9,
	[foo_4] = 16
};

// the key is valid as long as it can be fit in an uint. E.g characters.
// If you need keys to be 'strings', then use enums so that they are basically positional integers.

static int  translations[] = {
	['a'] = 1,
	['b'] = 2,
	['c'] = 3,
	['d'] = 4,
};

int main() {

	// one way is, foo_2 references 4 because it's value is the index of 4.
	printf("foo_2 value. --- %d\n", squares[foo_2]);
	printf("foo_2 value from lookup --- %d\n", squares_map[foo_2]);

	printf("a is position %d in the alphabet\n", translations['a']);

	return 0;
}
