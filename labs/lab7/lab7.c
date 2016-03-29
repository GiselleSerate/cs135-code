// Giselle Serate
// March 28, 2016
// Lab 7 where we switch certain elements of an array using pointers.


#include <stdio.h>


#define LEN 15


void switcheroo(int *first, int *second);


int main() {
	int numberArray[LEN];
	int i; // counter for my for loops

	printf("Enter %d integers:\n", LEN);

	for(i = 0; i < LEN; i++) { // Reads in LEN integers.
		scanf(" %d", numberArray+i);
	}

	// Calling switcheroo various times.
	switcheroo(numberArray, numberArray + 7); // indexes 0 and 7
	switcheroo(numberArray + 8, numberArray + 3); // indexes 8 and 3
	switcheroo(numberArray + 14, numberArray); // indexes 14 and 0

	printf("\nSwapped array:\n");

	for(i = 0; i < LEN; i++) { // Prints out array again.
		printf("%d ", *(numberArray+i));
	}

	printf("\n"); // For formatting's sake.

	return 0;
}

// Switches values of first and second thing, which are pointers.
void switcheroo(int *first, int *second) {
	int valFirst = *first;
	int valSecond = *second;

	*first = valSecond;
	*second = valFirst;
}