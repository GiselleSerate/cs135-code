// Giselle Serate
// April 15, 2016
// Project 9: Tic tac toe with images and is also 4x4


// Conventions: 
// Player 1 is 1 is O; Player 2 is 2 is X; blank is 0
// Board is a 4x4 grid.
// currentPlayer: 0 is P1 and 1 is P2


// Includes, defines
#include <stdio.h>
#include <stdlib.h> // for itoa
#define WIDTH 4
#define HEIGHT 4


// Alla my function declarations
int check_four_in_a_row(int board[WIDTH][HEIGHT], int width, int height);
void clear_table(int board[WIDTH][HEIGHT], int width, int height);
void display_ascii(int board[WIDTH][HEIGHT], int width, int height);
void display_image(int board[WIDTH][HEIGHT], int width, int height);
int make_move(int board[WIDTH][HEIGHT], int width, int height, int x, int y, int currentPlayer);
int is_valid(int board[WIDTH][HEIGHT], int width, int height, int x, int y);


// my main man
int main() {

	char x = 0;
	int y = 0;
	char option = 'a';
	int currentPlayer = 0;
	int board[WIDTH][HEIGHT];
	int winCheck; // stores return of win checker
	clear_table(board, WIDTH, HEIGHT);

	while(1) {
		// ASKYYY
		printf("It is Player %s's turn. Please type in one of the following:\n", currentPlayer?"O":"X");
		printf("\"x, y\": makes move in square x, y\n\"c\": clears board\n\"s\": displays ASCII board\n\"p\": displays PGM board\n\n");

		// scanf an int, if it's an int then start reading as coordinates
		// else if it's a char then I dunno you can store it as option I guess
		scanf("%c", &x);
		if(x >= '0' && x <='9') { // ● a legal move 
			x = atoi((const char *) &x); // there are better ways than atoi like subtracting value of ascii but w/e
			scanf(", %d", &y);
			x--;
			y--;
			// X AND Y ARE NOW 0-INDEXED
			if(!make_move(board, WIDTH, HEIGHT, y, x, currentPlayer)) {
				printf("That isn't a valid move. Try again.\n\n");
				while((getchar())!='\n'); // Clears input buffer
				continue; // this takes you into the else case with the switch actually
			}

			// Here's your win check.
			winCheck = check_four_in_a_row(board, WIDTH, HEIGHT); // store for analysis
			if(winCheck) {
				if(winCheck == -1) { // Full board
					printf("You're tied and the board is full!\n");
				}
				else { // A player wins, wincheck is 1 or 2
					printf("Player %d wins!\n", winCheck);
				}
			}
			// else keep playing because the board's not full and nobody won

			printf("Changing currentPlayer\n");
			currentPlayer = !currentPlayer;
		}
		else {
			option = x;
			switch(option) {
				case 'c': // ● c: clear the board
					clear_table(board, WIDTH, HEIGHT);
					break;
				case 's': // ● s: print the state of the board as displayed in Figure 1 
					display_ascii(board, WIDTH, HEIGHT);
					break;
				case 'p': // ● p: print the state of the board as an image (see below for more info)
					display_image(board, WIDTH, HEIGHT);
					break;
				case '1': // invalid move
					break;
				default:
					printf("%d I don't know how to do that.\n", (int)option);
					break;
			}
		}
		while((getchar())!='\n'); // Clears input buffer.
	}
}


// Function definition party land

// Takes in array
// Returns 1 if P1 has 4 in a row, 2 if P2 has 4 in a row, 0 if no one has 4 in a row; the full case returns a -1
int check_four_in_a_row(int board[WIDTH][HEIGHT], int width, int height) {
	int whoseTurn = 0;
	int i, j;
	// Check if P1 has won, then increment whoseTurn and check again for P2
	for(whoseTurn = 1; whoseTurn < 3; whoseTurn++) {		
		// Check verticals
		for(i = 0; i < WIDTH; i++) {
			if(board[i][0] == whoseTurn && board[i][1] == whoseTurn && board[i][2] == whoseTurn && board[i][3] == whoseTurn) {
				// printf("OOOH BABY A VERTICAL\n");
				return whoseTurn;
			}
		}

		// Check horizontals
		for(j = 0; j < HEIGHT; j++) {
			if(board[0][j] == whoseTurn && board[1][j] == whoseTurn && board[2][j] == whoseTurn && board[3][j] == whoseTurn) {
				// printf("OOOH BABY A HORIZONTAL\n");
				return whoseTurn;
			}
		}

		// Check positive slope diagonal
		if(board[0][3] == whoseTurn && board[1][2] == whoseTurn && board[2][1] == whoseTurn && board[3][0] == whoseTurn) {
			// printf("OOOH BABY A POS SLOPE DIAG\n");
			return whoseTurn;
		}

		// Check negative slope diagonal
		// Check positive slope diagonal
		if(board[0][0] == whoseTurn && board[1][1] == whoseTurn && board[2][2] == whoseTurn && board[3][3] == whoseTurn) {
			// printf("OOOH BABY A NEG SLOPE DIAG\n");
			return whoseTurn;
		}
	}

	// Check if there are empty spaces
	for(i = 0; i < WIDTH; i++) {
		for(j = 0; j < HEIGHT; j++) {
			if(board[i][j] == 0) {
				return 0;
			}
		}
	}

	// If you're here, you evidently haven't gotten any empty spaces. 
	return -1;
}

// Takes in array
// Sets entire board to 0. Does not return anything.
void clear_table(int board[WIDTH][HEIGHT], int width, int height) {
	int i, j; // indexing baby
	for(i = 0; i < width; i++) {
		for(j = 0; j < height; j++) {
			board[i][j] = 0;
		}
	}
	printf("The board has been cleared.\n\n");
}

// Takes in array
// Prints board as ascii characters. Does not return anything.
// Should look like:
// _____________ 4*WIDTH+1 underscores
// |sss|sss|sss| 1 pipe, 3 space (repeat until end line) 1 pipe, 1 \n
// |sXs|sOs|s s| 1 pipe, 1 space, SYMBOL, 1 space (repeat until end line) 1 pipe, 1 \n
// |___|___|___| 1 pipe, 3 underscore (repeat until end line) 1 pipe, 1 \n
void display_ascii(int board[WIDTH][HEIGHT], int width, int height) {
	int i, j, a; // indexing baby; a is my personal counter. Please no touchy.

	printf("This is the current game state:\n");

	for(a = 0; a < 4 * WIDTH + 1; a++) { 
		printf("_");
	}
	printf("\n");

	for(i = 0; i < width; i++) {
		for(a = 0; a < height; a++) {
			printf("|   ");
		}
		printf("|\n");
		for(j = 0; j < height; j++) {
			if(board[i][j] == 0) {
				printf("|   ");
			}
			else {
				printf("| %c ", board[i][j]-1?'O':'X');
			}
		}
		printf("|\n");
		for(a = 0; a < height; a++) {
			printf("|___");
		}
		printf("|\n");
	}
	printf("\n");
}

// Takes in array
// Prints board as a pgm image. Does not return anything.
// 5x 255 [blank] 1x 0 5x 128 [X] 1x 0 5x 0 [O] (repeat this until end of line)
// Repeat line 5x then line of 0s
void display_image(int board[WIDTH][HEIGHT], int width, int height) {
	int i, j, a, b; // Save a and b for me. Don't touch it.

	printf("This is the current game state:");

	// image header
	printf("P2\n# image.pgm\n23 23\n255\n"); 

	for(i = 0; i < WIDTH; i++) {
		for(a = 0; a < 5; a++) {
			for(j = 0; j < HEIGHT; j++) {
				for(b = 0; b < 5; b++) {
					if(board[i][j] == 0) { // Blank: 255
						printf("255 ");
					}
					else if(board[i][j] == 1) { // O:0
						printf("0 ");
					}
					else { // X: 128 
						printf("128 ");
					}
				}
				if(j < 3) {
					printf("0 ");
				}
			}
			printf("\n");
		}
		for(a = 0; a < 5 * WIDTH + 4; a++) {
			printf("0 ");
		}
		printf("\n");
	}

	printf("\n");
}

// Takes in array and also move coordinates and also information on the current player
// If it's a valid move, makes the move and returns 1. If it's not valid, returns 0 so main can ask again and re-call this function
int make_move(int board[WIDTH][HEIGHT], int width, int height, int x, int y, int currentPlayer) {
	// WRITE
	if(is_valid(board, width, height, x, y)) {
		board[x][y] = currentPlayer+1;
		return 1;
	}
	else {
		// Not a valid move.
		return 0;
	}
}

// Takes in array and also move coordinates to see if the square is empty. Also within bounds.
// Returns 0 for not valid move and 1 for valid move.
int is_valid(int board[WIDTH][HEIGHT], int width, int height, int x, int y) {
	if(x < width && x >= 0 && y < height && y >= 0 && board[x][y] == 0) {
		return 1;
	}
	return 0;
}