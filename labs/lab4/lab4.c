// Giselle Serate
// February 29, 2016
// CS 135 Lab [4]
// This counts up the number of each digit in a number and prints it in a formatted way. 

#include <stdio.h>

int main() {

	int digitRead; // current digit being read
	int digits[10] = {0}; // array to store instances of digits
	int counter; // mah counter for mah for loops because apparently I can't get this thing to compile in C99 for whatever reason

	printf("Enter a number: ");

	// I am priming my loop, sue me
	digitRead = getchar();

	// I want it to keep going through the input string even if it's not a number so it still gotta be doing getchar and going thru this while
	while(digitRead != '\0' && digitRead != '\n') { // The two lines in this loop act on DIFFERENT DIGITS. Please keep that in mind.
		if(digitRead <= '9' && digitRead >= '0') { // if the char we got already is a digit, increment the digit in array digits
			// printf("The digit I am reading is %d\n"); // Debug linessss!
			digits[digitRead - 48]++;
		}
		digitRead = getchar(); // gets next digit in the string
	}

	printf("Digit:\t\t");
	for (counter = 0; counter < 10; counter++) { // Prints out indexes 0 through 9
		printf("%d ", counter);
	}
	printf("\n");

	printf("Occurrences:\t");
	for (counter = 0; counter < 10; counter++) { // Prints out values in digits at indexes 0 through 9
		printf("%d ", digits[counter]);
	}
	printf("\n"); // Judge me by my newlines, do you?

	return 0;

}