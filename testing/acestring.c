// Giselle Serate
// April 12, 2016
// Trying test problem 5, trying to figure how to do with pointers


#include <stdio.h>


int main() {

	// This is what I had in part a)
	char a[30], b[30];
	char *p, *q;
	p = a;
	q = b;
	*p = '\0';
	*q = 'b';

	// This is how I had it in part b)
	*(q++) = 'a';
	*(q++) = 'c';
	*(q++) = 'e';
	*(q++) = '\0';

	printf("%s\n", b);

	return 0;

}