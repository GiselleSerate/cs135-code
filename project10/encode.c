// Giselle Serate
// April 28, 2016
// Project 10 encodes message in image given image file and message file by putting bits of message in least significant bits of the
// image pixels.


#include <stdio.h>
#include <stdlib.h> // for malloc


int main(int argc, char *argv[]) {
	char filenameI[20];
	char filenameM[20];
	char filenameE[20];
	FILE *image, *message, *encoded;
	char ichar, mchar; // holders for current image or message char
	int szX, szY; // size of image
	int i, j; // counters, beautiful counters
	int testMe;
	int *imgArray;

	// check command line argument number
	if(argc != 4) {
		printf("The proper use of this function is: encode image.pgm messagefile.txt encoded.pgm\n");
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

	// get mah output file
	encoded = fopen(argv[3], "w");
	if(encoded == NULL) {
		printf("Can't open the file %s\nPlease enter an encoded file name: ", argv[3]);
		scanf("%s", filenameE);
		encoded = fopen(filenameE, "w");
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
	do { // get in until \n, aka eat a line
		ichar = fgetc(image);
	} while(ichar != '\n');
	// Malloc array
	imgArray = (int *)malloc(sizeof(int) * (szX * szY));
	// Continue reading in array
	for(i = 0; i < szX * szY; i++) {
		fscanf(image, " %d", &imgArray[i]);
	}

	// start reading message
	int k = 0; // keeps track of where in the image we at
	for(i = 0; i < szX * szY; i++) {
		mchar = fgetc(message);
		if(mchar < 0) { // reached eof
			imgArray[k] |= 1 << 0; // just set all those bits bc then decode will catch it. 
			k++;
		}
		else {
			// ok got the char, break it down into 8 bits I think
			for(j = 0; j < 8; j++) {
				if(mchar & 1 << j) { // if bit j of mchar set, then
					// set bit 0 of image pixel k
					imgArray[k] |= 1 << 0;
				}
				else {
					// clear bit 0 of image pixel k
					imgArray[k] &= ~(1 << 0);
				}
				// increment k
				k++;
			}
		}
	}
	
	// okay now write that sucker
	fprintf(encoded, "P2\n# result.pgm\n%d %d\n255\n", szX, szY); // pgm header
	for(i = 0; i < szX * szY; i++) {
		fprintf(encoded, "%d\n", imgArray[i]);
	}

	free(imgArray);

	fclose(image);
	fclose(message);
	fclose(encoded);

	return 0;

}