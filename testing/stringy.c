// Giselle Serate
// May 8, 2016
// Strinnnnggggs galore. For no good reason I guess.


#include <stdio.h>
#include <string.h>


int main() {
	// string literals
	char *p;
	p = "abc";
	printf("%s", p);
	char *q = "abc";
	printf(" %s\n", q);
	char s[30] = "lollita";
	printf("%s\n", s);
	puts(p);

	// stringy thingies get lengthied
	printf("%ld\n", strlen(p));

	return 0;
}