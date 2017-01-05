#include <stdio.h>
#include <stdlib.h>

int right_propagate(int);
int modulo_two(int, int);

int right_propagate(int n) {
	int rightmost = n & ~(n-1);
	int to_propagate = rightmost - 1;

	return n | to_propagate;
}

int modulo_two(int m, int n) {
	if(n%2 != 0) {
		printf("Divisor %d is not a power of 2.\n", n);
		exit(1);
	}

	int to_right = n - 1;
	return m & to_right;
}

int main() {
	printf("Testing right_propagate() ---\n");
	printf("With %d, expect %d, got %d\n", 0, 0, right_propagate(0));
	printf("With %d, expect %d, got %d\n", -1, -1, right_propagate(-1));
	printf("With %d, expect %d, got %d\n", 168, 175, right_propagate(168));

	printf("Testing modulo_two() ---\n");
	printf("3 mod 2 is %d\n", modulo_two(3, 2));
	printf("7 mod 8 is %d\n", modulo_two(7, 8));
	printf("7 mod 2 is %d\n", modulo_two(7, 2));
	return 0;
}
