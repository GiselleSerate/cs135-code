// Giselle Serate
// March 3, 2016
// Prints certain "images"

#include <stdio.h>

int main() {

	int userNum;
	int i, j;
	int even = 0;

	printf("Enter a number: ");
	scanf("%d", &userNum);

	if(userNum%2 == 0) {
		printf("You must enter an odd number.\n");
		userNum++;
		even = 1;
	}

	// beginning printf statement
	printf("P2\n# test.pgm\n%d %d\n255\n", userNum, userNum);

	int image[userNum][userNum]; // Cannot use an initializer.

	if(even == 0) {
		// Initializes and prints black image
		for(i = 0; i < userNum; i++) {
			for(j = 0; j < userNum; j++) {
				image[i][j] = 0;
				printf("%d ", 0);
			}
			printf("\n");
		}
		printf("\n");
	}

	for(i = 0; i < userNum; i++) {
		for(j = 0; j < userNum; j++){
			if(i == j || (i + j) == (userNum - 1)) {
				image[i][j] = 255;
			}
			else {
				image[i][j] = 0;
			}
			printf("%d ", image[i][j]);
		}
		printf("\n");
	}

	return 0;
}