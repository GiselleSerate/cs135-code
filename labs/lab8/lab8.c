// Giselle Serate
// April 4, 2016
// Lab to make string an uppercase. Must use gets and puts.


#include <stdio.h>


int charsInString(char *wowString);

void capErrybody(char *wowString);


int main() {

	char bestString[256];

	printf("Please enter a string to be capitalized: ");

	// printf("\nGot past printf.\n"); // DEBUG LINE

	// Compiler's spitting a warning here about gets being deprecated, but I have to use it because rules be rules.
	gets(bestString);

	// printf("We got this far in the program.\n"); // DEBUG LINE

	printf("There are %d chars in the string.\n", charsInString(bestString));

	capErrybody(bestString);

	printf("The capitalized string is:");
	puts(bestString);

	return 0;

}


// Returns the number of chars in a string given a pointer to the string.
int charsInString(char *wowString) {
	char *counterPointer = wowString;
	while(*counterPointer != '\0') { // while counter in string, increment
		counterPointer++;
	}
	return counterPointer - wowString;
}

// Returns nothing given a pointer to a string; modifies actual string to Capitalize Errybody. 
void capErrybody(char *wowString) {
	int howMany = charsInString(wowString);

	int i = 0; // Everyone's favorite counter variable
	char *itsAPointer; // Points to each char.

	for(itsAPointer = wowString; itsAPointer - wowString < howMany; itsAPointer++) {
		if(*itsAPointer <= 'z' && *itsAPointer >= 'a') {
			*itsAPointer -= 'a'- 'A';
		}
	}
}
