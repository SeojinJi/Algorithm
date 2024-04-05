#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b){
    return(*(int *)a - *(int *)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    int **result;
    int row = arrSize * (arrSize - 1);
    int column = 2;

    // 결과 배열 할당
    result = (int **) malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++){
        result[i] = (int *) malloc(column * sizeof(int));
    }

    // 배열 정렬
    qsort(arr, arrSize, sizeof(int), compare);

    // 최소 차이 계산
    int minDiff = arr[1] - arr[0];
    int size = 0;
    for(int i = 1; i < arrSize; i++){
        int diff = arr[i] - arr[i-1];
        if(minDiff > diff){
            size = 0;
            minDiff = diff;
        }
        if(minDiff == diff){
            result[size][0] = arr[i-1];
            result[size][1] = arr[i];
            size++;
        }
    }

    // 결과 반환을 위한 설정
    *returnSize = size;
    *returnColumnSizes = (int *) malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = column;
    }

    return result;
}

int main(){

    int arr[] = {4, 2, 1, 3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int returnSize = 0;
    int *returnColumnSizes = 0;

    int ** result =  minimumAbsDifference(arr, arrSize, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
    }
    for(int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    return 0;
}
