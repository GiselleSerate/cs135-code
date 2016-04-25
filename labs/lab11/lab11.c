// Giselle Serate
// April 25, 2016
// Lab 11 (not 10) to make a function that creates an array.


#include <stdio.h>
#include <stdlib.h>


// Declares 
int *create_array (int n, int initial_value);


int main() {
	int i; // what else do you use i for of course it's a counter variable
	int n, initial_value;
	int *hereBePointer;
	FILE *fp;

	printf("Please enter the size of the array and the integer value that it will be initialized at in the format [size, initial value]\n");
	scanf("%d, %d", &n, &initial_value);
	hereBePointer = create_array(n, initial_value);

	fp = fopen("arrayb.dat", "wb");
	// fp = fopen("array.txt", "w");
	if(fp == NULL) {
		printf("I can't open this file.\n");
		exit(EXIT_FAILURE);
	}
	else {
		for(i = 0; i < n; i++) { // it through array made by create_array and put it all in fp
			printf("%d %d\n", i, *(hereBePointer+i));
			// fprintf(fp, "%d ", *(hereBePointer + i));
		}
		fwrite(hereBePointer, n, sizeof(int), fp);
	}

	// clean up yoself I'm not your mother
	free(fp);
	fclose(fp);
	return 0;
}


// Defines
int *create_array (int n, int initial_value) {
	// is cool counter var
	int i;

	int *arrayPtr;
	arrayPtr = malloc(n * sizeof(int));

	if(&arrayPtr != NULL) {
		// carry on assigning values
		for(i = 0; i < n; i++) {
			*(arrayPtr + i) = initial_value;
		}
		return arrayPtr;
	}
	else {
		printf("The array cannot be created.\n");
		return NULL;
	}
}