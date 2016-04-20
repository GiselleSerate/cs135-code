// Giselle Serate
// April 18, 2016
// Lab 10: Uses bitwise operators to do things.


#include <stdio.h>


int main() {
	int userNum, bitsSet = 0, beaterCopy; 
	int i; // Everyone's favorite counter variable

	printf("Please enter a number: ");
	scanf("%d", &userNum);

	// - Counts the number of bits that are equal to 1 in the binary representation of that number 
	for(i = 0; i < 8; i ++) {
		if (userNum & 1 << i) {
			bitsSet++;
		}
	}
	// and displays that to the screen
	printf("%d bits are set.\n", bitsSet);

	printf("The number with odd bits set is ");
	// - Sets all the odd-number bits of the number to 1 and displays the result in a form of zeros and ones
	for(i = 7; i > -1; i--) {
		if(i % 2 == 1) { // is odd, is 1
			printf("1");
			userNum |= 1 << i;
		}
		else { // is even, what is it before?
			if (userNum & 1 << i) {
				printf("1");
			}
			else {
				printf("0");
			}
		}
	}

	printf(".\nThe number with even bits cleared is ");
	// - Clears all the even-numbered bits to 0 and displays the result in a form of zeros and ones
	// Note that I don't have to actually change the userNum, as displaying's already happening and we return immediately afterwards. 
	for(i = 7; i > -1; i--) {
		if(i % 2 == 0) { // is even, is 0
			printf("0");
		}
		else { // is odd, what is it before?
			if (userNum & 1 << i) {
				printf("1");
			}
			else {
				printf("0");
			}
		}
	}
	printf(".\n");

	return 0;
}