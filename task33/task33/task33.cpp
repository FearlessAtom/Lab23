#include <stdio.h>
#include <string.h>
int grades(char result[100]);
int  main() {
	printf("Enter a grade : "); char result[100]; scanf_s("%s", result,sizeof(result));
	if (!grades(result)) { printf("Please, enter a valid grade!"); }
	else { printf("%d", grades(result)); }
	return 0;}
int grades(char result[100]) {
	char grades[4][100] = { "unsatisfactory","satisfactory","good","excellent" };
	for (int index = 0; strlen(grades[index]) > 0; index++) {
		if (strcmp(result, grades[index]) == 0) {
			return index + 2;}}
	return 0;}