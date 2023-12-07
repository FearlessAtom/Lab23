#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* grades(char character);
int main() {
	printf("Enter a grade : "); char character; scanf_s(" %c", &character);
	char* result = grades(character);
	if (result == NULL) { printf("Please, enter a valid grade!"); }
	else { printf("%s", result); free(result); }
	return 0;
}
char* grades(char character) {
	int index = character - '2';
	if (index >= 0 && index < 4) {
		char grades[4][100] = { "unsatisfactory", "satisfactory", "good", "excellent" };
		char* result = (char*)malloc(sizeof(char) * 100);
		strcpy(result, grades[index]);
		if (strlen(result) < 1) { free(result); return NULL; }
		return result;
	}
	else { return NULL; }
}
