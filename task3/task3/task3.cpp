#include <stdio.h>
#include <ctype.h>
#include <string.h>
int vowel(char c) {
	c = tolower(c);
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');}
int consonant(char c) {
	c = tolower(c);
	return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');}
int main() {
	char* something;
	char string[1000];
	printf("Enter a string: ");
	fgets(string, sizeof(string), stdin);
	char secondstring[1000];
	int index, j;
	for (index = 0, j = 0; string[index] != '\0'; index++) { if (!isdigit(string[index])) { secondstring[j++] = string[index]; } }
	secondstring[j] = '\0';
	char* pointer = strtok_s(string, " ",&something);
	int count = 0, countconsonant;
	printf("| Words with an odd number of consonants |\n");
	char* charpointer = pointer;
	while (pointer != 0) {
		if (vowel(*pointer)) { count = count + 1; }
		countconsonant = 0;
		for (int index = 0; index < strlen(pointer); index++) { if (consonant(*charpointer + index)) { countconsonant = countconsonant + 1; } }
		if (countconsonant % 2 == 1) { printf("%s ", pointer); }
		pointer = strtok_s(NULL, " ",&something);}
	printf("\n| Amount of words starting with a vowel  |\n%20d", count);
	printf("\n|         String without numbers         |\n%s", secondstring);
	return 0;}