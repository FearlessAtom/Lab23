#include <stdio.h>
void grade(char character){
    switch(character){
    case '2' : printf("unsatisfactory");break;
    case '3' : printf("satisfactory");break;
    case '4' : printf("good");break;
    case '5': printf("excellent");break;
    default : printf("Please, enter a valie grade!");}}
int main(){
    printf("Enter a grade : ");char character;scanf("%c", &character);
    grade(character);
    return 0;}