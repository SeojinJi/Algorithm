#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* makeSmallestPalindrome(char * s){
    int length = strlen(s);
    char* output = (char*)malloc((length+1)*sizeof(char));
    strcpy(output, s);
    if(length == 0 || length == 1){
        return s;
    }
    for(int i = 0; i < length / 2; i++){
        if(s[i] != s[length-1-i]){
            if(s[i] > s[length-1-i]){
                output[i] = s[length-1-i];
            }
            else{
                output[length-1-i] = s[i];
            }
        }
    }
    output[length] = '\0';
    return output;
}

int main(){
    char* s = "seven";
    char* result = makeSmallestPalindrome(s);
    printf("%s", result);
    return 0;
}