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
void update_table(int array[], int length, int x, int y);


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

	while( !check_three_in_a_row(board, N) || !fullTable ) { // Not three in a row, not full
		// Display table
		display_table(board, N);

		// Ask user for x and y coordinates
		printf("ENTER THE THINGY");
		scanf("%d,%d", &x, &y);
		while(check_legal_option(board, N, x-1, y-1)) { // Ask user while they have not inputted a legal option
			printf("ENTER THE THINGY");
			scanf("%d,%d", &x, &y);
		}

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
	int *arrayPtr = array;
	for(arrayPtr; arrayPtr < array + length; arrayPtr++) {
		*arrayPtr = -1;
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
	for(arrayPtr; arrayPtr < array + length; arrayPtr++) {
		if((arrayPtr - (array + length)) % 3 == 2) { // if this is the end of the row
			printf("|\n");
		}

		printf("|");

		if(*arrayPtr == -1) {
			printf("\t");
		}
		else if(*arrayPtr == 0) {
			printf(" O\t");
		}
		else {
			printf(" X\t");
		}

	}
}

// Checks if a given move is legal with the board as is. Returns 0 if illegal, 1 if legal. 
int check_legal_option(int array[], int length, int x, int y) {
	int *arrayPtr = array;
	arrayPtr = arrayPtr + N*y + x; // Move arrayPtr so it's pointing at the right spot. 
	if(*arrayPtr == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

void update_table(int array[], int length, int x, int y);