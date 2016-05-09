// Giselle Serate
// May 8, 2016
// Bit shifting numbers. No, it's not a rude word.


#include <stdio.h>


int main() {
	// 24's binary expression is: 011000
	// the indices be:            543210
	int numero = 24;
	int j = 2;
	int set, clear, check;

	// (1 << j) is a mask; jth bit set
	// ~(1 << j) is a mask; all bits but jth bit set

	// SETTING bit 5: should be 56
	set = numero | (1 << 5);
	printf("Set is %d\n", set);

	// CLEARING bit 4: should be 8
	// clear = numero ^ ~(1 << 4); // NOPE try again.
	// clear = numero ^ (~ (1 << 4)); // same thing
	clear = numero & (~ (1 << 4)); // maybe it will work

	printf("Clear is %d\n", clear);

	return 0;
}