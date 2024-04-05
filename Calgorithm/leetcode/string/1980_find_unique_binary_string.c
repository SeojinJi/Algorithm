#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

char* decimalToBinary(int n, int size){
    int binary[32]; // 32비트까지만 처리
    int i = 0;
    
    // n이 0보다 크거나 같을 때까지 2로 나누며 이진수로 변환
    while(n > 0){
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // 지정된 크기의 문자열을 할당하고 0으로 초기화
    char* result = (char*)malloc((size+1)*sizeof(char));
    for(int j = 0; j < size; j++){
        result[j] = '0';
    }
    result[size] = '\0'; // 문자열 끝에 널 문자 추가

    // 이진수 값을 문자열에 할당
    for(int j = i - 1; j >= 0; j--){
        result[size - (i - j) - 1] = binary[j] + '0';
    }

    return result;
}

char* findDifferentBinaryString(char** nums, int numsSize) {
    int numlen = strlen(nums[0]);
    char* result = (char*)malloc((numlen+1)*sizeof(char));
    int num = pow(2, numlen);
    printf("%d\n",num);
    int* decimalnum = (int *)malloc(numsSize * sizeof(int));
    for(int i = 0 ; i < numsSize; i++){
        char* endptr;
        decimalnum[i] = strtol(nums[i], &endptr, 2);
    }
    for(int i = 0; i < num; i++){
        int flag = 0;
        for(int j = 0; j < numsSize; j++){
            if(i == decimalnum[j]){
                printf("%d\n", decimalnum[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            // 2진수로 변환한 값 꺼내면 됨
            printf("%d\n", i);
            result = decimalToBinary(i, numlen);
            return result;
        }
    }
}



int main(){
    char* nums[] = {"00","01"};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    char* result = findDifferentBinaryString(nums, numsSize);
    printf("%s", result);
    return 0;
}

/* Solution
char* findDifferentBinaryString(char** nums, int numsSize) {
    char* output = (char*)malloc((numsSize + 1) * sizeof(char)); 
    for (int i = 0; i < numsSize; i++) {
        if (nums[i][i] == '1') {
            output[i] = '0';
        } else {
            output[i] = '1';
        }
    }
    output[numsSize] = '\0';
    return output;
}
*/