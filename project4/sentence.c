// Giselle Serate
// February 19, 2016
// Capitalizes a sentence terminated with given sentence terminators. Prints out word count. 

#include <stdio.h>

int isTerminator(char itsAChar) { // Returns 1 if terminator, 0 otherwise
	if(itsAChar=='.' || itsAChar=='?' || itsAChar=='!') {
		return 1;
	}
	else {
		return 0;
	}
}

int isLetter(char itsAChar) { // Will return true/false if treated as a bool
								// but true can still be separated into 2 (lowercase) and 1 (uppercase)
								// bahaha I'm clever
	if(itsAChar < 123 && itsAChar > 96) { // Is lowercase
		return 2;
	}
	else if(itsAChar > 91 && itsAChar < 64) { // Is uppercase
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	char myChar; // Character holder variable.
	int firstTime = 1; // Keeps track of the first time through the loop
	int numOfWords = 0;
	int lettersInWord = 0; // How many letters are in current word

	printf("Enter a sentence ended by a ‘.’, a ‘?’ or a ‘!’: ");

	// Use getChar to determine length of array.
	do {
		myChar = getchar();

		if (firstTime == 1) { //first time through loop
			printf("\nCapitalized sentence: ");
			firstTime = 0;
		}

		if(isLetter(myChar) == 2) { // lowercase
			printf("%c", myChar-32);
		}
		else { // means it's uppercase or maybe we just don't care because they tried to trick us and put other ascii characters
			printf("%c", myChar);
		}

		if (myChar == ' ') {
			if (lettersInWord != 0) { // if you're actually in a word
				numOfWords++;
			}
			lettersInWord = 0;
		}
		else if (isLetter(myChar)) {
			lettersInWord++;		
		}
		// Else it's punctuation and punctuation is stupid

	} while(!isTerminator(myChar) && myChar!='\n');

	// Fixing exit case, if they didn't put a space before the terminator add another word
	if (lettersInWord != 0) {
		numOfWords++;
	}

	printf("\nTotal number of words: %d\n", numOfWords);

	return 0;
}