/////////////////////////////////////////////////////////////////////
//
//    IDENTIFICATION DIVISION.
//    PROGRAM-ID. actions.c.
//    AUTHOR. Taylor Rainwater.
//    INSTALLATION. alduin.
//    DATE-WRITTEN. 8.11.2015.
//    DESCRIPTION. WOPR speech program using Festival TTS.
//
/////////////////////////////////////////////////////////////////////

//************************ENVIRONMENTAL-VARIABLES************************//

#include "wopr.h"

//**************************PROCEDURE-DIVISION**************************//.

/**
 * @brief Slow Printer.
 * @details Prints input from user or
 *          from default program
 *          variables.
 *
 * @param n string in.
 * @param nl number of newlines.
 */
void slowPrint(char n[], int nl){
	//****FUNCTION-VARIABLES****//

	int i = 0;
	int dly = 70;

	//****FUNCTION-PROCEDURES****//

	for (; i < strlen(n); i++){
		printf("%c", n[i]);
		fflush(stdout);
		usleep(dly*1000);
	}
	while (nl > 0){
		printf("\n");
		nl--;
	}
}

/**
 * @brief Express Printer.
 * @details Prints a string from
 *          the user of program
 *          default variables one
 *          character at a time.
 *
 * @param n string in.
 * @param nl number of newlines.
 */
void expPrint(char n[], int nl){
	//****FUNCTION-VARIABLES****//

	int i = 0;
	int dly = 15;

	//****FUNCTION-PROCEDURES****//

	for (; i < strlen(n); i++){
		printf("%c", n[i]);
		fflush(stdout);
		usleep(dly*1000);

	}
	while (nl > 0){
		printf("\n");
		nl--;
	}
}

/**
 * @brief Governed Print.
 * @details Printing function which has
 *          the user specifiy (govern)
 *          the delay.
 *
 * @param n string in.
 * @param nl number of newlines.
 * @param dly delay govern.
 */
void govPrint(char n[], int nl, int dly){
	//****FUNCTION-VARIABLES****//

	int i = 0;

	//****FUNCTION-PROCEDURES****//

	for (; i < strlen(n); i++){
		printf("%c", n[i]);
		fflush(stdout);
		usleep(dly*1000);
	}
	while (nl > 0){
		printf("\n");
		nl--;
	}
}

/**
 * @brief Clear Screen Function.
 * @details Clears the terminal screen
 *          for the neat retro feel.
 */
void clear(){
	system("clear");
}

/**
 * @brief Yes-No Answer Function.
 * @details Takes a string from user
 *          and returns if it is yes,
 *          no, or neither.
 *
 * @param n string in.
 * @return 0 = yes, 1 = no, 2 = neither.
 */
int answYN(char n[]){
	char chk0[] = "yes";
	char chk1[] = "Yes";
	char chk2[] = "no";
	char chk3[] = "No";

	if (strcmp(chk0, n) == 0 || strcmp(chk1, n) == 0){
		return 0;
	} else if (strcmp(chk2, n) == 0 || strcmp(chk3, n) == 0){
		return 1;
	} else {
		return 2;
	}
}

/**
 * @brief Hello Test.
 * @details Test a string for if the
 *          first five characters of
 *          a string is "hello".
 *
 * @param n string in.
 * @return 0 = yes, 1 = nope.
 */
int helloTst(char n[]){
	char swp[6] = "";
	char chk0[] = "hello";
	char chk1[] = "Hello";
	int out = 1;

	strncpy(swp, n, 5);
	swp[6] = '\0';
	if (strcmp(chk0, swp) == 0 || strcmp(chk1, swp) == 0){
		out = 0;
	}
	return out;
}

/**
 * @brief Check Variable
 * @details Checks if the variable and
 *          the code value are the same.
 *
 * @param n code value in.
 * @param v variable in.
 *
 * @return 0 = y, 1 = no.
 */
int chkVar(char n, char v){
	if (n == v){
		return 0;
	} else {
		return 1;
	}
}

/**
 * @brief Login Function.
 * @details Prints the login screen
 *          then prompts user for
 *          password.
 */
void login(){
	//****FUNCTION-VARIABLES****//

	char usr[25] = " ";
	char falken[10] = "Joshua";

	//****FUNCTION-PROCEDURES****//

	while(strcmp(falken, usr) != 0){
		clear();
		slowPrint("LOGON: ", 0);
		scanf("%s", usr);

		if (strcmp(falken, usr) == 0){
			clear();
		}
	}
}

/**
 * @brief Say.
 * @details Joshua says the string
 *          input.
 * 
 * @param n string in.
 * @return int.
 */
int say(char *n)
{   char swp[64];
    int out;

    sprintf(swp, "echo \"%s\" | festival --tts", n);
    out = system(swp);

    return out;
}

/**
 * @brief Weather Say.
 * @details Joshua gives the Boone 
 *          weather.
 */
void weather()
{
	system("weather --imperial 28607 | festival --tts");
}
