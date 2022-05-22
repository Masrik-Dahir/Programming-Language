#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
    // The string
    // char str[] = "For example a String";

    // Memory allocation variables 
    int variableNumberOfElements = sizeof argv[1];
    int ID_LEN = sizeof argv[1];
    char **orderedIds;

    // Necessary variables
    int i;

    // Memory allocation
    orderedIds = malloc(variableNumberOfElements * sizeof(char*));
    for (i = 0; i < variableNumberOfElements; i++){
        orderedIds[i] = malloc((ID_LEN+1) * sizeof(char));
    }

    // strtok
    char *token = strtok(argv[1], " ");
    i = 0;
    while (token != NULL){
        // printf("%s\n", token);
        orderedIds[i] = token;
        token = strtok(NULL, " ");
        i ++ ;
    }
    for(int i = 0; *orderedIds[i] != '\0'; i++){
        printf("%s\n", orderedIds[i]);
    }
    free(orderedIds);

    return 0;

}