#include <stdio.h>
#include <string.h>
void grades(char result[100]) {
	char grades[4][100] = { "unsatisfactory","satisfactory","good","excellent" };
	bool found = false;
	for (int index = 0; strlen(grades[index]) > 0; index++) {
		if (strcmp(result, grades[index]) == 0) {
			printf("%d", index + 2);
			found = true;}}
	if(!found)printf("Please, enter a valid grade!");}
int	main() {
	printf("Enter a grade : "); char result[100]; scanf_s("%s", result,sizeof(result));
	grades(result);
	return 0;}