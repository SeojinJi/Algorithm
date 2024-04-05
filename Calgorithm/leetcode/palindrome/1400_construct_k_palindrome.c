#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct palchar{
    char c;
    int number;
} palchar;


bool canConstruct(char* s, int k) {
    int length = strlen(s);
    if(length < k){
        return false;
    }
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
    int number = 0;
    for(int i = 0; i < index; i++){
        if(nodechar[i].number % 2 == 1){
            number++;
        }
    }
    if(number > k){
        return false;
    }
    return true;
}

int main(){
    char* s = "true";
    int k = 4;
    bool result = canConstruct(s, k);
    printf("%d", result);
    return 0;
}
