/////////////////////////////////////////////////////////////////////
//
//	IDENTIFICATION DIVISION.
//	PROGRAM-ID. nuclear.c.
//	AUTHOR. Taylor Rainwater.
//	INSTALLATION. alduin.
//	DATE-WRITTEN. 8.11.2015.
//	DESCRIPTION. Nuclear War is a serious matter.
//
/////////////////////////////////////////////////////////////////////

//************************ENVIRONMENTAL-VARIABLES************************//

#include "wopr.h"

//**************************PROCEDURE-DIVISION**************************//.

/**
 * @brief The Big Question.
 * @details Checks the answer of from
 *          the user and returns what
 *          Joshua should do.
 *
 * @param n second word, not used.
 * @param v first word, switch.
 * @return 0 = manual, 1 = auto.
 */
int bigAsk(char n[], char v[]){
	char chk0[] = "Manual";
	char chk1[] = "manual";
	char chk2[] = "Auto";
	char chk3[] = "auto";
	int out = 0;

	if (strcmp(chk0, n) == 0 || strcmp(chk1, n) == 0){
		out = 0;
	} else if (strcmp(chk2, n) == 0 || strcmp(chk3, n) == 0){
		out = 1;
	} else {
		slowPrint("I DO NOT UNDERSTAND YOUR ANSWER.", 2);
		slowPrint(CONTERM, 1);
	}
	return out;
}

void launch(char n[]){
	char ans[] = "";
	int dly = 2000000;

	clear();
	usleep(dly);
	slowPrint("LAUNCH CODE INTEGRITY CONFIRMED: ", 0);
	usleep(dly);
	slowPrint(n, 1);
	printf("\n");
	usleep(dly / 2);
	slowPrint("WOULD YOU LIKE TO INITIATE LAUNCH?\n", 1);
	scanf("%s", ans);
	if (answYN(ans) == 0){
		fflush(stdout);
		usleep(dly);
		slowPrint("\nI TRUST YOUR JUDGEMENT PROFESSOR FALKEN.", 1);
	} else if (answYN(ans) == 1){
		fflush(stdout);
		usleep(dly);
		slowPrint("\nI TRUST YOUR JUDGEMENT PROFESSOR FALKEN.", 1);
	} else {
		fflush(stdout);
		slowPrint("\nNUCLEAR WAR IS A SERIOUS MATTER.\n", 1);
		usleep(dly);
		slowPrint(CONTERM, 1);
	}
}

/**
 * @brief Launch Code Breaker.
 * @details This function processes the
 *          user provided launch code
 *          and breaks it digit by digit
 *          while also printing.
 */
void breaker(){
	char MANUAL[] = "MANUAL ENTRY OR AUTO GENERATE LAUNCH CODE?";
	char code[10] = "";
	char var[36] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char swp[] = " ";
	char ans0[] = " ";
	char ans1[] = " ";
	char predct[] = " ";
	int check = 0;
	int i = 0;
	int j = 10;
	int N = 36;
	srand(time(NULL));

	clear();
	slowPrint(MANUAL, 2);
	scanf("%s %s", ans0, ans1);
	if (bigAsk(ans0, ans1) == 0){
		slowPrint("\nENTER LAUNCH CODE: ", 0);
		scanf("%s", code);
		printf("\n\n");
		usleep(1000000);
		slowPrint("RUNNING SHI.64 INTEGRITY CHECK.", 2);
		usleep(1000000);
	} else if (bigAsk(ans0, ans1) == 1){
		slowPrint("\nCOMPUTER PERMISSIONS ELEVATED: D2.", 2);
		usleep(1000000);
		slowPrint("GENERATING LAUNCH CODE", 0);
		govPrint("............", 0, 1000);
		printf("\n\n");
		slowPrint("CODE GENERATED.", 2);
		usleep(1000000);
		slowPrint("RUNNING SHI.64 INTEGRITY CHECK.", 2);
		usleep(1000000);
		sprintf(code, "%c%c%c%c%c%c%c%c%c%c",
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)],
		var[rand() / (RAND_MAX / N + 1)]);
	}
	printf("\n");
	while (check == 0){
		j = 10;
		sprintf(swp, "%c%c%c%c%c%c%c%c%c%c",
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)],
			var[rand() / (RAND_MAX / N + 1)]);
		if (chkVar(code[i], swp[i]) == 0){
			predct[i] = swp[i];
			printf("\a");
			i++;
		}
		for (; j >= i; j--){
			predct[j] = swp[j];
		}
		expPrint(predct, 1);
		if (strcmp(code, predct) == 0){
			printf("\a");
			usleep(1000000);
			printf("\a");
			usleep(1000000);
			printf("\a");
			usleep(1000000);
			check = 1;
		}
	}
	launch(predct);
}