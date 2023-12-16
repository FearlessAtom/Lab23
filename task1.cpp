#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Goods {char name[20];int cost;int storageperiod;char variety[20];char releasedate[20];char expirationdate[20];};
int datetonumber(const char *date) {
    int day, month, year;
    sscanf(date, "%d.%d.%d", &day, &month, &year);
    return year * 10000 + month * 100 + day;}
void* swapint(int *a, int *b){int temp = *a;*a = *b;*b = temp;}
void* swapchar(char *a, char *b){char temp[100];strcpy(temp, a);strcpy(a,b);strcpy(b,temp);}
void swapall(struct Goods goods[], int j){
        swapchar(goods[j].name, goods[j + 1].name);
        swapint(&goods[j].cost, &goods[j + 1].cost);
        swapint(&goods[j].storageperiod, &goods[j + 1].storageperiod);
        swapchar(goods[j].variety, goods[j + 1]. variety);
        swapchar(goods[j].releasedate, goods[j + 1]. releasedate);
        swapchar(goods[j].expirationdate, goods[j + 1]. expirationdate);}
char datecheck(char date[]){
    bool error;
    char day[3] = "", month[3] = "";
    error = false;
    for(int index = 0, j = 3; index < 2;index++, j++){month[index] = date[j];}
    if(month[strlen(month) - 1] == '\n'){month[strlen(month) - 1] = '\0';}
    int monthnumber = atoi(month);
    if(!(monthnumber >= 1 && monthnumber <= 12)){error = true;}
    for(int index = 0;index < 2;index++){day[index] = date[index];}
    if(day[strlen(day) - 1] == '\n'){day[strlen(day) - 1] = '\0';}
    int daynumber = atoi(day);
    if(!(daynumber >= 1 && daynumber <= 31)){error = true;}
    if(date[2] != '.' || date[5] != '.' || strlen(date) != 10){error = true;}
    if(error){return 1;}
    return 0;}
void tolowercase(char* string){
    for(int index = 0;index < string[index] != '\0';index++){
        string[index] = tolower(string[index]);}}
void output(struct Goods goods[], int length) {for (int index = 0; index < length; index++) {printf("%d. Name : %15s, Cost : %2d$ , Storage period : %d, Variety : %s, Released date : %s, Expiration date : %s\n",index + 1, goods[index].name, goods[index].cost, goods[index].storageperiod,goods[index].variety, goods[index].releasedate, goods[index].expirationdate);}}
void bubbleSort(struct Goods goods[], int length, char criteria[], int order) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            int compare = 0;
            if (strcmp(criteria, "cost") == 0) {compare = goods[j].cost - goods[j + 1].cost;}
            else if (strcmp(criteria, "storage period") == 0) {compare = goods[j].storageperiod - goods[j + 1].storageperiod;}
            else if (strcmp(criteria, "release date") == 0) {compare = datetonumber(goods[j].releasedate) - datetonumber(goods[j + 1].releasedate);}
            else if (strcmp(criteria, "expiration date") == 0) {compare = datetonumber(goods[j].expirationdate) - datetonumber(goods[j + 1].expirationdate);}
            if ((compare > 0 && order) || (compare < 0 && !order)) {swapall(goods, j);}}}}
int main(){
    int length = 0;
    char input[100];
    struct Goods *goods = NULL;
    do {
        printf(">");fgets(input, sizeof(input), stdin);input[strcspn(input, "\n")] = '\0';tolowercase(input);
        if (strcmp(input, "output") == 0) {
            if (length < 1) {printf("There is no data yet!\n");}
            else {output(goods, length);}}
        else if (strcmp(input, "cls") == 0) {system("cls");}
        else if (strcmp(input, "find") == 0) {
            if (length < 1) {printf("There is no data yet!\n");}
            else {
                printf("What would you like to search? : ");
                char choice[20];
                fgets(choice, sizeof(choice), stdin);
                choice[strlen(choice) - 1] = '\0';
                tolowercase(choice);
                if (strcmp(choice, "name") == 0) {
                    printf("Enter the name : ");
                    char name[20];
                    fgets(name, sizeof(name), stdin);
                    name[strlen(name) - 1] = '\0';
                    bool found = false;
                    for (int index = 0; index < length; index++) {
                        if (strcmp(name, goods[index].name) == 0) {
                            printf("%d. Name : %15s, Cost : %2d$ , Storage period : %d, Variety : %s, Released date : %s, Expiration date : %s\n",index + 1, goods[index].name, goods[index].cost, goods[index].storageperiod,goods[index].variety, goods[index].releasedate, goods[index].expirationdate);
                            found = true;}}
                    if (!found) {printf("There are no items with such name!\n");}}
                else if (strcmp(choice, "cost") == 0) {
                    printf("Enter the cost : ");
                    int cost;scanf("%d", &cost);getchar();
                    bool found = false;
                    for (int index = 0; index < length; index++) {
                        if (cost == goods[index].cost) {
                            printf("%d. Name : %15s, Cost : %2d$ , Storage period : %d, Variety : %s, Released date : %s, Expiration date : %s\n",index + 1, goods[index].name, goods[index].cost, goods[index].storageperiod,goods[index].variety, goods[index].releasedate, goods[index].expirationdate);
                            found = true;}}
                    if (!found) {printf("There are no items with such cost!\n");}}
                else if (strcmp(choice, "storage period") == 0) {
                    printf("Enter the storage period : ");int storageperiod;scanf("%d", &storageperiod);getchar();
                    bool found = false;
                    for (int index = 0; index < length; index++) {
                        if (storageperiod == goods[index].storageperiod) {
                            printf("%d. Name : %15s, Cost : %2d$ , Storage period : %d, Variety : %s, Released date : %s, Expiration date : %s\n",index + 1, goods[index].name, goods[index].cost, goods[index].storageperiod,goods[index].variety, goods[index].releasedate, goods[index].expirationdate);
                            found = true;}}
                    if (!found) {printf("There are no items with such storage period!\n");}}
                else if (strcmp(choice, "variety") == 0) {
                    printf("Enter the variety : ");char variety[20];fgets(variety,sizeof(variety),stdin);variety[strlen(variety) - 1] = '\0';
                    bool found = false;
                    for (int index = 0; index < length; index++) {
                        if (strcmp(variety, goods[index].variety)) {
                            printf("%d. Name : %15s, Cost : %2d$ , Storage period : %d, Variety : %s, Released date : %s, Expiration date : %s\n",index + 1, goods[index].name, goods[index].cost, goods[index].storageperiod,goods[index].variety, goods[index].releasedate, goods[index].expirationdate);
                            found = true;}}
                    if (!found) {printf("There are no items with such variety!\n");}}
                else if (strcmp(choice, "release date") == 0) {
                    printf("Enter the release date : ");char releasedate[20];fgets(releasedate,sizeof(releasedate),stdin);releasedate[strlen(releasedate - 1)] = '\0';
                    bool found = false;
                    for (int index = 0; index < length; index++) {
                        if (strcmp(releasedate, goods[index].releasedate)) {
                            printf("%d. Name : %15s, Cost : %2d$ , Storage period : %d, Variety : %s, Released date : %s, Expiration date : %s\n",index + 1, goods[index].name, goods[index].cost, goods[index].storageperiod,goods[index].variety, goods[index].releasedate, goods[index].expirationdate);
                            found = true;}}
                    if (!found) {printf("There are no items with such release date!\n");}}
                else if (strcmp(choice, "expiration date") == 0) {
                    printf("Enter the expiration date : ");char expirationdate[20];fgets(expirationdate,sizeof(expirationdate),stdin);expirationdate[strlen(expirationdate) - 1] = '\0';
                    bool found = false;
                    for (int index = 0; index < length; index++) {
                        if (strcmp(expirationdate, goods[index].expirationdate) == 0) {
                            printf("%d. Name : %15s, Cost : %2d$ , Storage period : %d, Variety : %s, Released date : %s, Expiration date : %s\n",index + 1, goods[index].name, goods[index].cost, goods[index].storageperiod,goods[index].variety, goods[index].releasedate, goods[index].expirationdate);
                            found = true;}}
                    if (!found) {printf("There are no items with such expiration date!\n");}}
            else{printf("Options [name], [cost], [storage period], [variety], [release date], and [expiration date]\n");}}}
        else if (strcmp(input, "remove") == 0){
            if(length  < 1){printf("There is no date yet!\n");}
            else{int remove;
            output(goods, length);
            do{
                printf("Enter the number of an array you want to remove : ");
                scanf("%d", &remove);
                if(!(remove >= 1 && remove <= length)){printf("Invalid number!");}
            }while(!(remove >= 1 && remove <= length));
            length--;remove--;
            for(int index = remove; index < length + 1; index++){
                strcpy(goods[index].name,goods[index + 1].name);
                goods[index].cost = goods[index + 1].cost;
                goods[index].storageperiod = goods[index + 1].storageperiod;
                strcpy(goods[index].variety,goods[index + 1].variety);
                strcpy(goods[index].releasedate,goods[index + 1].releasedate);
                strcpy(goods[index].expirationdate,goods[index + 1].expirationdate);
            }
            goods = (struct Goods *)realloc(goods, length * sizeof(struct Goods));
            while(getchar() != '\n');
            if(length){printf("Struct with number %d element removed\n" , remove + 1);
            output(goods, length);}}}
        else if (strcmp(input, "add") == 0) {
            length++;
            goods = (struct Goods *)realloc(goods, length * sizeof(struct Goods));
            printf("Name : ");fgets(goods[length - 1].name, sizeof(goods[length - 1].name), stdin);goods[length - 1].name[strcspn(goods[length - 1].name, "\n")] = '\0';
                bool error;
            do{
                error = false;
                printf("Cost : ");
                if(scanf("%d", &goods[length - 1].cost) != 1){
                    printf("Please, enter a number!\n");
                    error = true;}
                else{error = false;}
                while(getchar() != '\n');
            }while(error);
            do{
                error = false;
                printf("Storage period : ");
                if(scanf("%d", &goods[length - 1].storageperiod) != 1){
                    printf("Please, enter a number! (days)\n");
                    error = true;}
                else{error = false;}
            while(getchar() != '\n');
            }while(error);
            printf("Variety : ");fgets(goods[length - 1].variety, sizeof(goods[length - 1].variety), stdin);goods[length - 1].variety[strcspn(goods[length - 1].variety, "\n")] = '\0';
            do{
                printf("Release date : ");
                fgets(goods[length - 1].releasedate, sizeof(goods[length - 1].releasedate), stdin);
                if(goods[length - 1].releasedate[strlen(goods[length - 1].releasedate) - 1] == '\n'){goods[length - 1].releasedate[strlen(goods[length - 1].releasedate) - 1] = '\0';}
                if(datecheck(goods[length - 1].releasedate)){printf("Please, enter the date in format : dd.mm.yyyy\n");}
            }while(datecheck(goods[length - 1].releasedate));
            do{
                printf("Expiration date : ");
                fgets(goods[length - 1].expirationdate, sizeof(goods[length - 1].expirationdate), stdin);
                if(goods[length - 1].expirationdate[strlen(goods[length - 1].expirationdate) - 1] == '\n'){goods[length - 1].expirationdate[strlen(goods[length - 1].expirationdate) - 1] = '\0';}
                if(datecheck(goods[length - 1].expirationdate)){printf("Please, enter the date in format : dd.mm.yyyy\n");}
            }while(datecheck(goods[length - 1].expirationdate));}
        else if (strcmp(input, "sort") == 0) {
            if (length < 1) {printf("There is no data yet!\n");}
            else if (length == 1) {printf("There is only one element!\n");}
            else {
                char criteria[20];
                do {
                    printf("Enter the criteria : ");
                    fgets(criteria, sizeof(criteria), stdin);
                    if (criteria[strlen(criteria) - 1] == '\n') {criteria[strlen(criteria) - 1] = '\0';}
                    tolowercase(criteria);
                    if (strcmp(criteria, "cost") != 0 && strcmp(criteria, "storage period") && strcmp(criteria, "release date") != 0 && strcmp(criteria, "expiration date") != 0) {printf("Options : [cost], [storage period], [release date], and [expiration date]\n");}
                }while (strcmp(criteria, "cost") != 0 && strcmp(criteria, "storage period") && strcmp(criteria, "release date") != 0 && strcmp(criteria, "expiration date") != 0);
                int order;
                do {
                    printf("Enter 1 or 0 for sorting in ascending and descending order, respectively : ");scanf("%d", &order);getchar();
                    if (order != 0 && order != 1) {printf("Please, enter a valid number!\n");}
                }while (order != 0 && order != 1);
                bubbleSort(goods, length, criteria, order);
                printf("Sorted : \n");
                output(goods, length);}}
    else if (strcmp(input, "exit") != 0) {printf("Options : [add], [output], [cls], [sort], and [exit]\n");}
    }while (strcmp(input, "exit") != 0);
    free(goods);
    return 0;}