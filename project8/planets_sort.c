// Giselle Serate
// April 11, 2016
// Sorts planets by alphabetical order. 


#include <stdio.h>


int string_compare(char* str1, char* str2);


int main(int argc, char* argv[]) {

	char* planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Neptune", "Uranus", "Pluto"}; // Yes, I'm including Pluto.
	int i = 0, j = 0; // We like counting, yes we do
	int howManyPlanets;

	while(planets[i]) {
		printf("this is planets[%d]: %s\n", i, planets[i]);
		i++;
	}

	howManyPlanets = i;

	// for i = 0 to size of planets array - 1 
	for(i = 0; i < howManyPlanets; i++) {

		// for j = size of planets array - 1 down to i + 1 
		for(j = howManyPlanets - 1; j < i + 1; j--) {

			// if planets[j] is prior to planets[j -1] alphabetically
			if(string_compare(planets[j], planets[j-1])) {

				// then exchange planets[j] with planets[j-1]
			}
		}

	}

	return 0;
}

// I made up my own return values because the instructions were not helpful.
// If str1 comes first, returns 0 (FALSE), if str2 comes first, returns 1 (TRUE), if neither, returns -1 (TRUE)
int string_compare(char* str1, char* str2) {
	while(*str1 != '\0' && *str2 != '\0') {
		if(*str1 < *str2) {
			return 0;
		}
		else if (*str1 > *str2) {
			return 1;
		}
	}
	// At this point both strings have ended without a difference.
	return -1;
}