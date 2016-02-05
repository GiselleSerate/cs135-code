// Project 1 Problem 1 Challenge 2
// Adds two fractions inputted by the user and returns answer as a reduced fraction. 
// Giselle Serate
// January 28, 2016

#include <stdio.h>

int main() {
	int num1, den1, num2, den2, mod;
	printf("Enter two fractions separated by the plus sign in the format a/b+c/d: ");
	scanf("%d/%d+%d/%d", &num1, &den1, &num2, &den2);
	int numAns = num1*den2+num2*den1;
	if(numAns==0) {
		printf("The sum of the two fractions is: 0\n");
		return 0; // This mid-program return may or may not be according to best practices.
	}
	int denAns = den1*den2;
	for(mod=2; mod<6; mod++) {
		while(numAns%mod==0&&denAns%mod==0) {
			numAns = numAns/mod;
			denAns = denAns/mod;
		}
	}
	printf("The sum of the two fractions is: %d/%d\n", numAns, denAns);
	return 0;
}