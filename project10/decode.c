// Giselle Serate
// May 1, 2016
// Decoding program to get messages from pgm files.


#include <stdio.h>
#include <stdlib.h> // do you even malloc bro?


int main(int argc, char *argv[]) {
	char filenameH[20];
	char filenameO[20];
	FILE *encoded, *output;
	char ichar, mchar;
	int szX, szY; // size of image
	int *imgArray;
	unsigned char currentChar = 0; // add stuff to this puppy bit by bit
	int i, j, p;

	// check command line argument number
	if(argc != 3) {
		printf("The proper use of this function is: decode encoded.pgm output.txt\n");
		exit(EXIT_FAILURE);
	}

	// get mah encoded file (the file with the message in it)
	encoded = fopen(argv[1], "r");
	while (encoded == NULL) {
		printf("Can't open the file %s\nPlease enter an encoded file name: ", argv[1]);
		scanf("%s", filenameH);
		encoded = fopen(filenameH, "r");
	}

	output = fopen(argv[2], "w");
	while (encoded == NULL) {
		printf("Can't open the file %s\nPlease enter an output file name: ", argv[2]);
		scanf("%s", filenameO);
		output = fopen(filenameO, "w");
	}

	// start reading image
	for(i = 0; i < 2; i++) { 
		do { // get in until \n, aka eat a line
			ichar = fgetc(encoded);
		} while(ichar != '\n');
	}
	fscanf(encoded, "%d %d", &szX, &szY); // get in size
	for(i = 0; i < 2; i++) { 
		do { // get in until \n, aka eat a line
			ichar = fgetc(encoded);
		} while(ichar != '\n');
	}

	// Malloc array
	imgArray = (int *)malloc(sizeof(int) * (szX * szY)); // this works man
	// Continue reading in array
	for(i = 0; i < szX * szY; i++) {
		fscanf(encoded, " %d", &imgArray[i]);
	}

	int wE, power;
	currentChar = 0;
	// start reading from encoded thing
	for(i = 0; i < szX * szY; i++) {
		// Pull 8 lsbs. We want mod 8
		// ok got the number. Extract the bit from this by checking bit 0 of the number
		if(imgArray[i] & 1 << 0) {
			// if it's set, bit i % 8 of currentChar is 1
			power = 1;
			for(p = 0; p < (i % 8); p++) { // raises to power i % 8
				power *= 2;
			}
			wE += power;
		}
		// else bit i % 8 of currentChar be 0
		if((i % 8) == 7) {
			// you at the end now, write this puppy somewhere
			if (wE < 127) { // if char printable, print it [32 to 126]
				// printf("%c", (char)wE);
				fprintf(output, "%c", (char)wE);
			}
			wE = 0;
		}
	}

	// CLEAN UP FAM
	free(imgArray);
	fclose(encoded);
	fclose(output);

	return 0;

}
