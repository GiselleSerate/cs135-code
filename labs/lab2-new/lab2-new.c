// Giselle Serate
// February 8, 2016
// Lab 2 New: Gets largest city from each area code. 

// Groupings: 
// 0 - Albany: 229
// 1 - Atlanta: 404, 470, 678, 770
// 2 - Macon: 478
// 3 - Columbus: 706, 762
// 4 - Savannah: 912

#include <stdio.h>

int main() {
	int code;
	printf("Enter a three-digit area code: ");
	scanf("%d", &code);

	if(code == 229) {
		printf("The largest city in your area code is Albany.\n");
	}
	else if(code == 404||code == 470||code == 678||code == 770) {
		printf("The largest city in your area code is Atlanta.\n");
	}
	else if(code == 478) {
		printf("The largest city in your area code is Macon.\n");
	}
	else if(code == 706||code == 762) {
		printf("The largest city in your area code is Columbus.\n");
	}
	else if(code == 912) {
		printf("The largest city in your area code is Savannah.\n");
	}
	else {
		printf("There is no area code %d in Georgia.\n", code);
	}

	return 0;
}