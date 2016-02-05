// Giselle Serate
// February 5, 2016
// Program that compares two people's ages. 

#include <stdio.h>

int main() {
	int m1, d1, y1, m2, d2, y2, oldest;
	printf("Enter the birthday of person 1 (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &m1, &d1, &y1);
	printf("Enter the birthday of person 2 (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &m2, &d2, &y2);
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