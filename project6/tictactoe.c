// Giselle Serate
// March 18, 2016
// Project 6: tic tac toe
// P1 is 0 and O and P2 is 1 and X; blank is -1

#include <stdio.h>

#define SIZE 3 // Dimension of board
#define N SIZE * SIZE // Length of array board


// Function prototypes
void create_clear_table(int array[], int length);
int check_table_full(int array[], int length);
int check_three_in_a_row(int array[], int length);
void display_table(int array[], int length);
int check_legal_option(int array[], int length, int x, int y);
void update_table(int array[], int length, int x, int y, int whoseTurn);


int main() {

	// Make a matrix for the board
	int board[SIZE];

	// Tracker of current player, 0 for P1, 1 for P2
	int whoseTurn = 0;

	// Stores user's last inputted x and y, variable to store output of check_table_full
	int x, y, fullTable;

	// Clear matrix
	create_clear_table(board, N);

	fullTable = check_table_full(board, N);

	// Prompts user with explanatory but kind of unhelpful text.
	printf("This program plays the game of tic-tac-toe");

	while( !check_three_in_a_row(board, N) || !fullTable ) { // Not three in a row, not full
		// Display table
		display_table(board, N);

		// Ask appropriate user for x and y coordinates
		printf("Enter the section of %c for Player %d [row,col]:", (whoseTurn == 0)?'O':'X', (whoseTurn == 0)?1:2);
		scanf("%d,%d", &x, &y);
		while(check_legal_option(board, N, x, y)) { // Ask user while they have not inputted a legal option
			printf("Invalid selection\nEnter the section of %c for Player %d [row,col]:", (whoseTurn == 0)?'O':'X', (whoseTurn == 0)?1:2);
			scanf("%d,%d", &x, &y);
		}

		update_table(board, N, x, y, whoseTurn);

		// Change whoseTurn
		whoseTurn = !whoseTurn;

		// Check again for looping back; just so I don't have to do an extra function call for the win/lose/tie case at the end
		fullTable = check_table_full(board, N);

	}	

	// Win case or lose case or tie case

	return 0;
}


// Function definitions

// Takes in an array and its length and sets the entire table to blank (aka -1)
void create_clear_table(int array[], int length) {
	// printf("Size is %d and N is %d", SIZE, N); // DEBUG LINE
	int *arrayPtr = array;
	for(arrayPtr; arrayPtr < array + N; arrayPtr++) {
		*arrayPtr = -1;
		// printf("%d ", *arrayPtr); // DEBUG LINE
	}
}

// Checks if the table's full of values; if it's full, put 1, if it's not full, put 0
int check_table_full(int array[], int length) {
	int *arrayPtr = array;
	for(arrayPtr; arrayPtr < array + length; arrayPtr++) { // Iterate through array
		if(*arrayPtr < 0) { // If the space is blank
			return 0;
		}
	}
	return 1;
}

// Checks if there is a three in a row, returns 0 if none, returns 1 if it's with Player 1 and 2 if it's with Player 2. 
int check_three_in_a_row(int array[], int length) {
	// PLEASE WRITE ME
}

// Print out the table.
void display_table(int array[], int length) {
	int *arrayPtr = array;
	printf("\nThe current state of the game is:\n\nColumn:1   2   3\nRow:  ___ ___ ___\n     |   |   |   |\n  1  "); // Print header and top of first row
	for(arrayPtr; arrayPtr < array + length; arrayPtr++) {
		if((arrayPtr - (array + length)) % SIZE == 0 && !(arrayPtr - array == 0)) { // If this is the end of the row and not the first time, print bottom of this row and the top of the next one
			printf("|\n");
			printf("     |___|___|___|\n     |   |   |   |\n  %ld  ", (arrayPtr - array)/SIZE + 1);
		}

		printf("|");

		if(*arrayPtr == -1) {
			printf(" b ");
		}
		else if(*arrayPtr == 0) {
			printf(" O ");
		}
		else {
			printf(" X ");
		}

	}
	printf("|\n");
	printf("     |___|___|___|\n\n"); // Print bottom of last row
}

// Checks if a given move is legal with the board as is. Returns 0 if illegal, 1 if legal. 
int check_legal_option(int array[], int length, int x, int y) { // Note that x and y are the userdefined x and y
	int *arrayPtr = array;
	arrayPtr = arrayPtr + N*(y-1) + x - 1; // Move arrayPtr so it's pointing at the right spot. 
	if(x > 3 || x < 1 || y > 3 || y < 1) {
		printf("LEGAL ERROR: Out of range (%d, %d)\n", x, y); // DEBUG LINE
		return 1;
	}
	else if(*arrayPtr != -1) {
		printf("LEGAL ERROR: Space not blank (%d, %d, %d)\n", x, y, *arrayPtr); // DEBUG LINE
		return 1;
	}
	else {
		printf("LEGAL ACTION: This is okay (%d, %d)\n", x, y); // DEBUG LINE
		return 0;
	}
}

// Changes values in actual array according to what the latest x and y are, does not return anything
void update_table(int array[], int length, int x, int y, int whoseTurn) { // Note that x and y are userdefined x and y
	int *arrayPtr = array;
	arrayPtr = arrayPtr + N*(y-1) + x - 1; // Move arrayPtr so it's pointing at the right spot. 
	*arrayPtr = whoseTurn;
	// printf("\nwhoseTurn is:%d and x: %d and y: %d\n", whoseTurn, x, y); // DEBUG LINE
}