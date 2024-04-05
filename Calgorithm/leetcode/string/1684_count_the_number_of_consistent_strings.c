#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int alen = strlen(allowed);
    int result = 0;
    for(int i = 0; i < wordsSize; i++){
        int allow = 0;
        for(int j = 0; j < strlen(words[i]); j++){
            int flag = 0;
            for(int k = 0; k < alen; k++){
                if(allowed[k] == words[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                allow = 1;
                break;
            }
        }
        if(allow == 0){
            result++;
        }
    }
    return result;
}

int main(){
    char* allowed = "cad";
    char* words[] = {"cc","acd","b","ba","bac","bad","ac","d"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    int result = countConsistentStrings(allowed, words, wordsSize);
    printf("%d", result);
    return 0;
}