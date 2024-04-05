#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* minOperations(char* boxes, int* returnSize) {
    int len = strlen(boxes);
    int* result = (int*)malloc(len * sizeof(int));
    *returnSize = len;
    for(int i = 0; i < len; i++){
        int num = 0;
        for(int j = 0; j < len; j++){
            if(i==j){
                continue;
            }
            if(boxes[j] == '1'){
                if(i <= j){
                    num += (j - i);
                }
                else{
                    num += (i - j);
                }
            }
        }
        result[i] = num;
    }
    return result;
}

int main(){
    char* boxes = "110";
    int returnSize = 0;
    int* result = minOperations(boxes, &returnSize);
    for(int i = 0; i < returnSize; i++){
        printf("%d\n", result[i]);
    }
    return 0;
}