// Giselle Serate
// May 8, 2016
// 2D arrays eh


#include <stdio.h>
#include <stdlib.h>


int main() {
	// Making a 2x2 array. No bugs here.
	int i, j, arree[2][2] = {{1,2},{3,4}};
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			printf("%d\n", arree[i][j]);
		}
	}

	// Pointerly mallocing a 2x2. wowmygod I am cool, this works
	int *pointerly = malloc(2*sizeof(int*)); 

	*pointerly = 2;

	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			printf("%d\n", *(pointerly+i*2+j));
		}
	}

	return 0;
}