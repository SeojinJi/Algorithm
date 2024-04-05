#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int minPartitions(char* n) {
    int largest = 0;
    int len = strlen(n);
    for(int i = 0; i < len; i++) {
        int digit = n[i] - '0'; // 문자를 숫자로 변환
        if(digit > largest) {
            largest = digit;
        }
    }
    return largest;
}

int main(){
    char* n = "27346209830709182346";
    int result = minPartitions(n);
    printf("%d", result);
    return 0;
}