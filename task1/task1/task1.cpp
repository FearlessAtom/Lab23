#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int main() {
	srand(time(0));
	int number = 4;
	int** array = (int**)malloc(sizeof(int*) * number);
	for (int index = 0; index < number; index++) { array[index] = (int*)malloc(sizeof(int) * number); }
	int* pointer = &array[0][0];
	int max = INT_MIN;
	for (int index = 0; index < number; index++) {
		for (int j = 0; j < number; j++) {
			*(pointer + index * number + j) = rand() % 20 - 10;
			printf("%4d", *(pointer + index * number + j));
			if (*(pointer + index * number + j) > max) { max = *(pointer + index * number + j); }}
		printf("\n");}
	printf("Max = %d\n", max);
	for (int index = 0; index < number; index++) {
		for (int j = 0; j < number; j++) {
			*(pointer + index * number + j) = *(pointer + index * number + j) * max;
			printf("%4d", *(pointer + index * number + j));}
		printf("\n");}
	for (int index = 0; index < number; index++) {
		for (int j = 0; j < number; j++) {
			printf("%11d", (pointer + index * number + j));}
		printf("\n");}
	for (int index = 0; index < number; index++) { free(pointer + index); }
	return 0;}