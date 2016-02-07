// Giselle Serate
// February 6, 2016
// Adds series 2^2 + 4^2 + 6^2 + ... + n^2 and lists explicitly the numbers being added. 

#include <stdio.h>

int main() {
	int max, sum = 0, curr = 2; // max: user-inputted upper limit
								// sum: total sum, will be returned
								// curr: current value that is being handled in loop

	printf("Enter an integer smaller than 100: ");
	scanf("%d", &max);

	printf("Sum = "); // starts output line

	while(curr < max) {
		if (curr == 2) {
			printf("%d", curr*curr);
		}
		else {
			printf(" + %d", curr*curr);
		}
		sum += curr * curr; // adds square of curr to sum
		curr += 2; // increments curr to next even number
	}

	printf(" = %d\n", sum); // finishes output line

	return 0;
}