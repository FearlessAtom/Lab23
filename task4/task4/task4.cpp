#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
int beeptime = 500;
int sleeptime = 500;
void dot() { Sleep(sleeptime); Beep(500, beeptime); printf(". "); }
void underscore() { Sleep(sleeptime); Beep(1000, beeptime); printf("_ "); }
int main() {
	bool value;;
	char string[100];
	do {value = false;
		printf("Enter a string : "); fgets(string, sizeof(string), stdin);
		if (string[strlen(string) - 1] == '\n') { string[strlen(string) - 1] = '\0'; }
		int count = 0;
		char* pointer = string;
		while (*pointer != '\0') {
			*pointer = tolower(*pointer);
			if (!isdigit(*pointer) || !isalpha(*pointer)) { pointer = pointer + 1; }
			else { value = true; }}} while (value);
	for (int index = 0; index < strlen(string); index++) {
		switch (string[index]) {
		case ' ': {Sleep(500); printf("\n"); Sleep(500); break; }
		case 'a': {printf("\nA = "); dot(); underscore(); break; }
		case 'b': {printf("\nB = "); underscore(); dot(); dot(); dot(); break; }
		case 'c': {printf("\nC = "); underscore(); dot(); underscore(); dot(); break; }
		case 'd': {printf("\nD = "); underscore(); dot(); dot(); break; }
		case 'e': {printf("\nE = "); dot(); break; }
		case 'f': {printf("\nF = "); dot(); dot(); underscore(); dot(); break; }
		case 'g': {printf("\nG = "); underscore(); underscore(); dot(); break; }
		case 'h': {printf("\nH = "); dot(); dot(); dot(); dot(); break; }
		case 'i': {printf("\nI = "); dot(); dot(); break; }
		case 'j': {printf("\nJ = "); dot(); underscore(); underscore(); underscore(); break; }
		case 'k': {printf("\nK = "); underscore(); dot(); underscore(); break; }
		case 'l': {printf("\nL = "); dot(); underscore(); dot(); dot(); break; }
		case 'm': {printf("\nM = "); underscore(); underscore(); break; }
		case 'n': {printf("\nN = "); underscore(); dot(); break; }
		case 'o': {printf("\nO = "); underscore(); underscore(); underscore(); break; }
		case 'p': {printf("\nP = "); dot(); underscore(); underscore(); dot(); break; }
		case 'q': {printf("\nQ = "); underscore(); underscore(); dot(); underscore(); break; }
		case 'r': {printf("\nR = "); dot(); underscore(); dot(); break; }
		case 's': {printf("\nS = "); dot(); dot(); dot(); break; }
		case 't': {printf("\nT = "); underscore(); break; }
		case 'u': {printf("\nU = "); dot(); dot(); underscore(); break; }
		case 'v': {printf("\nV = "); dot(); dot(); dot(); underscore(); break; }
		case 'w': {printf("\nW = "); dot(); underscore(); underscore(); break; }
		case 'x': {printf("\nX = "); underscore(); dot(); dot(); underscore(); break; }
		case 'y': {printf("\nY = "); underscore(); dot(); underscore(); underscore(); break; }
		case 'z': {printf("\nZ = "); underscore(); underscore(); dot(); dot(); break; }
		case '1': {printf("\n1 = "); dot(); underscore(); underscore(); underscore(); underscore(); break; }
		case '2': {printf("\n2 = "); dot(); dot(); underscore(); underscore(); underscore(); break; }
		case '3': {printf("\n3 = "); dot(); dot(); dot(); underscore(); underscore(); break; }
		case '4': {printf("\n4 = "); dot(); dot(); dot(); dot(); underscore(); break; }
		case '5': {printf("\n5 = "); dot(); dot(); dot(); dot(); dot(); break; }
		case '6': {printf("\n6 = "); underscore(); dot(); dot(); dot(); dot(); break; }
		case '7': {printf("\n7 = "); underscore(); underscore(); dot(); dot(); dot(); break; }
		case '8': {printf("\n8 = "); underscore(); underscore(); underscore(); dot(); dot(); break; }
		case '9': {printf("\n9 = "); underscore(); underscore(); underscore(); underscore(); dot(); break; }
		case '0': {printf("\n0 = "); underscore(); underscore(); underscore(); underscore(); underscore(); break; }}}
	return 0;}