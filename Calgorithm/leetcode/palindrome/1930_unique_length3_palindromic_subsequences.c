#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_subarray(char** result, char* output, int resultindex){ // 해당 array가 있는지 없는지 확인
    for(int i = 0; i < resultindex; i++){
        if(strstr(output, result[i]) != NULL || strstr(result[i], output) != NULL){
            return true;
        }
    }
    return false;
}


int is_palin(char* s){ // 0 no , 1 yes
    int slen = strlen(s);
    for(int i = 0; i < slen / 2 ; ++i){
        if(s[i] != s[slen - 1 - i]){
            return 0;
        }
    }
    return 1;
}

int countPalindromicSubsequence(char* s) {
    int length = strlen(s);
    int num = 0;
    char** result = (char**)malloc(20000 * sizeof(char*));
    for(int i = 0; i < 20000; i++){
        result[i] = (char*)malloc(4 * sizeof(char));
    }
    for(int i = 0; i < length; i++){
        for(int j = i+1; j < length; j++){
            for(int k = j+1; k < length; k++){
                char* output = (char*)malloc(4 * sizeof(char));
                strncpy(output, s+i, 1);
                output[1]='\0';
                strncat(output, s+j, 1);
                strncat(output, s+k, 1); 
                if(is_palin(output)){
                    if(is_subarray(result, output, num) == false){
                        // printf("%s\n", output);
                        result[num] = output;
                        num++;
                    }
                }
                free(output);
            }
        }
    }
    for(int i = 0; i < 20000; i++) {
        free(result[i]);
    }
    free(result);
    return num;
}

int main(){
    char* s = "aabca";
    int result = countPalindromicSubsequence(s);
    printf("%d", result);
    return 0;
}
