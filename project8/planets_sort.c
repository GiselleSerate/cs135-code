// Giselle Serate
// April 11, 2016
// Sorts planets by alphabetical order. 


#include <stdio.h>


int string_compare(char* str1, char* str2);


int main(int argc, char* argv[]) {

	char* planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Neptune", "Uranus", "Pluto"}; // Yes, I'm including Pluto.
	int i = 0, j = 0; // We like counting, yes we do
	int howManyPlanets;
	char* holdMyCoke[1]; // This should be long enough to hold a planet, right, Steven?

	while(planets[i]) {
		// printf("this is planets[%d]: %s\n", i, planets[i]);// DEBUG LINE
		i++;
	}

	howManyPlanets = i;

	// for i = 0 to size of planets array - 1 
	for(i = 0; i < howManyPlanets; i++) {
		printf("NEW I LOOP, i = %d\n", i); // DEBUG LINE

		// for j = size of planets array - 1 down to i + 1 
		for(j = howManyPlanets - 1; j > i; j--) {
			printf("Into j loop, j = %d\n", j); // DEBUG LINE

			// if planets[j] is BEFORE planets[j -1] alphabetically or the same, the following happens (switch even if the same bc it doesn't matter)
			if(string_compare(planets[j-1], planets[j])) {
				printf("We strcmpd and was true.\n");
				// then exchange planets[j] with planets[j-1] for FORWARD ALPHABETIZATION
				// if(argv[2] == "a") {
				if(1) {
					printf("j is %s and j - 1 is %s\n", planets[j], planets[j-1]); // DEBUG LINE
					*holdMyCoke = planets[j]; // doopy a
					planets[j] = planets[j-1];
					planets[j-1] = *holdMyCoke;
				}
			}
			else { // This means it's after alphabetically
				printf("We strcmpd and was false.\n");
				// then exchange planets[j] with planets[j-1] for REVERSE ALPHABETIZATION
				if(0) {
					*holdMyCoke = planets[j];
					planets[j] = planets[j-1];
					planets[j-1] = *holdMyCoke;
				}
			}
		}

	}

	// PRINTY PRINTY
	if(argv[2] == "r") {
		printf("The planets in reverse alphabetical order are: ");
	}
	else { // Else assumes forward alphabetization
		printf("The planets in alphabetical order are: ");
	}

	for(i = 0; i < howManyPlanets - 1; i++) {
		printf("%s, ", planets[i]);
	}
	printf("%s\n", planets[i]);

	return 0;
};

// I made up my own return values because the instructions were not helpful.
// If str1 comes first, returns 0 (FALSE), if str2 comes first, returns 1 (TRUE), if neither, returns -1 (TRUE)
int string_compare(char* str1, char* str2) {
	while(*str1 != '\0' && *str2 != '\0') {
		if(*str1 < *str2) {
			printf("Boutta return 0\n"); // DEBUG LINE
			return 0;
		}
		else if (*str1 > *str2) {
			printf("Boutta return 1\n"); // DEBUG LINE
			return 1;
		}
		str1++;
		str2++;
	}
	// At this point both strings have ended without a difference.
	printf("Boutta return -1\n"); // DEBUG LINE
	return -1;
}