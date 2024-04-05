#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // 회문이 아님
        }
        start++;
        end--;
    }
    return 1; // 회문임
}

void partitionHelper(char* s, int start, int len, char*** result, int* resultSize, char** path, int* pathSize) {
    if (start == len) {
        // 파티션 완료, 결과에 추가
        char** partition = (char**) malloc((*pathSize) * sizeof(char*));
        for (int i = 0; i < *pathSize; i++) {
            partition[i] = strdup(path[i]);
        }
        result[*resultSize] = partition;
        (*resultSize)++;
        return;
    }

    for (int i = start; i < len; i++) {
        if (isPalindrome(s, start, i)) {
            // 현재 부분 문자열이 회문이면 추가
            path[*pathSize] = (char*) malloc((i - start + 2) * sizeof(char));
            strncpy(path[*pathSize], s + start, i - start + 1);
            path[*pathSize][i - start + 1] = '\0'; // Null-terminate the string
            (*pathSize)++;

            // 재귀 호출
            partitionHelper(s, i + 1, len, result, resultSize, path, pathSize);

            // 백트래킹: 현재 부분 문자열을 제거하여 다음 부분 문자열 탐색
            (*pathSize)--;
            free(path[*pathSize]);
        }
    }
}

// 주어진 문자열의 모든 회문 파티션을 찾는 함수
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s);
    *returnSize = 0;
    *returnColumnSizes = NULL;

    // 결과 배열 및 임시 저장 배열 초기화
    char*** result = (char***) malloc(1000 * sizeof(char**));
    char** path = (char**) malloc(len * sizeof(char*));
    int pathSize = 0;

    // 재귀 호출을 통해 모든 회문 파티션 찾기
    partitionHelper(s, 0, len, result, returnSize, path, &pathSize);

    // 결과 리턴
    *returnColumnSizes = (int*) malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = pathSize;
    }

    free(path);
    return result;
}

int main(){
    char* s = "aab";
    int returnSize = 0;
    int *returnColumnSizes = 0;
    char** result = partition(s, &returnSize, &returnColumnSizes);
    for(int i = 0; i < *returnColumnSizes; i++){
        for(int j = 0; j <returnSize; j++){
            printf("%s", result[i][j]);
        }
    }
    return 0;
}