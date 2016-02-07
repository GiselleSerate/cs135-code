// Giselle Serate
// February 6, 2016
// Adds series 2^2 + 4^2 + 6^2 + ... + n^2

#include <stdio.h>

int main() {
	int max, sum = 0, curr = 2; // max: user-inputted upper limit
								// sum: total sum, will be returned
								// curr: current value that is being handled in loop

	printf("Enter an integer smaller than 100: ");
	scanf("%d", &max);

	while(curr < max) {
		sum += curr * curr; // adds square of curr to sum
		curr += 2; // increments curr to next even number
	}

	printf("Sum = %d\n", sum);

	return 0;
}