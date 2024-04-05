#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* truncateSentence(char* s, int k) {
    int number = 0;
    int length = strlen(s);
    char * result = (char*) malloc((length + 1) * sizeof(char));
    for(int i = 0; i < length+1; i++){
        result[i] = s[i];
        if(s[i] == ' '){
            number += 1;
            if(number == k){
                result[i] = '\0';
                break;
            }
        }
    }
    return result;
}

int main(){

    char s[] =  "What is the solution to this problem";
    int k = 3;

    char* result = truncateSentence(s, k);
    
    printf("%s\n", result);

    free(result);

    return 0;
}