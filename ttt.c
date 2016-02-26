/////////////////////////////////////////////////////////////////////
//
//	IDENTIFICATION DIVISION.
//	PROGRAM-ID. ttt.c.
//	AUTHOR. Taylor Rainwater.
//	INSTALLATION. alduin.
//	DATE-WRITTEN. 10.11.2015.
//	DESCRIPTION. Tic-Tac-Toe Program.
//
/////////////////////////////////////////////////////////////////////

//************************ENVIRONMENTAL-VARIABLES************************//

#include "wopr.h"

//**************************PROCEDURE-DIVISION**************************//.

void printBoard(Board board) {
	char l0[] = " ";
	char l1[] = " ";
	char l2[] = " ";
	char l3[] = " ";
	char l4[] = " ";

	sprintf(l0, " %c | %c | %c", board[0][0], board[0][1], board[0][2]);
	sprintf(l1, "---|---|---");
	sprintf(l2, " %c | %c | %c", board[1][0], board[1][1], board[1][2]);
	sprintf(l3, "---|---|---");
	sprintf(l4, " %c | %c | %c", board[2][0], board[2][1], board[2][2]);

	printf("\n\n");
	expPrint(l0, 1);
	expPrint(l1, 1);
	expPrint(l2, 1);
	expPrint(l3, 1);
	expPrint(l4, 1);
}

int hasWinner(Board board) {
	int line = 0;
	if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
		(board[0][2]==board[1][1] && board[0][2]==board[2][0])) { return 1; }
	for(; line <=2; line++) {
		if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||
			(board[0][line]==board[1][line] && board[0][line]==board[2][line])) {
				return 1;
			}
	}
	return 0;
}

/**
 * @brief Reset Board.
 * @details A function to reset the 
 *          board to the default 
 *          values.
 * 
 * @param n Board in. 
 */
void resetBrd(Board n){
	int i = 0;
	int j = 0;
	int c = 1;

	for (; i < 3; i++){
		for (; j < 3; j++){
			n[i][j] = c + '0';
			c++;
		}
		c++;
	}
}

/**
 * @brief Two Player Tic-Tac-Toe.
 * @details This is the function
 *          for twon human players.
 */
void twoPlyr(){
	char swp[] = " ";
	int winner = 0;
	int choice = 0;
	int row = 0;
	int column = 0;
	int c = 0; 
	int i;

	Board board = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};

	while (c == 0){
		resetBrd(board);
		for (i = 0; i < 9 && !winner; i++) {
			int player = i%2 + 1;

			clear();
			printBoard(board);
			do { sprintf(swp, "%c: ", (player==1)?'X':'O');
				 slowPrint(swp, 0);
				 scanf("%d", &choice);

				 row = --choice/3;
				 column = choice%3;
			} while(choice < 0 || choice > 9 || board [row][column] > '9');

			board[row][column] = (player == 1) ? 'X' : 'O';
			if (hasWinner(board)){ winner = player; }
		}
		
		printBoard(board);
		if(!winner) {
			slowPrint("THE GAME IS A DRAW.", 1);
			printf("\a");
			usleep(2000000);
			c = 0;
		} else {
			sprintf(swp, "Player %d has won\n", winner);
			slowPrint(swp, 1);
			usleep(2000000);
			c = 1;
			clear();
		}
	}
}

int playTTT() {
	char ans[] = " ";
	char human[] = "human";
	char comp[] = "computer";
	int check = 0;

	while (check == 0){
		clear();
		slowPrint("NUMBER OF PLAYERS?\n", 1);
		scanf("%s", ans);
		if (strcmp("zero", ans) == 0){

		} else if (strcmp("one", ans) == 0){
			slowPrint("\nPLAYER X: ", 0);
			slowPrint(human, 1);
			slowPrint("PLAYER O: ", 0);
			slowPrint(comp, 1);
			usleep(2000000);
			check = 1;
		} else if (strcmp("two", ans) == 0){
			slowPrint("\nPLAYER X: ", 0);
			slowPrint(human, 1);
			slowPrint("PLAYER O: ", 0);
			slowPrint(human, 1);
			usleep(2000000);
			twoPlyr();
			check = 1;
		} else {
			slowPrint("INVALID NUMBER OF PLAYERS\n", 1);
		}
	}
	return 0;
}
