// Giselle Serate
// March 3, 2016
// Prints certain "images"

#include <stdio.h>

int main() {

	int userNum;
	int i, j;

	printf("Enter a number: ");
	scanf("%d", &userNum);

	if(userNum%2 == 0) {
		printf("You must enter an odd number.\n");
		userNum++;
	}

	int image[userNum][userNum]; // Cannot use an initializer.

	// // Initializes and can print black image (if you uncomment)
	// for(i = 0; i < userNum; i++) {
	// 	for(j = 0; j < userNum; j++) {
	// 		image[i][j] = 0;
	// 		// printf("%d\t", 0);
	// 	}
	// 	// printf("\n");
	// }

	for(i = 0; i < userNum; i++) {
		for(j = 0; j < userNum; j++){
			if(i == j || (i + j) == (userNum - 1)) {
				image[i][j] = 255;
			}
			else {
				image[i][j] = 0;
			}
			printf("%d\t", image[i][j]);
		}
		printf("\n");
	}

	return 0;
}