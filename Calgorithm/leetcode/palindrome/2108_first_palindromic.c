#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* firstPalindrome(char** words, int wordsSize) {
    int length = 0;
    for(int i = 0; i < wordsSize; i++){
        if(length < strlen(words[i])){
            length = strlen(words[i]);
        }
    }
    char* output = (char *)malloc(length+1);
    output[0] = '\0';
    for(int i = 0; i < wordsSize; i++){
        int wordSize = strlen(words[i]);
        char* wordsreversed = (char *)malloc(wordSize+1);
        strcpy(wordsreversed, words[i]);
        for(int j = 0; j < wordSize / 2; j++){
            char temp = wordsreversed[j];
            wordsreversed[j] = wordsreversed[wordSize-j-1];
            wordsreversed[wordSize-j-1] = temp; 
        }
        if(strcmp(words[i], wordsreversed)==0){
            output = words[i];
            return output;
        }
    }
    return output;
}

int main(){

    char* words[] = {"abc", "car", "ada", "racecar", "cool"};
    int wordsSize = 5;
    char* result = firstPalindrome(words, wordsSize);
    printf("%s", result);
    return 0;
}