// Giselle Serate
// March 14, 2016
// Lab 6: Gets kth digit of number n using digit function. 

#include <stdio.h>

// These are the functions I'm using. 
int digit(int n, int k);
int numDigits(int n);
int pOfTen(int exp);

int main() {
	int n, k;

	printf("Enter two positive integers (n, k): ");
	scanf("%d,%d", &n, &k);

	while(n < 0 || k < 0) { // Re-prompt user if this is wrong. 
		printf("Enter two positive integers (n, k): ");
		scanf("%d,%d", &n, &k);
	}

	// If digit(n, k) can't get a proper number for this, it returns -1. 
	// If I were writing a program not for an auto grader, I'd assign the return value to a var and print a coherent error message.
	printf("The k=%d digit of %d is: %d\n", k, n, digit(n, k));

	return 0;
}

// Returns kth digit of n
// or -1 if n does not have k digits.
int digit(int n, int k) {
	int count = numDigits(n);

	if(count < k || k == 0) {
		return -1; // Error value indicating that there is no kth digit in n. 
	}
	else {
		n /= pOfTen(k - 1); // By division, since this is an int:
							// Intentionally truncates everything smaller than the digit in question. 
		n = n % 10; // Mod 10 gets only the smallest digit of the number. 
		return n;
	}
}

// Returns the number of digits in this number. 
int numDigits(int n) {
	int count;

	while(n > 0) {
		n /= 10;
		count++;
	}

	return count;
}

// Returns the power of ten associated with this exponent. 
int pOfTen(int exp) {
	int i, holder = 10;

	for(i = 1; i < exp; i++) {
		holder *= 10;
	}

	return holder;
}