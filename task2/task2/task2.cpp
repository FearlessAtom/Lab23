#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int main() {
	srand(time(0));
	int number = 5;
	int** array = (int**)malloc(sizeof(int*) * number);
	for (int index = 0; index < number; index++) {
		array[index] = (int*)malloc(sizeof(int) * number);}
	int* pointer = &array[0][0];
	for (int index = 0; index < number; index++) {
		for (int j = 0; j < number; j++) {
			*(pointer + index * number + j) = rand() % 20 - 10;
			printf("%4d", *(pointer + index * number + j));}
		printf("\n");}
	int min = *pointer;
	int minindex, minj;
	for (int index = 0; index < number; index++) {
		for (int j = 0; j < number; j++) {
			if (*(pointer + index * number + j) < min) {
				min = *(pointer + index * number + j);
				minindex = index;
				minj = j;}}}
	printf("Min = %d\n", min);
	for (int index = minindex; index < number - 1; index++) {
		for (int j = 0; j < number; j++) {
			*(pointer + index * number + j) = *(pointer + (index + 1) * number + j);}}
	for (int j = minj; j < number - 1; j++) {
		for (int index = 0; index < number; index++) {
			*(pointer + index * number + j) = *(pointer + index * number + (j + 1));}}
	for (int index = 0; index < number - 1; index++) {
		for (int j = 0; j < number - 1; j++) {
			printf("%4d", *(pointer + index * number + j));}
		printf("\n");}
	for (int index = 0; index < number; index++) { free(pointer + index); }
	return 0;}