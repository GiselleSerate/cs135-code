// Giselle Serate
// March 18, 2016
// Project 6: tic tac toe
// P1 is 0 and O and P2 is 1 and X; blank is -1

#include <stdio.h>

#define SIZE 3 // Dimension of board
#define LENGTH SIZE * SIZE // Length of array board


// Function prototypes
void create_clear_table(int array[], int length);
int check_table_full(int array[], int length);
int check_three_in_a_row(int array[], int length, int whoseTurn);
void display_table(int array[], int length);
int check_legal_option(int array[], int length, int x, int y);
void update_table(int array[], int length, int x, int y, int whoseTurn);


int main() {

	// Make a matrix for the board
	int board[LENGTH];

	// Tracker of current player, 0 for P1, 1 for P2
	int whoseTurn = 0;

	// Stores user's last inputted x and y, variable to store output of check_table_full
	int x, y, fullTable;

	// Clear matrix
	create_clear_table(board, LENGTH);

	fullTable = check_table_full(board, LENGTH);

	// Prompts user with explanatory but kind of unhelpful text.
	printf("This program plays the game of tic-tac-toe");

	while( !check_three_in_a_row(board, LENGTH, whoseTurn) && !fullTable ) { // Not three in a row, not full
		// Display table
		display_table(board, LENGTH);

		// Ask appropriate user for x and y coordinates
		printf("Enter the section of %c for Player %d [row,col]:", (whoseTurn == 0)?'O':'X', (whoseTurn == 0)?1:2);
		scanf("%d,%d", &x, &y);
		while(check_legal_option(board, LENGTH, x, y)) { // Ask user while they have not inputted a legal option
			printf("Invalid selection\nEnter the section of %c for Player %d [row,col]: ", (whoseTurn == 0)?'O':'X', (whoseTurn == 0)?1:2);
			scanf("%d,%d", &x, &y);
		}

		update_table(board, LENGTH, x, y, whoseTurn);

		// Change whoseTurn
		whoseTurn = !whoseTurn;

		// Check again for looping back; just so I don't have to do an extra function call for the win/lose/tie case at the end
		fullTable = check_table_full(board, LENGTH);

	}

	// Win case or lose case or tie case
	display_table(board, LENGTH);
	if(fullTable) { // Tie case
		printf("Game over, no player wins.\n");
	}
	else { // Win case
		printf("Congratulations, Player %d wins! \n", whoseTurn + 1);
	}

	return 0;
}


// Function definitions

// Takes in an array and its length and sets the entire table to blank (aka -1)
void create_clear_table(int array[], int length) {
	int *arrayPtr = array;
	for(arrayPtr; arrayPtr < array + LENGTH; arrayPtr++) {
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
int check_three_in_a_row(int array[], int length, int whoseTurn) { // I really only have to check the inverse of whoseTurn because only the player who made the last move can actually win
	whoseTurn = !whoseTurn; // inverse: see above.
	if(array[6] == whoseTurn && array[4] == whoseTurn && array[2] == whoseTurn|| // 0
		array[0] == whoseTurn && array[4] == whoseTurn && array[8] == whoseTurn|| // 1
		array[3] == whoseTurn && array[4] == whoseTurn && array[5] == whoseTurn|| // 2
		array[1] == whoseTurn && array[4] == whoseTurn && array[7] == whoseTurn|| // 3
		array[0] == whoseTurn && array[1] == whoseTurn && array[2] == whoseTurn|| // 4
		array[6] == whoseTurn && array[7] == whoseTurn && array[8] == whoseTurn|| // 5
		array[0] == whoseTurn && array[3] == whoseTurn && array[6] == whoseTurn|| // 6
		array[2] == whoseTurn && array[5] == whoseTurn && array[8] == whoseTurn) { // 7

		return whoseTurn + 1; // Returns who actually won (1 for Player 1, 2 for player 2)

	}
	else { // I mean, there's not really a point with the else, if caught by the if the function returns and doesn't get here
		return 0;
	}
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
	arrayPtr = array + SIZE*(y-1) + x - 1; // Move arrayPtr so it's pointing at the right spot. 
	if(x > 3 || x < 1 || y > 3 || y < 1) {
		return 1;
	}
	// else if(*arrayPtr != -1) {
	else if(*arrayPtr != -1) {
		return 1;
	}
	else {
		return 0;
	}
}

// Changes values in actual array according to what the latest x and y are, does not return anything
void update_table(int array[], int length, int x, int y, int whoseTurn) { // Note that x and y are userdefined x and y
	int *arrayPtr = array;
	arrayPtr = arrayPtr + SIZE*(y-1) + x - 1; // Move arrayPtr so it's pointing at the right spot. 
	*arrayPtr = whoseTurn;
}