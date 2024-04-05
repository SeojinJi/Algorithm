#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_palin(char* s){
    int slen = strlen(s);
    for(int i = 0; i < slen / 2 ; ++i){
        if(s[i] != s[slen - 1 - i]){
            return false;
        }
    }
    return true;
}

bool is_substring(char* s,char* t){
    char* str = strstr(s, t);  // s1에서 s2를 찾아서 있으면 해당 포인터 반환
    if(str == NULL){
        return false;
    }
    else{
        return true;
    }
}

int factorial(int num){
    if(num == 1){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}

bool is_subarray(char** result, char* output, int resultindex){ // 해당 array가 있는지 없는지 확인
    for(int i = 0; i < resultindex; i++){
        if(strstr(output, result[i]) != NULL || strstr(result[i], output) != NULL){
            return true;
        }
    }
    return false;
}

char** max_palindromes(char *s, int *returnSize){
    int len = strlen(s);
    char** result = (char**)malloc(factorial(len) * sizeof(char*));
    for(int i = 0; i < factorial(len); i++){
        result[i] = (char*)malloc((len + 1) * sizeof(char)); // +1 for null terminator
    }
    int resultindex = 0;

    for(int start = 0; start < len; start++) {
        for(int end = start; end < len; end++) {
            int sublen = end - start + 1;
            char* substr = (char*)malloc((sublen + 1) * sizeof(char)); // +1 for null terminator
            strncpy(substr, s + start, sublen);
            substr[sublen] = '\0';
            
            if(is_palin(substr)) {
                strcpy(result[resultindex++], substr);
            }
            free(substr);
        }
    }
    char** final = (char**)malloc(resultindex * sizeof(char*));
    int finalindex = 0;
    for(int i = 0; i < resultindex; i++){
        final[i] = (char*)malloc((len + 1) * sizeof(char)); // +1 for null terminator
    }
    for(int start = 0; start < resultindex; start++){
        int flag = 0;
        for(int end = 0; end < resultindex; end++){
            if(is_substring(result[end], result[start]) == true && start != end){
                flag = 1;
                break;
            }
            if(strcmp(result[start], result[end]) == 0 && is_subarray(final, result[start], finalindex) == false && start != end){
                strcpy(final[finalindex++], result[start]);
            }
            
        }
        if(flag == 0){
            strcpy(final[finalindex++], result[start]);
        }
    }

    *returnSize = finalindex;
    return final;
}

int main(){
    char* s = "abc";
    int returnSize = 0;
    char** result = max_palindromes(s, &returnSize);

    printf("Number of palindromes: %d\n", returnSize);
    for(int i = 0; i < returnSize; i++){
        printf("%s\n", result[i]);
        free(result[i]); // Free memory allocated for each palindrome
    }
    free(result); // Free memory allocated for result array

    return 0;
}