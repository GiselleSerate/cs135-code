// Project 1 Problem 1 
// Adds two fractions inputted by the user. 
// Giselle Serate
// January 28, 2016

#include <stdio.h>

int main() {
	int num1, den1, num2, den2;
	printf("Enter two fractions separated by the plus sign in the format a/b+c/d: ");
	scanf("%d/%d+%d/%d", &num1, &den1, &num2, &den2);
	int numAns = num1*den2+num2*den1;
	if(numAns==0) {
		printf("The sum of the two fractions is: 0\n");
	}
	else {
		printf("The sum of the two fractions is: %d/%d\n", numAns, den1*den2);
	}
	return 0;
}