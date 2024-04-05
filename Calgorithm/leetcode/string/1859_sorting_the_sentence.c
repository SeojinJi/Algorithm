#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* sortSentence(char* s){
    int len = strlen(s);
    char** resultSen = (char**)malloc(10 * sizeof(char*));
    for(int i = 0; i < 10; i++){
        resultSen[i] = (char*)malloc((len+1)*sizeof(char));
    }
    char* temp = (char*)malloc((len+1)*sizeof(char));
    int index = 0;
    int largest = 0;
    int num = 0;
    for(int i = 0; i < len; i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            temp[num] = s[i];
            temp[num+1] = '\0';
            num++;
        }
        else if(s[i] >= '1' && s[i] <= '9'){
            int number = s[i] - 48;
            if(largest < number){
                largest = number;
            }
            strcpy(resultSen[number], temp);
            free(temp);
            num = 0;
            char* temp = (char*)malloc((len+1)*sizeof(char));
        }
    }
    char* result = (char*)malloc((len+1)*sizeof(char));
    for(int i = 1; i < largest+1; i++){
        if(i == 1){
            int leni = strlen(resultSen[i]);
            strcpy(result, resultSen[i]);
            result[leni] = ' ';
            result[leni+1] = '\0';
        }
        else if(strlen(resultSen[i]) > 0){
            int leni = strlen(result) + strlen(resultSen[i]);
            strcat(result, resultSen[i]);
            result[leni] = ' ';
            result[leni+1] = '\0';
        }
    }
    return result;
}

int main(){
    char* s = "Myself2 Me1 I4 and3";
    char* result = sortSentence(s);
    printf("%s", result);
    return 0;
}