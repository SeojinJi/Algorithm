#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* strreverse(char* s){
    int len = strlen(s);
    char* result = (char*)malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        result[i] = s[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

bool isPalindrome(int x) {
    char* number = (char*)malloc(12 * sizeof(char));
    sprintf(number, "%d", x);
    char* reverse = (char*)malloc(12 * sizeof(char));
    strcpy(reverse, number);
    char* strre = strreverse(reverse);
    if(strcmp(number, strre) == 0){
        return true;
    }
    return false;
}

int main(){
    int x = -121;
    bool result = isPalindrome(x);
    printf("%d\n", result);
    return 0;
}