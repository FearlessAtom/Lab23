#include <stdio.h>
#include <ctype.h>
int main() {
	char input[100];
	int count = 0;
	printf("Enter a string: "); fgets(input, sizeof(input), stdin);
	for (int index = 0; input[index] != '\0'; index++) {
		char character = tolower(input[index]);
		if (isalpha(character) && character != 'e' && character != 'a' && character != 'i' && character != 'o' && character != 'u') { count = count + 1; }}
	printf("Amount of consonants : %d", count);
	return 0;}