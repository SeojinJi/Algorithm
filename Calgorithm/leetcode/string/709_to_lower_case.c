#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* toLowerCase(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            result[i] = s[i] + 32;
        }
        else{
            result[i] = s[i];
        }
    }
    result[len] = '\0';
    return result;
}

int main(){
    char* s = "Hello";
    char* result = toLowerCase(s);
    printf("%s", result);
    return 0;
}