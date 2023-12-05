#include <stdio.h>
const char* grade(char character);
int main(){
	printf("Enter a string : "); char character; scanf_s("%c", &character);
	const char* result = grade(character);
	if (!result) { printf("Please, enter a valie grade!"); }
	else { printf("%s", result); }
	return 0;}
const char* grade(char character) {
	switch (character) {
	case '2': return "unsatisfactory";
	case '3': return "satisfactory";
	case '4': return "good";
	case '5': return "excellent";
	default: return NULL;}}