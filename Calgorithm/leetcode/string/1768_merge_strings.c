#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * mergeAlternately(char * word1, char * word2){
    int length = strlen(word1) + strlen(word2) + 1;
    char* output = (char *)malloc(length*sizeof(char)*10000);
    if(word1 == NULL && word2 == NULL){
        return NULL;
    }
    int index = 0;
    int index1 = 0;
    int index2 = 0;
    while(word1[index1] && word2[index1]){
        output[index] = word1[index1];
        index1 += 1;
        index += 1;
        output[index] = word2[index2];
        index2 += 1;
        index += 1;
    }
    while(word1[index1]){
        output[index] = word1[index1];
        index += 1;
        index1 += 1;
    }
    while(word2[index2]){
        output[index] = word2[index2];
        index2 += 1;
        index += 1;
    }
    output[index] = '\0';
    return output;
}

int main(){
    char* word1 = "abcde";
    char* word2 = "pqrs";

    char* result = mergeAlternately(word1, word2);
    printf("%s", result);

    return 0;
}