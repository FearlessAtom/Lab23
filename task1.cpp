    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int* reversed(char (*words)[100], char *string) {
        char *pointer = strtok(string, " ");
        int index = 0;
        while (pointer != NULL) {
            strcpy(words[index], pointer);
            pointer = strtok(NULL, " ");
            index++;}
        for(int j = 0;j < index;j++){if(strlen(words[j]) % 2 == 0){*strrev(words[j]);}}
        for (int index = 0; strlen(words[index]) > 0; index++){printf("%s ", words[index]);}
        return 0;}
    int main() {
        char string[100], words[100][100];
        printf("Enter a string: ");fgets(string, sizeof(string), stdin);
        if (string[strlen(string) - 1] == '\n') {string[strlen(string) - 1] = '\0';}
        reversed(words, string);
        return 0;}