// Giselle Serate
// February 1, 2016
// Lab 2
// Computes sum of the numbers in a matrix
// by row, by column, and by diagonal

#include <stdio.h>

int main () {
	int a, b, c, d;
	// Format:
	// a   b
	// c   d
	int row1, row2, col1, col2, dia1, dia2;

	printf("Enter the first row of two integers: ");
	scanf("%d%d", &a, &b);
	printf("Enter the second row of two integers: ");
	scanf("%d%d", &c, &d);

	row1 = a + b;
	row2 = c + d;
	col1 = a + c;
	col2 = b + d;
	dia1 = a + d;
	dia2 = b + c;

	printf("\nNumbers to be added:\n");
	printf("%-10d%-10d\n%-10d%-10d\n\n", a, b, c, d);
	printf("Row sums: %d %d\n", row1, row2);
	printf("Column sums: %d %d\n", col1, col2);
	printf("Diagonal sums: %d %d\n", dia1, dia2);
	return 0;
}