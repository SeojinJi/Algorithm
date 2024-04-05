#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define STRLEN 12
#define MAXLEN 4096

int getLen(int i) {  // 이진수 i의 1 개수 리턴
    int count = 0;
    while (i) {
        count += i & 1;
        i >>= 1;
    }
    return count;
}

// i에 해당하는 string 뽑아내기
char* getString(char* in, char* out, int i, int len_out) {
    /*
    i: string 번호
    len_out: 뽑은 이진수의 길이
    */
    int j = 0;
    int k = 0;
    int slen = strlen(in);
    while (i) {
        if (i & 1) {
            out[len_out - j - 1] = in[slen - k - 1];
            ++j;
        }
        i >>= 1;
        ++k;
    }
    out[len_out] = '\0';
};

int is_palin(char* s) {
    int slen = strlen(s);
    for (int i = 0; i < slen / 2; ++i) {
        if (s[i] != s[slen - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int maxProduct(char* s) {
    int len = strlen(s);
    if(len == 2){
        return 1;
    }
    char temp[STRLEN + 1];
    int max_len = 0;
    int max2_len = -1;

    // for 문 2 ** input_len 회 돌리기
    for (int i = 1; i < pow(2, len); ++i) {
        // i에 해당하는 substring 길이 받기
        int len_out = getLen(i); // 이렇게 하면 다 좋은데 문제는 substring이 둘이 겹치면 안된다는 조건을 못 지킴

        // 길이가 갱신되면
        if (len_out >= max_len && len_out != len) {
            // string update, 길이 업데이트
            getString(s, temp, i, len_out);
            if (is_palin(temp) == 1) {
                max2_len = max_len;
                max_len = len_out;
            }
        }
    }
    return max2_len * max_len;
}

int main(){
    char* s = "bccb";
    int result = maxProduct(s);
    printf("%d", result);
    return 0;
}


