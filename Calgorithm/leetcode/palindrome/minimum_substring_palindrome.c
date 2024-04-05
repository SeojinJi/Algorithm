// 긴 문자열이 주어졌을 때, 최소한의 문자를 빼서 palindrome 만들기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// palindrome 여부 확인
bool is_palin(char* s){ // 0 no , 1 yes
    int slen = strlen(s);
    for(int i = 0; i < slen / 2 ; ++i){
        if(s[i] != s[slen - 1 - i]){
            return false;
        }
    }
    return true;
}

// index i 인 문자 제거
void iErase(char* str, char* result, int i){
    int len = strlen(str);
    if (i < 0 || i >= len){
        strcpy(result, str);
        return;
    }
    strncpy(result, str, i);
    result[i] = '\0';
    strcat(result, str+i+1);
}

typedef struct palchar{
    char c;
    int number;
} palchar;

int compare(void const *a, void const *b) {
    return *(int *)b - *(int *)a;
}


char* miniPalindrome(char* s){
    int length = strlen(s);
    palchar nodechar[55];
    int index = 0;
    for(int i = 0; i < length; i++){
        if(index == 0){
            nodechar[index].c = s[i];
            nodechar[index].number = 1;
            index++;
        }
        else{
            int boolean = 0;
            for(int j = 0; j <index; j++){
                if(nodechar[j].c == s[i]){
                    nodechar[j].number += 1;
                    boolean = 1;
                }
            }
            if(boolean == 0){
                nodechar[index].c = s[i];
                nodechar[index].number = 1;
                index++;
            }           
        }
    }
    int left = 0;
    int right = length - 1;
    int mid = (left + right) / 2;
    int * number = (int *)malloc((length+1) * sizeof(int));
    int numberindex = 0;
    while(left < right){
        if(s[left] == s[right]){
            left += 1;
            right -= 1;
        }
        else{
            int flag = 0;
            for(int i = 0; i < index; i++){
                if(nodechar[i].c == s[left]){
                    if(nodechar[i].number % 2 == 1){
                        nodechar[i].number -= 1;
                        number[numberindex] = left;
                        numberindex++;
                        left += 1;
                        break;
                    }
                    else{
                        flag = 1;
                    }
                }
            }
            if(left >= right){
                break;
            }
            for(int i = 0; i < index; i++){
                if(nodechar[i].c == s[right]){
                    if(nodechar[i].number % 2 == 1){
                        nodechar[i].number -= 1;
                        number[numberindex] = right;
                        numberindex++;
                        right -= 1;
                    }
                    else{
                        if(flag == 1 && left + 1 != right){
                            number[numberindex] = right;
                            numberindex++;
                            right -= 1;
                        }
                        else if(flag == 1 && left + 1 == right){
                            right -= 1;
                        }
                    }
                }
            }
        }
        printf("%d, %d\n", left, right);
    }
    qsort(number, numberindex, sizeof(int), compare);
    char* result = (char*)malloc(length * sizeof(char));
    for(int i = 0; i < numberindex; i++){
        // printf("%d\n", number[i]);
        char* result = (char*)malloc((length+1) * sizeof(char));
        iErase(s, result, number[i]);
        s = result;
    }
    // printf("%d\n", numberindex);
    return s;
}


int main(){
    char* s = "ccbb";
    char* result = miniPalindrome(s);
    printf("%s", result);
    return 0;
}
