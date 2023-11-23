#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(0));
	int count = 0;
	int number = 5;
	int* arrayone = (int*)malloc(sizeof(int) * number);
	int* pointerone = arrayone;
	printf("First array : \n");
	for (int index = 0; index < number; index++) {
		*(pointerone + index) = rand() % 5;
		printf("%2d", *(pointerone + index));}
	int* arraytwo = (int*)malloc(sizeof(int) * number);
	int* pointertwo = arraytwo;
	printf("\nSecond array : \n");
	for (int index = 0; index < number; index++) {
		*(pointertwo + index) = rand() % 5;
		printf("%2d", *(pointertwo + index));}
	printf("\n");
	int* both = (int*)malloc(sizeof(int) * number * 2);
	int* pointerboth = both;
	for (int index = 0; index < number; index++) { *(pointerboth + index) = *(pointerone + index); }
	for (int index = 0; index < number; index++) { *(pointerboth + index + number) = *(pointertwo + index); }
	printf("Merged array : \n");
	for (int index = 0; index < number * 2; index++) { printf("%2d", *(pointerboth + index)); }
	int* common = (int*)malloc(sizeof(int) * number);
	int* pointercommon = common;
	printf("\nCommon elements : \n");
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (*(pointerone + i) == *(pointertwo + j)) {
				int found = 0;
				for (int k = 0; k < count; k++) {
					if (*(pointerone + i) == *(pointercommon + k)) {
						found = 1;
						break;}}
				if (!found) {
					*(pointercommon + count) = *(pointerone + i);
					count++;}}}}
	for (int index = 0; index < count; index++) { printf("%2d", *(pointercommon + index)); }
	free(arrayone);
	free(arraytwo);
	free(both);
	free(common);
	return 0;}