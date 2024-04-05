#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 1024
#define STRLEN 10

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

int longestPalindromeSubseq(char* in) {
    int len_in = strlen(in);
    char temp[STRLEN + 1];
    char output[STRLEN + 1];
    int max_len = 0;

    // for 문 2 ** input_len 회 돌리기
    for (int i = 1; i < pow(2, len_in); ++i) {
        // i에 해당하는 substring 길이 받기
        int len_out = getLen(i);

        // 길이가 갱신되면
        if (len_out > max_len) {
            // string update, 길이 업데이트
            getString(in, temp, i, len_out);
            if (is_palin(temp) == 1) {
                max_len = len_out;
                strcpy(output, temp);
            }
        }
    }
    printf("%s\n", output);
    return len_in - max_len;
}

void main() {
    char* input = "bbbab";
    int ans = longestPalindromeSubseq(input);
    printf("%d\n", ans);
}
