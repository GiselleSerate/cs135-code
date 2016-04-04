// Giselle Serate
// April 4, 2016
// Converts a number of time in seconds to hours, minutes, and seconds. 

#include <stdio.h>


void print_time(long allTheSeconds, int *hrsPtr, int *minsPtr, int *secsPtr);


int main() {
	long allTheSeconds;
	int hrs, mins, secs;

	printf("Enter the number of seconds: ");

	scanf("%ld", &allTheSeconds);

	print_time(allTheSeconds, &hrs, &mins, &secs);

	printf("The equivalent is: %d hour(s), %d minute(s), %d second(s).\n", hrs, mins, secs);

	return 0;
}


void print_time(long allTheSeconds, int *hrsPtr, int *minsPtr, int *secsPtr) {
	*hrsPtr = allTheSeconds/3600;
	*minsPtr = (allTheSeconds - *hrsPtr * 3600) / 60;
	*secsPtr = allTheSeconds - (*hrsPtr * 3600) - (*minsPtr * 60);
}
