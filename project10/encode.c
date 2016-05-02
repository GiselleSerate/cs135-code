// Giselle Serate
// April 28, 2016
// Project 10 encodes message in image given image file and message file. Looks like they're all pgm files.


#include <stdio.h>
#include <stdlib.h> // for malloc


// function declaring? if you wanna I mean you don't have to


int main(int argc, char *argv[]) {
	char filenameI[20];
	char filenameM[20];
	FILE *image, *message, *encoded;
	char ichar, mchar; // holders for current image or message char
	int szX, szY; // size of image
	int i, j; // counters, beautiful counters
	int testMe;
	int *imgArray;

	// check command line argument number
	if(argc != 3) {
		printf("The proper use of this function is: encode image.pgm messagefile.txt\n");
		exit(EXIT_FAILURE);
	}

	// get mah image file
	image = fopen(argv[1], "r");
	while (image == NULL) {
		printf("Can't open the file %s\nPlease enter an image file name: ", argv[1]);
		scanf("%s", filenameI);
		image = fopen(filenameI, "r");
	}

	// get mah message file
	message = fopen(argv[2], "r");
	while (message == NULL) {
		printf("Can't open the file %s\nPlease enter a message file name: ", argv[2]);
		scanf("%s", filenameM);
		message = fopen(filenameM, "r");
	}

	// start reading image
	for(i = 0; i < 2; i++) { 
		do { // get in until \n, aka eat a line
			ichar = fgetc(image);
		} while(ichar != '\n');
	}
	fscanf(image, "%d %d", &szX, &szY); // get in size
	do { // get in until \n, aka eat a line
		ichar = fgetc(image);
	} while(ichar != '\n');
	// Malloc array
	imgArray = (int *)malloc(sizeof(int) * (szX * szY));
	// Continue reading in array
	for(i = 0; i < szX * szY; i++) {
		fscanf(image, " %d", &imgArray[i]);
	}

	// start reading message I NEED THAT SIZE
	do {
		mchar = fgetc(message);
	} while(mchar > 0);



	// ANY FREEING NEED TO BE DONE? PLEASE DO IT

	fclose(image);
	fclose(message);
	// fclose(encoded); // UNCOMMENT LATER PLS PLS

	return 0;

}


// function definitions or whatever