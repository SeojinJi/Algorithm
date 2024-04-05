#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 문자열 내의 두 문자를 교환하는 함수
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// 비교 함수
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// 문자열을 이용하여 순열을 생성하고 배열에 저장하는 함수
void permute(char *str, int start, int end, char **permutations, int *count) {
    if (start == end) {
        // 순열을 동적 메모리에 저장
        permutations[*count] = (char *)malloc((end + 2) * sizeof(char)); // +2 for null terminator and extra space
        strcpy(permutations[*count], str);
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            // str[start]부터 str[i]까지의 문자열을 고정하고,
            // 나머지 문자들에 대해 재귀적으로 순열 생성
            swap((str + start), (str + i));
            permute(str, start + 1, end, permutations, count);
            // 다음 순열을 위해 문자열을 다시 원래대로 되돌림
            swap((str + start), (str + i));
        }
    }

    // 마지막에 순열을 생성하고 정렬
    if (start == end) {
        // 정렬
        qsort(permutations, *count, sizeof(char *), compare);
        // 같은 게 존재하는 경우 빼기
        int i = 1;
        while(i < *count){
            if(strcmp(permutations[i],permutations[i-1])==0){
                for(int j = i; j < *count; j++){
                    permutations[j] = permutations[j+1];
                }
                *count -= 1;
            }
            i++;
        }
    }
}

int main() {
    char str[] = "abb";
    int n = strlen(str);
    
    // 순열을 저장할 배열과 순열 개수를 저장할 변수 선언
    char **permutations = (char **)malloc(1000 * sizeof(char *));
    int count = 0;

    permute(str, 0, n - 1, permutations, &count);

    // 정렬된 순열 출력
    for (int i = 0; i < count; i++) {
        printf("%s\n", permutations[i]);
        free(permutations[i]); // 각 순열에 할당된 메모리 해제
    }

    free(permutations); // 순열 배열에 할당된 메모리 해제
    return 0;
}