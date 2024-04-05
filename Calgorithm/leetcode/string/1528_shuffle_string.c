#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* restoreString(char* s, int* indices, int indicesSize) {
    int len = strlen(s); // 8
    char* result = (char*)malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        result[indices[i]] = s[i];
    }
    result[len] = '\0';
    return result;
}

int main(){
    char* s = "abc";
    int indices[] = {0, 1, 2};
    int indicesSize = sizeof(indices) / sizeof(indices[0]);
    char* result = restoreString(s, indices, indicesSize);
    printf("%s", result);
    return 0;
}