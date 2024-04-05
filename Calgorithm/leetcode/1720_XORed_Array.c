#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    int *enArray;
    *returnSize=encodedSize+1;
    enArray=(int*)malloc(sizeof(int)*(*returnSize));
    enArray[0]=first;
    for(int i=0;i<encodedSize;i++){
        enArray[i+1]=enArray[i]^encoded[i];
    }
    return enArray;
}

int main(){

    int encoded[] = {6, 2, 7, 3};
    int encodedSize = sizeof(encoded) / sizeof(encoded[0]);
    int first = 4;
    int returnSize = 0;

    int * result = decode(encoded, encodedSize, first, &returnSize); 

    for(int i = 0; i < returnSize; i++){
        printf("%d, ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}