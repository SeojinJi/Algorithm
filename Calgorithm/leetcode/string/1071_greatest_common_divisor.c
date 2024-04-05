#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GCD(int a, int b){
    int number = a % b;
    if(number == 0){
        return b;
    }
    return GCD(b, number);
}

char* gcdOfStrings(char* str1, char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    int length = length1 + length2 + 1;
    char* leftstr = (char*)malloc(length * sizeof(char));
    char* rightstr = (char*)malloc(length * sizeof(char));
    strcpy(leftstr, str1);
    strcat(leftstr, str2);
    strcpy(rightstr, str2);
    strcat(rightstr, str1);

    if(!strcmp(leftstr, rightstr)){
        int gcdresult = GCD(length1, length2);
        char* result = (char*)malloc((gcdresult+1)*sizeof(char));
        strncpy(result, leftstr, gcdresult);
        result[gcdresult] = '\0';
        return result;
    }

    char* result ="";
    return result; 
}

int main(){
    char* str1 = "ABABAB";
    char* str2 = "ABAB";

    char* result = gcdOfStrings(str1, str2);
    printf("%s", result);
    return 0;
}