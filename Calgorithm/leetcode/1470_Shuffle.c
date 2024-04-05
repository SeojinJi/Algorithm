#include <stdio.h>
#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* result = (int*) malloc(sizeof(int) * n * 2);
    for(int i = 0; i < n; i++){
        result[i*2] = nums[i];
        result[2*i+1] = nums[n+i]; 
    }
    *returnSize = n * 2;
    return result;
}

int main(){

    int nums[] = {1,1,2,2};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int n = 2;
    int *returnSize = (int *) malloc(numSize * sizeof(int));

    int* result = shuffle(nums, numSize, n, returnSize);

    for(int i = 0; i < numSize; i++){
        printf("%d, ", result[i]);
    }
    printf("\n");

    free(returnSize);

    return 0;
}