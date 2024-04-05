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

char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len+1)*sizeof(char));
    char* temp = (char*)malloc((len+1)*sizeof(char));
    int num = 0;
    int flag = 0;
    for(int i = 0; i <= len; i++){
        if(s[i] != ' ' && s[i] != '\0'){
            temp[num] = s[i];
            temp[num+1] = '\0';
            num++;
        }
        else if((s[i] == ' ' || s[i] == '\0') && flag == 0){
            printf("%s\n", temp);
            char* temprev = strreverse(temp);
            printf("%s\n", temprev);
            strcpy(result, temprev);
            printf("%s\n", result);
            if (s[i] == ' ') {
                strcat(result, " ");
            }
            num = 0;
            flag = 1;
            free(temp);
            temp = (char*)malloc((len+1)*sizeof(char));
        }
        else if(s[i] == ' ' || s[i] == '\0'){
            char* temprev = strreverse(temp);
            strcat(result, temprev);
            if (s[i] == ' ') {
                strcat(result, " ");
            }
            num = 0;
            free(temp);
            temp = (char*)malloc((len+1)*sizeof(char));
        }
    }
    free(temp);
    return result;
}

int main(){
    char* s = "Let's take LeetCode contest";
    char* result = reverseWords(s);
    printf("%s", result);
    return 0;
}