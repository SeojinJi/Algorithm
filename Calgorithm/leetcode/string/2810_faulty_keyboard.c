#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strreverse(char* s){
    int len = strlen(s);
    char* result = (char*)malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        result[i] = s[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

char* finalString(char* s){
    int len = strlen(s);
    int num = 0;
    char* result = (char*)malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        if(s[i] != 'i'){
            result[num] = s[i];
            result[num+1] = '\0';
            num++;
        }
        else if(s[i] == 'i' && i == 0){
            continue;
        }
        else if(s[i] == 'i'){
            result = strreverse(result);
        }
    }
    return result;
}

int main(){
    char* s = "pointer";
    char* result = finalString(s);
    printf("%s", result);
    return 0;
}