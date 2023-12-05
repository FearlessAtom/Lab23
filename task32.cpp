#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* grades(char character);
int main() {
    printf("Enter a grade : ");char character;scanf(" %c", &character);
    char* result = grades(character);
    if (result == NULL) {printf("Please, enter a valid grade!");}
    else{printf("%s", result);free(result);}
    return 0;}
char* grades(char character) {
    character = character - '2';
    char grades[4][100] = {"unsatisfactory", "satisfactory", "good", "excellent"};
    char* result = (char*)malloc(sizeof(char) * 100);
    strcpy(result, grades[character]);
    return result;}
