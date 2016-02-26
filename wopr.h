/////////////////////////////////////////////////////////////////////
//
//	IDENTIFICATION DIVISION.
//	PROGRAM-ID. wopr.h.
//	AUTHOR. Taylor Rainwater.
//	INSTALLATION. alduin.
//	DATE-WRITTEN. 30.10.2015.
//	DESCRIPTION. WOPR Header File.
//
/////////////////////////////////////////////////////////////////////

//************************ENVIRONMENTAL-VARIABLES************************//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define ROWS 3
#define COLS 3
#define CONTERM "-++- CONNECTION TEMINATED -++-"

typedef char Board[ROWS][COLS];

//********PROTOTYPES********//

	//WOPR//

	void greeting();

	//TTT//
	
	void printBoard(Board);
	void resetBrd(Board);
	void twoPlyr();
	int hasWinner(Board);
	int playTTT();

	//ACTIONS//
	void slowPrint(char[], int);
	void expPrint(char[], int);
	void govPrint(char[], int, int);
	void launch(char[]);
	void clear();
	void login();
	void breaker();
	void prtGmes();
	void gameLst();
	void weather();
	int answYN(char[]);
	int helloTst(char[]);
	int chkVar(char, char);
	int bigAsk(char[], char[]);
	int say(char*);
