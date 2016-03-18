// Giselle Serate
// March 18, 2016
// Project 6: tic tac toe
// P1 is 0 and O and P2 is 1 and X

#include <stdio.h>

#define N 3

// Function prototypes
void create_clear_table(int array[], int length);
int check_table_full(int array[], int length);
int check_three_in_a_row(int array[], int length);
void display_table(int array[], int length);
int check_legal_option(int array[], int length, int x, int y);
void update_table(int array[], int length, int x, int y);

int main() {

	// Make a matrix
	int board[3];

	// Tracker of current player, 0 for P1, 1 for P2
	int whoseTurn = 0;

	// Stores user's last inputted x and y

	// Clear matrix
	create_clear_table(board, N);

	int fullTable = check_table_full(board, N);

	while( !check_three_in_a_row(board, N) || !fullTable ) { // Not three in a row, not full
		// Display table
		display_table(board, N);

		printf("ENTER THE THINGY");
		scanf("%d,%d",&x, &y);
		while(check_legal_option(board, N)) { // Ask user while they have not inputted a legal option
			printf("ENTER THE THINGY");
			scanf("%d,%d", &x, &y);
		}

		// Change whoseTurn
		whoseTurn = !whoseTurn;

		// Check again for looping back; just so I don't have to do an extra function call for the win/lose/tie case at the end
		fullTable = check_table_full;

	}	

	// Win case or lose case or tie case

	return 0;
}

// Function definitions