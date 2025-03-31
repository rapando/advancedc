#include<stdio.h>

void update_val(void *x, int new_val) {
	int *p = (int *)x;
	*p = new_val;
}

int main() {
	const int a = 78;
	printf("original value:	%d\n", a);

	int *ptr = (int *)&a;
	*ptr = 43;
	printf("direct change attempt: %d\n",a);

	update_val((void *)&a, 34);
	printf("void pointer change: %d\n", a);

}


