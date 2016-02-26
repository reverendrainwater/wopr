/////////////////////////////////////////////////////////////////////
//
//	IDENTIFICATION DIVISION.
//	PROGRAM-ID. WOPR.
//	AUTHOR. Taylor R. Rainwater.
//	INSTALLATION. alduin.
//	DATE-WRITTEN. 30.10.15.
//	DESCRIPTION. WOPR Launch Code Breaker.
//
/////////////////////////////////////////////////////////////////////

//************************ENVIRONMENTAL-VARIABLES************************//

#include "wopr.h"

//**************************PROCEDURE-DIVISION**************************//

/**
 * @brief Greeting Function.
 * @details Greeting for WOPR.
 */
void greeting()
{	//****FUNCTION-VARIABLES****//
	char hello[] = "GREETINGS PROFESSOR FALKEN.";
	char play[] = "\nSHALL WE PLAY A GAME?";
	char swp0[] = " ";
	char swp1[] = " ";
	int dly = 2000;

	//****FUNCTION-PROCEDURES****//
	login();
	slowPrint(hello, 2);
	scanf("%s %s", swp0, swp1);
	if (helloTst(swp0) == 1){
		slowPrint("\nHOW RUDE PROFESSOR FALKEN.", 1);
		usleep(dly*1000);
		slowPrint("PLEASE FORMALLY SAY HELLO.\n", 1);
		slowPrint(CONTERM, 1);
	} else {
		slowPrint(play, 2);
		scanf("%s", swp1);
		if (answYN(swp1) == 0){
			gameLst();
		} else if (answYN(swp1) == 1){
			slowPrint("GOODBYE.\n", 1);
			slowPrint(CONTERM, 1);
		} else if (answYN(swp1) == 2){
			slowPrint("\nI DO NOT UNDERSTAND YOUR ANSWER.\n", 1);
			slowPrint(CONTERM, 1);
		}
	}
}

//*********MAIN********//
int main()
{	greeting();
	return 0;
}
