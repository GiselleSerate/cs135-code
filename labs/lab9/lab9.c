// Giselle Serate
// April 11, 2016
// Removes filename from a URL. 

#include <stdio.h>


void remove_filename(char* url);


int main() {

	char url[] = "http://www.knking.com/index.html";

	printf("%s\n", url);

	remove_filename(url);

	printf("%s\n", url);

	return 0;

}


// takes in pointer, changes string to remove filename
// Process: searches for end of string, then goes backward to first slash it can find counting from the end of the string, making null chars as it goes.
void remove_filename(char* url) {
	// I don't remember the string idiom, so I'm going to make it up. 
	while(*url++); // Post-increments the pointer if the character is NOT the null character
	// Now it is pointing past, so:
	url--;

	// Now we go backwards in search of the slash.
	while(*url != '/') {
		*url = '\0'; // it's a null now // I don't actually need to do this because the null TERMINATES the string. 
		url--; // go backward
	}

	*url = '\0'; // Get rid of that slash.
}