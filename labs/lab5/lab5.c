// Giselle Serate
// March 7, 2016
// lab 5: reads in a matrix and returns a weird one with wraparound addition. 

#include <stdio.h>

#define N 5

int main() {
	int i, j; // rows, cols iterators
	int userMat[N][N];
	int finalMat[N][N];

	printf("Enter a %dx%d matrix of integers. \n", N, N);
	for(i = 0; i < N; i++) {
		printf("Row number %d: ", i + 1);
		for(j = 0; j < N; j++) {
			scanf("%d", &userMat[i][j]);
		}
	}

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(j+1 < N) {
				finalMat[i][j] = userMat[i][j] + userMat[i][j+1];
			}
			else {
				finalMat[i][j] = userMat[i][j] + userMat[i][0];
			}
			printf("%d\t", finalMat[i][j]);
		}
		printf("\n");
	}

	printf("\nThe new matrix is:\n");


	return 0;
}