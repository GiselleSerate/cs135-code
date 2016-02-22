// Giselle Serate
// February 22, 2016
// Prints out number of occurrences of each letter in an input terminated by a period. 
// I used Python dictionaries for this before. It was much easier. Then again, it was Python. 

#include <stdio.h>
#define LETTERS 26

int main() {

	int letterInstances[LETTERS]; // where a is 0
	char currentChar;
	int count;
	char charToPush;

	for(count = 0; count < LETTERS; count++) { // Clearing array so every value is 0 before we start. 
		letterInstances[count] = 0;
	}

	printf("Enter a sentence ended by a '.':");

	// Scans in each char. 
	do {
		currentChar = getchar();
		charToPush = currentChar - 97;
		letterInstances[charToPush]++;
	} while(currentChar != '.');

	for(count = 0; count < LETTERS; count++) {
		if(letterInstances[count] == 0) {
			// don't print anything because there's no letter
		}
		else if(letterInstances[count] == 1) {
			printf("Letter '%c' occurs 1 time\n", count+97);
		}
		else {
			printf("Letter '%c' occurs %d times\n", count+97, letterInstances[count]);
		}
	}

	return 0;
}