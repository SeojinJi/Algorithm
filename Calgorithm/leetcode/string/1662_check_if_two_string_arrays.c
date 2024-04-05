#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    char* word1sum = (char*)malloc(1001*sizeof(char));
    char* word2sum = (char*)malloc(1001*sizeof(char));
    for(int i = 0; i < word1Size; i++){
        if(i==0){
            strcpy(word1sum, word1[i]);
        }
        else{
            strcat(word1sum, word1[i]);
        }
    }
    for(int i = 0; i < word2Size; i++){
        if(i==0){
            strcpy(word2sum, word2[i]);
        }
        else{
            strcat(word2sum, word2[i]);
        }
    }
    if(strcmp(word1sum, word2sum) == 0){
        return true;
    }
    return false;
}

int main(){
    char* word1[] = {"abc", "d", "defg"};
    int word1Size = 3;
    char* word2[] = {"abcddefg"};
    int word2Size = 1;

    bool result = arrayStringsAreEqual(word1, word1Size, word2, word2Size);
    printf("%d\n", result);
    return 0; 
}