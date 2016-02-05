// Project 1 Problem 2
// Formats inventory list inputted by user. 
// Giselle Serate
// January 28, 2016

#include <stdio.h>

int main() {
	int item, quantity, month, day, year;
	float price;
	printf("Enter the item ID: ");
	scanf("%d", &item);
	printf("Enter the quantity of items: ");
	scanf("%d", &quantity);
	printf("Enter the price per item: ");
	scanf("%f", &price);
	printf("Enter the date of purchase (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);
	printf("Item\tQuantity\tUnit\t\tPurchase\n\t\t\tPrice\t\tDate\n");
	printf("%d\t%d\t\t$%7.2f\t%d/%d/%d\n", item, quantity, price, month, day, year);
	return 0;
}