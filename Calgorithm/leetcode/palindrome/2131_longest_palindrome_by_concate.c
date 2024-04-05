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

int is_palin(char* s){ // 0 no , 1 yes
    int slen = strlen(s);
    for(int i = 0; i < slen / 2 ; ++i){
        if(s[i] != s[slen - 1 - i]){
            return 0;
        }
    }
    return 1;
}

typedef struct palchar{
    char* c;
    int number;
} palchar;


int longestPalindrome(char** words, int wordsSize) {
    // 싹 다 그냥 딕셔너리에 넣어버려.
    palchar nodechar[55];
    int index = 0;
    for(int i = 0; i < wordsSize; i++){
        if(index == 0){
            nodechar[index].c = words[i];
            nodechar[index].number = 1;
            index++;
        }
        else{
            int boolean = 0;
            for(int j = 0; j <index; j++){
                if(nodechar[j].c == words[i]){
                    nodechar[j].number += 1;
                    boolean = 1;
                }
            }
            if(boolean == 0){
                nodechar[index].c = words[i];
                nodechar[index].number = 1;
                index++;
            }           
        }
    }
    int result = 0;
    int flag = 0;
    for(int i = 0; i < index; i++){
        if(is_palin(nodechar[i].c) && flag == 0 && nodechar[i].number % 2 == 1){
            printf("1 %s, %d\n", nodechar[i].c,nodechar[i].number);
            flag = 1;
            result += (nodechar[i].number) * 2;
            continue;
        }
        else if(is_palin(nodechar[i].c)){
            printf("2 %s, %d\n", nodechar[i].c,nodechar[i].number);
            result += (nodechar[i].number / 2) * 4;
        }
        for(int j = i+1; j < index; j++){
            char* rev = strreverse(nodechar[j].c);
            if(strcmp(nodechar[i].c, rev) == 0){
                if(nodechar[i].number >= nodechar[j].number){
                    printf("3 %s, %d\n", nodechar[i].c,nodechar[i].number);
                    result += (nodechar[j].number) * 4;
                }
                else{
                    printf("4 %s, %d\n", nodechar[i].c,nodechar[i].number);
                    result += (nodechar[i].number) * 4;
                }
            }
        }
    }
    return result;
}




int main(){
    char* words[] = {"dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc"};
    //aa = 3, bb = 3, cc = 3, dd = 5 -> 22
    // char* words[] = {"ll","lb","bb","bx","xx","lx","xx","lx","ll","xb","bx","lb","bb","lb","bl","bb","bx","xl","lb","xx"};
    // ll = 2, lb = 4, bb = 3, bx = 3, xx = 3, lx = 2, xb = 1, bl = 1, xl = 1
    // ll = 2, xx = 3, lb = 1, bb = 2, lx = 1, xb = 1, 
    int wordsSize = sizeof(words) / sizeof(words[0]);
    int result = longestPalindrome(words, wordsSize);
    printf("%d", result);
    return 0;
}



// 어느 C에서는 위의 코드의 답이 이상하게 나와서 아래 내용 첨부함
/*
typedef struct palchar{
    char* c[100];
    int number;
} palchar;


int longestPalindrome(char** words, int wordsSize) {
    palchar nodechar[4000];
    int index = 0;
    for(int i = 0; i < wordsSize; i++){
        int found = 0;
        for(int j = 0; j < index; j++){
            if(strcmp(nodechar[j].c, words[i]) == 0){
                nodechar[j].number++;
                found = 1;
                break;
            }
        }
        if(!found){
            strcpy(nodechar[index].c, words[i]);
            nodechar[index].number = 1;
            index++;
        }
    }
    int result = 0;
    int flag = 0;
    for(int i = 0; i < index; i++){
        if(is_palin(nodechar[i].c) && flag == 0 && nodechar[i].number % 2 == 1){
            // printf("1 %s, %d\n", nodechar[i].c,nodechar[i].number);
            flag = 1;
            result += (nodechar[i].number) * 2;
            continue;
        }
        else if(is_palin(nodechar[i].c)){
            // printf("2 %s, %d\n", nodechar[i].c,nodechar[i].number);
            result += (nodechar[i].number / 2) * 4;
        }
        for(int j = i+1; j < index; j++){
            char* rev = strreverse(nodechar[j].c);
            if(strcmp(nodechar[i].c, rev) == 0){
                if(nodechar[i].number >= nodechar[j].number){
                    // printf("3 %s, %d\n", nodechar[i].c,nodechar[i].number);
                    result += (nodechar[j].number) * 4;
                }
                else{
                    // printf("4 %s, %d\n", nodechar[i].c,nodechar[i].number);
                    result += (nodechar[i].number) * 4;
                }
            }
        }
    }
    return result;
}
*/