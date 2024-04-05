#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    char* truck[] = {"G", "P", "M"};
    int count[3] = {0, 0, 0};
    int time[3] = {0, 0, 0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < garbageSize; j++){
            for(int k = 0; k < strlen(garbage[j]); k++){
                if(garbage[j][k] == truck[i][0]){
                    count[i] += 1;
                }
            }
        }
    }
    
    for(int i = 0; i < 3; i++){
        int num = 0;
        for(int j = 0; j < garbageSize; j++){
            for(int k = 0; k < strlen(garbage[j]); k++){
                if(garbage[j][k] == truck[i][0]){
                    time[i] += 1;
                    num += 1;
                }
            }
            if(num == count[i]){
                break;
            }
            else{
                time[i] += travel[j];
            }
        }
    }
    int result = 0;
    for(int i = 0; i < 3; i++){
        result += time[i];
    }
    return result;
}

int main(){
    char* garbage[] = {"MMM","PGM","GP"};
    int garbageSize = 3;
    int travel[] = {3, 10};
    int travelSize = 2;
    int result = garbageCollection(garbage, garbageSize, travel, travelSize);
    printf("%d", result);
    return 0;
}