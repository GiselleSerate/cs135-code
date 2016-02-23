// Giselle Serate
// February 19, 2016
// Capitalizes a sentence terminated with given sentence terminators. Also returns word count and longest word length.

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
	else if(itsAChar < 91 && itsAChar > 64) { // Is uppercase
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
	int maxLetters = 1; // Initialized at 1 so I can put it in the not zero if statement.
						// Because the words will be at least 1 letter long anyway.

	printf("Enter a sentence ended by a ‘.’, a ‘?’ or a ‘!’: ");

	// Use getChar to determine length of array.
	do {
		myChar = getchar();

		if (myChar == ' ' || isTerminator(myChar)) {
			if (lettersInWord != 0) { // if you're actually in a word
				numOfWords++;
				if (lettersInWord > maxLetters) {
					// printf("\nNEW MAXIMUM: %d", lettersInWord);
					maxLetters = lettersInWord;
				}
			}
			lettersInWord = 0;
			// printf("\nDone being a word.");
		}
		else if (isLetter(myChar)) {
			lettersInWord++;
			// printf("\nNew letter in word: %c", myChar);		
		}
		// Else it's punctuation and punctuation is stupid
		if (firstTime == 1) { //first time through loop
			printf("Capitalized sentence: ");
			firstTime = 0;
		}

		if(isLetter(myChar) == 2) { // lowercase
			printf("%c", myChar-32);
		}
		else { // means it's uppercase or maybe we just don't care because they tried to trick us and put other ascii characters
			printf("%c", myChar);
		}

	} while(!isTerminator(myChar) && myChar!='\n');

	printf("\nTotal number of words: %d\n", numOfWords);
	printf("Length of the longest word: %d\n", maxLetters);

	return 0;
}