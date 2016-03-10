// Giselle Serate
// March 9, 2016
// Problem 2: Makes pgm images according to rules

#include <stdio.h>

int main() {
	int userInput;
	int mod;
	int i, j;
	int size; // size of each board square

	printf("Please enter a number: ");
	scanf("%d", &userInput);

	mod = userInput % 3;

	if(mod == 2) {
		// create an all­ black image of size n x n
		// store this image in a multidimensional array
	}
	else {
		// create an image with dimensions add either 1 or 2 to make the dimensions when divided by 3 have 
		// a remainder of 2 (so 9 ­> 11x11 image, 16 ­> 17x17 image)
		userInput += (2-mod);
	}

	int multArray[userInput][userInput];

	// This part isn't really necessary--why did it have to be a black array first?
	// I write another nested for later anyway. All I'd have to do is add an else to my if. 
	for(i = 0; i < userInput; i++) {
		for(j = 0; j < userInput; j++) {
			multArray[i][j] = 0;
		}
	}

	// image header text
	printf("P2\n# image.pgm\n%d %d\n1\n", userInput, userInput);

	size = userInput/3; // Truncates. This is on purpose. 
	printf("size: %d \n", size);

	for(i = 0; i < userInput; i++) {
		for(j = 0; j < userInput; j++) {
			// Tricksy: Size, as the size of the inside square, takes you to the first bar, size * 2 + 1 takes you to the second bar.
			// This might seem weird but it works because you have to mind your zero-indexing. 
			if(i == size || i == size * 2 + 1 || j == size || j == size * 2 + 1) {
				multArray[i][j] = 0;
			}
			else {
				multArray[i][j] = 1;				
			}
			printf("%d ", multArray[i][j]);
		}
		printf("\n");
	}

	return 0;
}

