// Giselle Serate
// February 16, 2016
// Simulated robot will take in commands and update position. 

// HEADING KEY:
//	      N (0)
//   W (3)    E (1)
//	      S (2)

#include <stdio.h>

int main() {
	int choice;
	int xPos = 0, yPos = 0, heading = 1;
	int steps;

	for(;;) { // Infinite loop
		printf("#This program controls the movement of a simulated robot.\n(1) Drive forward\n(2) Drive backward\n(3) Turn left\n(4) Turn right\n(5) Display robot position\n(6) Reset to start position\n(7) Quit program\nPlease select from the above options: ");
		scanf("%d", &choice);

		switch(choice){
			case 1: // Drive forward
				printf("Please enter the number of steps: ");
				scanf("%d", &steps);
				switch(heading) {
					case 0: // Headed north
						yPos+=steps;
						break;
					case 1: // Headed east
						xPos+=steps;
						break;
					case 2: // Headed south
						yPos-=steps;
						break;
					case 3: // Headed west
						xPos-=steps;
						break;
				}
				break;
			case 2: // Drive backward
				printf("Please enter the number of steps: ");
				scanf("%d", &steps);
				switch(heading) {
					case 0: // Headed north
						yPos-=steps;
						break;
					case 1: // Headed east
						xPos-=steps;
						break;
					case 2: // Headed south
						yPos+=steps;
						break;
					case 3: // Headed west
						xPos+=steps;
						break;
				}
				break;
			case 3: // Turn left
				switch(heading) {
					case 0: // Headed north
						heading = 3; // Now west
						break;
					case 1: // Headed east
						heading = 0; // Now north
						break;
					case 2: // Headed south
						heading = 1; // Now east
						break;
					case 3: // Headed west
						heading = 2; // Now south
						break;
				}
				break;
			case 4: // Turn right
				switch(heading) {
					case 0: // Headed north
						heading = 1; // Now east
						break;
					case 1: // Headed east
						heading = 2; // Now south
						break;
					case 2: // Headed south
						heading = 3; // Now west
						break;
					case 3: // Headed west
						heading = 0; // Now north
						break;
				}
				break;
			case 5: // Display robot position
				printf("#Robot location is (%d, %d); Heading: ", xPos, yPos);
				switch(heading) {
					case 0: // Headed north
						printf("North\n");
						break;
					case 1: // Headed east
						printf("East\n");
						break;
					case 2: // Headed south
						printf("South\n");
						break;
					case 3: // Headed west
						printf("West\n");
						break;
				}
				break;
			case 6: // Reset to start position
				xPos = 0;
				yPos = 0;
				heading = 1;
				break;
			case 7: // Quit program
				return 0;
				break;
			default: // Invalid choice
				printf("Selected option is not valid.\n");
				break;
		}
	}
}