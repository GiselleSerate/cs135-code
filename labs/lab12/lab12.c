// Giselle Serate
// May 2, 2016
// lab 12 to do things with arrays and pointers


#include <stdio.h>


void increment_value (int *value); 
int sum_array (const int *a, int n); 


int main() {

	int i;
	int array[10]; 

	for(i = 0; i < 10; i++) {
		array[i] = i + 1;
	}

	printf("The sum is %d.\n", sum_array(array, 10));

	for(i = 0; i < 10; i++) {
		increment_value(array + i);
	}

	printf("After incrementing, the sum is %d.\n", sum_array(array, 10));

	return 0;

}


// This is a function that takes in an int pointer and increments the value in the int pointer by 1. 
void increment_value (int *value) {
	*value += 1;
}

// This function takes in a const int and an int. 
int sum_array (const int *a, int n) {

	int sum = 0;
	int *mine = a; // i know it's constant but I want a copy darnit
	
	while(mine < a + n) { // You said not to use i. So I didn't use i. It's giving me a warning, but it's working.
		sum += *(mine++);
	}

	return sum;
}