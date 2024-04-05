#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct alpha{
    char ch[1000];
} alpha;

char* convert(char* s, int numRows) {
    if(numRows == 1){
        return s;
    }
    int length = strlen(s);
    alpha* word = (alpha*)malloc(numRows * sizeof(alpha));
    for (int i = 0; i < numRows; ++i)
        strcpy(word[i].ch, "");
    word[0].ch[0] = s[0];
    int index = 1;
    int wordindex = 0;
    int reverse = 0;
    while(index < length){
        // printf("%c", s[index]);
        if(reverse == 0){
            for(int i = 1; i < numRows; i++){
                word[i].ch[wordindex] = s[index];
                word[i].ch[wordindex+1] = '\0';
                index++;
            }
            wordindex++;
            reverse = 1;
            continue;
        }
        else if(reverse == 1){
            for(int i = numRows - 2; i >= 0; i--){
                word[i].ch[wordindex] = s[index];
                word[i].ch[wordindex+1] = '\0';
                index++;
            }
            wordindex++;
            reverse = 0;
            continue;
        }
    }
    char* result = (char*)malloc((length+1)*sizeof(char));
    int resultindex = 0;
    // printf("%d\n", numRows);
    // printf("%d\n", wordindex);
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < wordindex; j++){
            printf("%c ", word[i].ch[j]);
            if(word[i].ch[j] == '\0'){
                continue;
            }
            result[resultindex] = word[i].ch[j];
            resultindex++;
        }
        printf("\n");
    }
    if((result[resultindex-1] >= 'a' && result[resultindex-1] <= 'z') || (result[resultindex-1] >= 'A' && result[resultindex-1] <= 'Z')){
        result[resultindex] = '\0';
    }
    else{
        result[resultindex-1] = '\0';
    }
    free(word);
    return result;
}

int main(){
    char* s = "PAYPALISHIRING";
    int numRows = 3;
    char* result = convert(s, numRows);
    printf("%s", result);
    return 0;
}