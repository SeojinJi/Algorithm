#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct palchar{
    char c;
    int number;
} palchar;

char * sortVowels(char * s){
    int length = strlen(s);
    palchar nodechar[10];
    nodechar[0].c = 'A';
    nodechar[0].number = 0;
    nodechar[1].c = 'E';
    nodechar[1].number = 0;
    nodechar[2].c = 'I';
    nodechar[2].number = 0;
    nodechar[3].c = 'O';
    nodechar[3].number = 0;
    nodechar[4].c = 'U';
    nodechar[4].number = 0;
    nodechar[5].c = 'a';
    nodechar[5].number = 0;
    nodechar[6].c = 'e';
    nodechar[6].number = 0;
    nodechar[7].c = 'i';
    nodechar[7].number = 0;
    nodechar[8].c = 'o';
    nodechar[8].number = 0;
    nodechar[9].c = 'u';
    nodechar[9].number = 0;
    int* number = (int *)malloc(length * sizeof(int));
    int index = 0;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < 10; j++){
            if(nodechar[j].c == s[i]){
                nodechar[j].number += 1;
                number[index] = i;
                index++;
                break;
            }
        }
    }
    if(index == 0 || index == 1){
        return s;
    }
    char* result = (char*)malloc((length+1)*sizeof(char));
    int n = 0;
    for(int i = 0; i < length; i++){
        if(i != number[n]){
            result[i] = s[i];
        }
        else{
            for(int j = 0; j < 10; j++){
                if(nodechar[j].number > 0){
                    result[i] = nodechar[j].c;
                    nodechar[j].number--;
                    n++;
                    break;
                }
            }
        }
    }
    result[length] = '\0';
    return result ;
}

int main(void){
    char * s = "lYmpH";
    char* result = sortVowels(s);
    printf("%s", result);
    return 0;
}