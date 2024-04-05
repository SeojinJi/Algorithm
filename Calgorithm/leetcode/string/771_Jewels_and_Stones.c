#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palchar{
    char c;
    int number;
} palchar;


int numJewelsInStones(char* jewels, char* stones) {
    int jlength = strlen(jewels);
    int slength = strlen(stones);
    palchar snodechar[55];
    int index = 0;
    for(int i = 0; i < slength; i++){
        if(index == 0){
            snodechar[index].c = stones[i];
            snodechar[index].number = 1;
            index++;
        }
        else{
            int boolean = 0;
            for(int j = 0; j <index; j++){
                if(snodechar[j].c == stones[i]){
                    snodechar[j].number += 1;
                    boolean = 1;
                }
            }
            if(boolean == 0){
                snodechar[index].c = stones[i];
                snodechar[index].number = 1;
                index++;
            }           
        }
    }

    int number = 0;
    for(int i = 0; i < jlength; i++){
        for(int j = 0; j < index; j++){
            if(snodechar[j].c == jewels[i]){
                number += snodechar[j].number;
            }
        }
    }
    return number;
}

int main(){
    char* jewels = "z";
    char* stones = "ZZ";
    int result = numJewelsInStones(jewels, stones);
    printf("%d", result);
    return 0;
}