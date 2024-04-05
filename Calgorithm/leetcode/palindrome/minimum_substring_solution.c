// 최소한의 문자를 제거해서 팰린드롬 만들고, 제거한 문자개수 리턴

// 모든 substring을 temp에다가가 하나씩 넣고,
// 가장 길이가 긴 것을 뽑고, 전체 길이 - 현재 길이 하면 끝

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

int q2(char* in, char* out) {
    int len_in = strlen(in);
    char temp[STRLEN + 1];
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
                strcpy(out, temp);
            }
        }
    }
    return len_in - max_len;
}

void main() {
    char input[STRLEN + 1];
    printf("Input: ");
    scanf("%s", input);

    char output[STRLEN + 1];
    int ans = q2(input, output);

    printf("%s\n", output);
    printf("%d\n", ans);
}

/*
string 길이가 10이면 그 sub string은 가짓수가 총 2**10-1 = 1023 입니다. (길이 0 제외)
각 substring 을 1부터 1023 까지의 자연수에 대응시킬 수 있습니다.
이 때 substring을 자연수에 일대응 대응 시키는 방법은
해당 자연수를 이진수로 표현해서, 그에 대응하는 character를 포함 시키거나 포함 하지 않으면 됩니다.
예를 들어 이진수가 11111 11111 이면 모든 character가 포함된 substring에 대응합니다.
00000 00001 이면, 마지막 character만 포함된 substring에 대응합니다.
길이가 1023 인 for문을 돌려서 getString함수에 1부터 1023 까지 집어넣으면,
각 숫자에 해당하는 string을 차례로 뱉어줍니다.
쏟아져 나오는 string 중에서 문제의 조건에 맞는 녀석을 찾아서 이용하면 됩니다.
*/