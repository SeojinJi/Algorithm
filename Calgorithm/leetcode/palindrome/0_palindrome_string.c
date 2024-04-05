#include <stdio.h>
#include <string.h>

char* s1;
char* s2;

// 길이
int strlen(s1);

// 복사, 슬라이싱
void strcpy(s1, s2);
void strncpy(s1, s2, n);

// python
// s1 = s2[3:10]
// C
// void strncpy(s1, s2 + 3, 7);

//concat
void strcat(s1, s2); // s1 = s1 + s2
void strncat(s1, s2, n);

// 뒤집기
void strrev(s1); // 리턴 없이 s1이 뒤집힘
char* strreverse(char* s){
    int len = strlen(s);
    char* result = (char*)malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        result[i] = s[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

// index i 인 문자 제거
void iErase(char* str, char* result, int i){
    int len = strlen(str);
    if (i < 0 || i >= len){
        strcpy(result, str);
        return;
    }
    strncpy(result, str, i);
    result[i] = '\0';
    strcat(result, str+i+1);
};

// 비교 식, {-1,. 0, 1} 리턴
int strcmp(s1, s2);
int strncmp(s1, s2, n);

// 스트링(또는 문자) 찾기
char* strstr(s1, s2);  // s1에서 s2를 찾아서 있으면 해당 포인터 반환

int is_palin(char* s){ // 0 no , 1 yes
    int slen = strlen(s);
    for(int i = 0; i < slen / 2 ; ++i){
        if(s[i] != s[slen - 1 - i]){
            return 0;
        }
    }
    return 1;
}

int is_n_palin(char* s, int n){
    for(int i = 0; i < n / 2; ++i){
        if(s[i] != s[n - 1 - i]){
            return 0;
        }
    }
    return 1;
}

// 문자를 숫자로 바꾸기
int num = atoi(str); //문자열을 숫자로 바꾸기
int digit = n[i] - '0'; // 문자 하나씩 숫자로 바꾸기

// 숫자를 문자로 바꾸기
sprintf(str, "%d", num);

// 문자 숫자
int a = 'a'; // a = 97
int z = 'z'; // z = 122
int A = 'A'; // A = 65
int Z = 'Z'; // Z = 90
printf("%d", a - 32);
printf("%c", a - 32);

int a = '0'; // 48
int b = '9'; // 57
// strstr 사용법
int main() {
    char str[] = "Hello, world!";
    char substr[] = "world";

    // 문자열 str에서 substr을 찾음
    char *result = strstr(str, substr);

    if (result != NULL) {
        printf("'%s' found at index %d\n", substr, (int)(result - str));
    } else {
        printf("'%s' not found\n", substr);
    }

    return 0;
}

// 문자열을 long integer로 변환하는데 사용
int main() {
    char str[] = "12345";
    char* endptr;
    long num;

    // 문자열을 long integer로 변환
    num = strtol(str, &endptr, 10); // str : 변환할 문자열, 
    //&endptr : 변환된 문자열의 마지막 위치를 나타내는 포인터, 10 : 변환할 문자열이 몇 진수인가

    if (*endptr != '\0') {
        printf("변환 실패: 변환된 부분 다음에 다른 문자가 있습니다.\n");
    } else {
        printf("변환 성공: %ld\n", num);
    }

    return 0;
}