#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return(*(int *)a - *(int *)b);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        result[i] = nums[i] * nums[i];
    } 
    qsort(result, *returnSize, sizeof(int), compare);

    return result;
}


int main(){
    int nums[] = {-4,-1,0,3,10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;
    int* result = sortedSquares(nums, numsSize, &returnSize);
    for(int i = 0; i < returnSize; i++){
        printf("%d\n", result[i]);
    }
    return 0;
}