/////////////////////////////////////////////////////////////////////
//
//	IDENTIFICATION DIVISION.
//	PROGRAM-ID. games.c.
//	AUTHOR. Taylor Rainwater.
//	INSTALLATION. alduin.
//	DATE-WRITTEN. 8.11.2015.
//	DESCRIPTION. Games program for Joshua.
//
/////////////////////////////////////////////////////////////////////

//************************ENVIRONMENTAL-VARIABLES************************//

#include "wopr.h"

char GAMES[15][50] = {
		{"1.\tFALKEN'S MAZE"},
		{"2.\tBLACK JACK"},
		{"3.\tGIN RUMMY"},
		{"4.\tHEARTS"},
		{"5.\tBRIDGE"},
		{"6.\tCHECKERS"},
		{"7.\tCHESS"},
		{"8.\tPOKER"},
		{"9.\tFIGHTER COMBAT"},
		{"10.\tGUERRILLA ENGAGEMENT"},
		{"11.\tDESERT WARFARE"},
		{"12.\tAIR-TO-GROUND ACTIONS"},
		{"13.\tTHEATERWIDE TACTICAL WARFARE"},
		{"14.\tTHEATERWIDE BIOTOXIC AND CHEMICAL WARFARE"},
		{"\n15.\tGLOBAL THERMONUCLEAR WAR\n"}
};

//**************************PROCEDURE-DIVISION**************************//.

/**
 * @brief Print Game List.
 * @details Prints the game list with
 *          numbering for user to
 *          select.
 */
void prtGmes(){
	int dly = 1000000;
	int i = 0;

	clear();
	slowPrint("PLEASE SELECT A NUMBER:", 2);
	for (; i < 14; i++){					// Print from array.
		expPrint(GAMES[i], 1);
	}
	usleep(dly);
	slowPrint(GAMES[14], 1);
}

/**
 * @brief Game List and Selection.
 * @details Takes play answer then prints
 *          the game list for user.
 */
void gameLst(){
	char ans[] = "";
	int swp = 0;

	prtGmes();
	scanf("%d", &swp);
	switch (swp){
		case 1:clear();
			   break;
		case 2:clear();
			   break;
		case 3:clear();
			   break;
		case 4:clear();
			   break;
		case 5:clear();
			   break;
		case 6:clear();
			   break;
		case 7:clear();
			   break;
		case 8:clear();
			   break;
		case 9:clear();
			   break;
		case 10:clear();
			    break;
		case 11:clear();
			    break;
		case 12:clear();
			    break;
		case 13:clear();
			    break;
		case 14:clear();
				break;
		case 15:clear();
				slowPrint("\nWOULDN'T YOU PREFER A NICE GAME OF CHESS?\n", 1);
				scanf("%s", ans);
				if (answYN(ans) == 0){

				} else if (answYN(ans) == 1){
					usleep(1000000);
					slowPrint("\nVERY WELL PROFESSOR FALKEN.", 1);
					usleep(1000000);
					breaker();
				} else {
					slowPrint("I DO NOT UNDERSTAND YOUR ANSWER.", 2);
					slowPrint(CONTERM, 1);
				}
				break;
		case 60:playTTT();
				break;
	}
}