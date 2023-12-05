#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
void token(char words[100][100], char* string);
void palindrome(char words[100][100], char palindromearray[100][100]);
void withoutrepeatedwords(char words[100][100], char countarray[100][100]);
void countinstances(char words[100][100], char countarray[100][100], char countint[100]);
char* wordthatoccursthemost(char countarray[100][100], char countint[100]);
void alphabeticalorder(char words[100][100]);
int main(){
	char string[100], words[100][100], palindromearray[100][100], countarray[100][100], countint[100];
	printf(">"); fgets(string, sizeof(string), stdin);
	if (string[strlen(string) - 1] == '\n') { string[strlen(string) - 1] = '\0'; }
	token(words, string);
	palindrome(words, palindromearray);
	if (strlen(palindromearray[0]) > 0) {
		printf("Palidromes : \n");
		for (int index = 0; strlen(palindromearray[index]) > 0; index++) { printf("%s ", palindromearray[index]); }}
	else { printf("The string does not have palidromes!"); }
	withoutrepeatedwords(words, countarray);
	countinstances(words, countarray, countint);
	printf("\nWords and number of their instances : \n");
	for (int index = 0; strlen(countarray[index]) > 0; index++) { printf("%s[%d] ", countarray[index], countint[index]); }
	printf("\nWord that occurs the most : ");
	printf("%s", wordthatoccursthemost(countarray, countint));
	printf("\nArray without reptead words : \n");
	for (int index = 0; strlen(countarray[index]) > 0; index++) { printf("%s ", countarray[index]); }
	alphabeticalorder(words);
	printf("\nArray sorted in alphabetical order : \n");
	for (int index = 0; strlen(words[index]) > 0; index++) { printf("%s ", words[index]); }
	return 0;}
void token(char words[100][100], char* string) {
	char* pointer = strtok(string, " ");
	int index = 0;
	while (pointer != NULL) {
		strcpy(words[index], pointer);
		pointer = strtok(NULL, " ");
		index++;}
	words[index][0] == '\0';
}
void palindrome(char words[100][100], char palindromearray[100][100]) {
	int count = 0;
	for (int index = 0; strlen(words[index]) > 0; index++) {
		if (strcmp(words[index], _strrev(_strdup(words[index]))) == 0 && strlen(words[index]) != 1) {
			strcpy(palindromearray[count], words[index]);
			count++;}}}
void withoutrepeatedwords(char words[100][100], char countarray[100][100]) {
	int count = 0;
	for (int index = 0; strlen(words[index]) > 0; index++) {
		bool found = false;
		for (int j = 0; strlen(countarray[j]) > 0; j++) {
			if (strcmp(words[index], countarray[j]) == 0) {
				found = true;
				break;}}
		if (!found) {
			strcpy(countarray[count], words[index]);
			count++;}}}
void countinstances(char words[100][100], char countarray[100][100], char countint[100]) {
	for (int index = 0; strlen(countarray[index]) > 0; index++) { countint[index] = 0; }
	for (int index = 0; strlen(countarray[index]) > 0; index++) {
		for (int j = 0; strlen(words[j]) > 0; j++) {
			if (strcmp(countarray[index], words[j]) == 0) {
				countint[index] = countint[index] + 1;}}}}
char* wordthatoccursthemost(char countarray[100][100], char countint[100]) {
	int max = INT_MIN;
	int maxindex;
	for (int index = 0; strlen(countarray[index]) > 0; index++) {
		if (countint[index] > max) {
			max = countint[index];
			maxindex = index;}}
	return countarray[maxindex];}
void alphabeticalorder(char words[100][100]) {
	int length = 0;
	while (strlen(words[length]) > 0) { length++; }
	for (int index = 0; index < length - 1; index++) {
		for (int j = 0; j < length - index - 1; j++) {
			if (strcmp(words[j], words[j + 1]) > 0) {
				char temp[100];
				strcpy(temp, words[j]);
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], temp);}}}}