#include <stdio.h>
#include <stdlib.h>
char a[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
void Board();
void printBoard();
int markBoard(int choice, char mark);
int checkWinner();
int swap(int *, int *);
int main() {
	int player, *p, player1 = 1, player2 = 2, checker, marker, choice,markplayer;
	char mark;
	Board();
	printf("\n\n\tMenu\t\n1)play with X\n2)play with O\n3)Exit\n\n");
	scanf("%d", &markplayer);
  getchar();
	do {
		system("cls");
		if (markplayer == 1) {
			mark = 'X';
		} else if(markplayer==2) {
			mark = 'O';
		}
		else {break;}
		printBoard();
		player = swap(&player2, &player1);
		if (player == 1) {
			mark = 'X';
		} else {
			mark = 'O';
		}
		printf("Player %d enter your choice:", player);
		scanf("%d", &choice);

		marker = markBoard(choice, mark);
		// decrement player if the input choice is invalid
		if (marker == 0) {
			player = swap(&player1, &player2);
		}
		checker = checkWinner();
	} while (checker == -1);


if (checker == 1) { printBoard();
	printf("Player %d has won *.*\n\n", player);
} else if(checker == 0 && markplayer!=3) {printBoard();
	printf("<----------Game Draw---------->\n\n");
}
printf("\n\nThanks for using Malak's Tic-Tac-Toe game <3 \n\n");
}
// print the board of the game
void Board() {
	char a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	printf("\n\n Welcome to Malak's simple Tic Tac Toe game ^.^\n\n Given a "
		   "sample "
		   "of board like this \n\n\n");
	printf(" \t Player 1 (X) \t Player 2 (O) \t \n\n");
	printf("    |    |    \n");
	printf(" %c  | %c  | %c \n", a[1], a[2], a[3]);
	printf("____|____|____\n");
	printf("    |    |    \n");
	printf(" %c  | %c  | %c \n", a[4], a[5], a[6]);
	printf("____|____|____\n");
	printf("    |    |    \n");
	printf(" %c  | %c  | %c \n", a[7], a[8], a[9]);
	printf("____|____|____\n");
	printf("    |    |    \n");
	printf("\n\nBased on this numbering as refrence choose where you want to "
		   "play\n\n\n");
}
void printBoard() {
	printf("\n\nMalak's simple tic-tac-toe\n\n");
	printf(" \t Player 1 (X) \t Player 2 (O) \t \n\n");
	printf("    |    |    \n");
	printf(" %c  | %c  | %c \n", a[1], a[2], a[3]);
	printf("____|____|____\n");
	printf("    |    |    \n");
	printf(" %c  | %c  | %c \n", a[4], a[5], a[6]);
	printf("____|____|____\n");
	printf("    |    |    \n");
	printf(" %c  | %c  | %c \n", a[7], a[8], a[9]);
	printf("____|____|____\n");
	printf("    |    |    \n");
}
int markBoard(int choice, char mark) {

//if the triggered box of number== choice is filled with X or O then return 0 to choose another choice

	if (choice == 1 && a[1] != 'X' && a[1] != 'O')
		a[1] = mark;
	else if (choice == 2 && a[2] != 'X' && a[2] != 'O')
		a[2] = mark;
	else if (choice == 3 && a[3] != 'X' && a[3] != 'O')
		a[3] = mark;
	else if (choice == 4 && a[4] != 'X' && a[4] != 'O')
		a[4] = mark;
	else if (choice == 5 && a[5] != 'X' && a[5] != 'O')
		a[5] = mark;
	else if (choice == 6 && a[6] != 'X' && a[6] != 'O')
		a[6] = mark;
	else if (choice == 7 && a[7] != 'X' && a[7] != 'O')
		a[7] = mark;
	else if (choice == 8 && a[8] != 'X' && a[8] != 'O')
		a[8] = mark;
	else if (choice == 9 && a[9] != 'X' && a[9] != 'O')
		a[9] = mark;
	else {
		return 0;
	}
	return 1;
}
int checkWinner() {
	// Winning conditions
	if (a[1] != ' ' && a[1] == a[2] && a[2] == a[3])
		return 1;
	if (a[4] != ' ' && a[4] == a[5] && a[5] == a[6])
		return 1;
	if (a[7] != ' ' && a[7] == a[8] && a[8] == a[9])
		return 1;
	if (a[1] != ' ' && a[1] == a[4] && a[4] == a[7])
		return 1;
	if (a[2] != ' ' && a[2] == a[5] && a[5] == a[8])
		return 1;
	if (a[3] != ' ' && a[3] == a[6] && a[6] == a[9])
		return 1;
	if (a[1] != ' ' && a[1] == a[5] && a[5] == a[9])
		return 1;
	if (a[3] != ' ' && a[3] == a[5] && a[5] == a[7])
		return 1;
	if (a[1] != ' ' && a[2] != ' ' && a[3] != ' ' && a[4] != ' ' &&
		a[5] != ' ' && a[6] != ' ' && a[7] != ' ' && a[8] != ' ' &&
		a[9] != ' ') // Draw Condition
		return 0;

	return -1;
}
int swap(int *player1, int *player2) {
	int z;
	z = *player1;
	*player1 = *player2;
	*player2 = z;
	return *player1;
}
