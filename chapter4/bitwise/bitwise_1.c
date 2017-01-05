#include <stdio.h>
#include <stdlib.h>

int shift_count(int);
int right_count(int);
void test(int, int);
void print_binary_reverse(int);
void is_power_two(int);

// Counts number of set bits
// Shift-counter cannot handle negative numbers as it relies on right shift

int shift_count(int n) {
	if(n < 0) {
		printf("Cannot handle negative numners!\n");
		exit(1);
	}

	int result = 0;
	int test;

	while(n != 0) {
		test = n & 1;
		result += test;
		n = n >> 1;
	}

	return result;
}

int right_count(int n) {
	/*
	if(n < 0) {
		printf("Cannot handle negative numners!\n");
		exit(1);
	}
	*/
	int rightmost;
	int total = 0;

	do {
		rightmost = n & ~(n-1);
		if(rightmost > 0) {
			total++;
		}

		n = n ^ rightmost;
	} while(n != 0);

	return total;
}

void test(int n, int which) {
	if(which == 1) {
		printf("There are %d bits set in %d\n", shift_count(n), n);
	} else {
		printf("There are %d bits set in %d\n", right_count(n), n);
	}
}

void print_binary_reverse(int n) {
	if(n < 0) {
		printf("Cannot handle negative numners!\n");
		exit(1);
	}

	printf("%d is 0x", n);
	
	int bit;
	while(n != 0) {
		bit = n & 1;
		printf("%d", bit);
		n = n >> 1;
	}

	printf("\n");
}

void is_power_two(int n) {
	if(right_count(n) == 1) {
		printf("%d is a power of 2.\n", n);
	} else {
		printf("%d is not a power of 2.\n", n);
	}
}

int main() {
	printf("Testing Shift Counter ---\n");
	test(0, 1);
	test(7, 1);

	printf("Testing Right Counter ---\n");
	test(0, 2);
	test(7, 2);
	test(-3, 2);
	
	printf("Testing Binary Print (Reverse) ---\n");
	print_binary_reverse(0);
	print_binary_reverse(7);
	print_binary_reverse(5);
	print_binary_reverse(15);

	printf("Testing Power Two ---\n");
	is_power_two(1);
	is_power_two(2);
	is_power_two(8);
	is_power_two(14);
	is_power_two(31);

	return 0;
}
