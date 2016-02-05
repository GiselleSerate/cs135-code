// Project 1 Problem 1 Challenge 1
// Adds two fractions inputted by the user and returns answer as an improper fraction. 
// Giselle Serate
// January 28, 2016

#include <stdio.h>

int main() {
	int num1, den1, num2, den2;
	int whole = 0;
	printf("Enter two fractions separated by the plus sign in the format a/b+c/d: ");
	scanf("%d/%d+%d/%d", &num1, &den1, &num2, &den2);
	int numAns = num1*den2+num2*den1;
	int denAns = den1*den2;
	// I could have used mod and dividing. That would actually have been way faster/more efficient. Oh well.
	if(numAns>denAns) {
		while(denAns<=numAns) {
			numAns = numAns - denAns;
			whole++;
		}
	}
	if(whole==0&&numAns==0) {
		printf("The sum of the two fractions is: 0\n");
	}
	else if(whole==0) {
		printf("The sum of the two fractions is: %d/%d\n", numAns, den1*den2);
	}
	else if(numAns==0) {
		printf("The sum of the two fractions is: %d\n", whole);
	}
	else {
		printf("The sum of the two fractions is: %d %d/%d\n", whole, numAns, den1*den2);
	}
	return 0;
}