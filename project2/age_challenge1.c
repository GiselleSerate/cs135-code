// Giselle Serate
// February 5, 2016
// Age comparing program that will reject wrong input. 

#include <stdio.h>

int main() {
	int m1, d1, y1, m2, d2, y2, oldest, error;

	printf("Enter the birthday of person 1 (mm/dd/yyyy): "); // initial ask for person 1
	scanf("%d/%d/%d", &m1, &d1, &y1);

	if (m1 < 1 || m1 > 12) {
		printf("Month %d is invalid.", m1);
		error = 1;
	}
	else if (d1 < 1 || d1 > 31) {
		printf("Day %d is invalid.", d1);
		error = 1;
	}
	else if (y1 < 1900 || y1 > 2016) {
		printf("Year %d is invalid.", y1);
		error = 1;
	}
	else {
		error = 0;
	}

	if (error == 1) { // re-ask if it's wrong for person 1
		printf("Enter the birthday of person 1 (mm/dd/yyyy): ");
		scanf("%d/%d/%d", &m1, &d1, &y1);
	}
	
	printf("Enter the birthday of person 2 (mm/dd/yyyy): "); // initial ask for person 2
	scanf("%d/%d/%d", &m2, &d2, &y2);

	if (m2 < 1 || m2 > 12) {
		printf("Month %d is invalid.", m2);
		error = 1;
	}
	else if (d2 < 1 || d2 > 31) {
		printf("Day %d is invalid.", d2);
		error = 1;
	}
	else if (y2 < 1900 || y2 > 2016) {
		printf("Year %d is invalid.", y2);
		error = 1;
	}
	else {
		error = 0;
	}

	if (error == 1) { // re-ask if it's wrong for person 2
		printf("Enter the birthday of person 2 (mm/dd/yyyy): ");
		scanf("%d/%d/%d", &m2, &d2, &y2);
	}

	// beginning of code that compares dates
	if (y1 < y2) {
		// 1 oldest
		oldest = 1;
	}
	else if (y1 > y2) {
		// 2 oldest
		oldest = 2;
	}
	else if (m1 < m2) {
		// 1 oldest
		oldest = 1;
	}
	else if (m1 > m2) {
		// 2 oldest
		oldest = 2;
	}
	else if (d1 < d2) {
		// 1 oldest
		oldest = 1;
	}
	else if (d1 > d2) {
		// 2 oldest
		oldest = 2;
	}
	else {
		// same age
		printf("They are the same age.\n");
		return 0;
	}
	printf("Person %d is the oldest.\n", oldest);
	return 0;
}