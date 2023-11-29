#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int error() {printf("Invalid user input!");exit(1);}
int main() {
	printf(">"); char string[100]; fgets(string, sizeof(string), stdin);
	char stuff[20][1000];
	int index = 0, result = 0;
	char* something;
	char* pointer = strtok_s(string, " ",&something);
	while (pointer != NULL) {
		strcpy_s(stuff[index], pointer);
		pointer = strtok_s(NULL, " ",&something);
		index++;}
	bool addition = true;
	for (int j = 0; j < index; j++) {
		if (j % 2 == 0 && !isdigit(stuff[j][0])) { error(); }
		else if (j % 2 == 1 && (strcmp("+", stuff[j]) && strcmp("-", stuff[j]))) { error(); }}
	for (int j = 0; j < index; j = j + 2) {
		if (j % 2 == 0) {
			if (strcmp("+", stuff[j - 1]) == 0) { addition = true; }
			else if (strcmp("-", stuff[j - 1]) == 0) { addition = false; }}
		else { printf("Invalid user input!"); return 1; };
		if (isdigit(stuff[j][0])) {
			if (addition) { result = result + atoi(stuff[j]); }
			else { result = result - atoi(stuff[j]); }}}
	printf("Result = %d", result);
	return 0;}