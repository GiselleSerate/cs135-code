// Giselle Serate
// February 19, 2016
// Capitalizes a sentence terminated with given sentence terminators. 

#include <stdio.h>

int main() {
	char myChar; // Character holder variable.
	int count = 0;
	int numOfWords = 0;
	int lettersInWord = 0; // How many letters are in a given word

	printf("Enter a sentence ended by a ‘.’, a ‘?’ or a ‘!’: ");

	// Use getChar to determine length of array.
	do {
		myChar = getchar();
		count++;
		if (myChar == ' ') {
			if (lettersInWord != 0) { // if you're actually in a word
				numOfWords++;
			}
			lettersInWord = 0;
		}
	} while(myChar!='.' && myChar!='?' && myChar!='!');

	// Fixing exit case, if they put a space before the terminator add another word
	if (lettersInWord == 0) {
		numOfWords++;
	}

	// Initialize array to hold word counts for each word in the sentence.
	char holdMyWordCounts[numOfWords];

	// Initialize array to hold entire sentence now that you know how big it should be
	char holdMySentence[count];

	for(int i = 0; i < count; i++) {
		printf("In the froot loop, time "); // OH. THIS IS BAD. VERY, VERY BAD. FRICKLEFRACKLESNAPANDCRACKLE.
		myChar = getchar();
		if(myChar < 123 && myChar > 96) { // lowercase
			holdMySentence[i] = myChar;
		}
		else { // means it's uppercase or maybe we just don't care because they tried to trick us and put other ascii characters
			holdMySentence[i] = myChar;
		}
		printf("%c",holdMySentence[i]);
	};


	return 0;
}