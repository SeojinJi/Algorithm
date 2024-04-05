#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(void const *a, void const *b) {
    return *(int *)a - *(int *)b;
}

int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int output = numsSize;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != i){
            output = i;
            return output;
        }
    }
    return output;
}

int main(){
    int nums[] = {3, 0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = missingNumber(nums, numsSize);
    printf("%d", result);

    return 0;
}