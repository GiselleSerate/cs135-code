// Giselle Serate
// May 1, 2016
// Decoding program to get messages from pgm files.


#include <stdio.h>
#include <stdlib.h> // do you even malloc bro?


int main(int argc, char *argv[]) {
	char filenameH[20];
	FILE *encoded, *output;
	char ichar, mchar;
	int szX, szY; // size of image
	int *imgArray;
	unsigned char currentChar; // add stuff to this puppy bit by bit
	int i, j;
	int screen = 1; // IN PRACTICE WILL START OUT AS 0 BUT I WANT IT TO PRINT TO SCREEN

	// check command line argument number
	if(argc != 2) {
		printf("The proper use of this function is: decode encoded.pgm\n");
		exit(EXIT_FAILURE);
	}

	// get mah encoded file (the file with the message in it)
	encoded = fopen(argv[1], "r");
	while (encoded == NULL) {
		printf("Can't open the file %s\nPlease enter an encoded file name: ", argv[1]);
		scanf("%s", filenameH);
		encoded = fopen(filenameH, "r");
	}

	// start reading image
	for(i = 0; i < 2; i++) { 
		do { // get in until \n, aka eat a line
			ichar = fgetc(encoded);
		} while(ichar != '\n');
	}
	fscanf(encoded, "%d %d", &szX, &szY); // get in size
	do { // get in until \n, aka eat a line
		ichar = fgetc(encoded);
	} while(ichar != '\n');
	// Malloc array
	imgArray = (int *)malloc(sizeof(int) * (szX * szY));
	// Continue reading in array
	for(i = 0; i < szX * szY; i++) {
		fscanf(encoded, " %d", &imgArray[i]);
	}

	output = fopen("output.txt", "w");
	if(output == NULL) {
		printf("Can't open an output file. Printing message to screen.\n");
		screen = 1;
	}

	// start reading from encoded thing
	int k = 0; // keeps track of where in encoded we at
	for(i = 0; i < szX * szY; i++) {
		// ok got the number. Extract the bit from this by checking bit 0 of the number
		if(imgArray[i] & 1 << 0) {
			// if it's set, make bit (i % width) of currentChar be 1
			currentChar |= 1 << (i % szX);
			// printf("bit 1\n");
		}
		else {
			// make bit (i % width) of currentChar be 0
			currentChar &= ~ (1 << (i % szX));
			// printf("bit 0\n");
		}
		if((i > 0) && ((i % szX) == szX-1)) {
			// you at the end now, write this puppy somewhere
			fprintf(output, "%c", currentChar);
			printf("%c", currentChar);
		}
		for(j = 0; j < 8; j++) {
			if(mchar & 1 << j) { // if bit j of mchar set, then
				// set bit 0 of image pixel k
				imgArray[i] |= 1 << k;
			}
			else {
				// clear bit 0 of image pixel k
				imgArray[i] &= ~(1 << k);
			}
			// increment k
			k++;
		}
	}

	// CLEAN UP FAM

	return 0;

}
