#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int length = strlen(senate);
    int* radiant = (int *) malloc(sizeof(int) * length);
    int* dire = (int *) malloc(sizeof(int) * length);
    int r = 0;
    int d = 0;
    char* output;
    for(int i = 0; i < length; i++){
        if(senate[i] == 'R'){
            radiant[r] = i;
            r++;
        }
        else{
            dire[d] = i;
            d++;
        }
    }
    int number = length;
    while(r != 0 && d != 0){
        int rnumber = radiant[0];
        int dnumber = dire[0];
        for(int i = 1; i < r; i++){
            radiant[i-1] = radiant[i];
        }
        for(int i = 1; i < d; i++){
            dire[i-1] = dire[i];
        }
        r--;
        d--;
        if(rnumber < dnumber){
            radiant[r] = number;
            r++;
        }
        else{
            dire[d] = number;
            d++;
        }
        number++;
    }
    if(r == 0){
        output = "Dire";
    }
    else{
        output = "Radiant";
    }
    return output;
}

int main(){
    char senate[] = "RDD";
    char* result = predictPartyVictory(senate);
    printf("%s\n", result);
    return 0;
}