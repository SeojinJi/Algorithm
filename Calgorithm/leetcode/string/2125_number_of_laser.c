#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 500

int numberOfBeams(char** bank, int bankSize) {
    if(bankSize == 1){
        return 0;
    }
    int number[MAX] = {0};
    for(int i = 0; i < bankSize; i++){
        for(int j = 0; j < strlen(bank[i]); j++){
            if(bank[i][j] == '1'){
                number[i] += 1;
            }
        }
    }
    int result = 0;
    int lindex = 0;
    int rindex = 1;
    while(rindex < bankSize){
        if(number[lindex] == 0){
            lindex += 1;
            rindex += 1;
            continue;
        }
        if(number[rindex] == 0){
            rindex += 1;
            continue;
        }
        result += number[lindex] * number[rindex];
        lindex = rindex;
        rindex += 1;
    }
    return result;
}

int main(){
    char* bank[] = {"00000","00101","10100","11110","11100","01001","00100","11010"};
    int bankSize = 8;
    int result = numberOfBeams(bank, bankSize);
    printf("%d", result);
    return 0;
}