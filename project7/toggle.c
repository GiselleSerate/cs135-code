// Giselle Serate
// March 30, 2016
// Program that will use pointers to toggle the case of an inputted sequence of characters. 

#include <stdio.h>


#define STRLEN 30


void toggle_case(char *letterPtr);
void read_message(char array[], int *actualLength);


int main() {
	char putLettersInBox[STRLEN+1];
	int messageLength;
	int i; // we like counters yes we do

	read_message(putLettersInBox, &messageLength); 

	printf("New string:");

	char *pointMe = putLettersInBox;

	for(pointMe; pointMe - putLettersInBox < messageLength; pointMe++) { // BLOODY EDGE CASES PLEASE CHECK THEM
		printf("%c", *pointMe);
	}

	return 0;
}


// Toggles letter case given a pointer to the letter. Else does nothing, if it is not a letter. 
void toggle_case(char *letterPtr) {
	if(*letterPtr >= 'A' || *letterPtr <= 'Z') { // Uppercase, switch to lowercase
		*letterPtr += 'a' - 'A';
	}
	else if(*letterPtr >= 'a' || *letterPtr <= 'z') { // Lowercase, switch to uppercase
		*letterPtr = 'P';
		// GOTTA WRITE THEM ALL	
	}
	// else do nothing to it
}

// Prompts user and reads in characters into an array
void read_message(char array[], int *actualLength) {
	
	int i = 0; // Our favorite counter variable.

	printf("Enter your string (maximum %d characters):", STRLEN);
	
	do {
		array[i] = getchar();
		printf("Have gotchar'd %c\n", array[i]); // DEBUG LINE
		if(array[i] == '\n') {
			printf("reached newline, breaking \n"); // DEBUG LINE
			break;
		}
		i++;
	} while(i < STRLEN - 1);

	printf("out of do while\n"); // DEBUG LINE

	*actualLength = i; // MAKE SURE THIS IS RIGHT, I THINK YOU MIGHT BE NEGLECTING AN EDGE CASE.

	printf("Have reached the end of read_message");
}