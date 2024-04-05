#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_palin(char* s){ // 0 no , 1 yes
    int slen = strlen(s);
    for(int i = 0; i < slen / 2 ; ++i){
        if(s[i] != s[slen - 1 - i]){
            return 0;
        }
    }
    return 1;
}

int minimumLength(char* s) {
    int len = strlen(s);
    if(len == 1){
        return 1;
    }
    int left = 0;
    int right = len - 1;
    // printf("%d, %d\n", left, right);
    while(left < right){
        char leftstr = s[left];
        char rightstr = s[right];
        printf("%c, %d\n", leftstr, left);
        printf("%c, %d\n", rightstr, right);
        printf("\n");
        if(leftstr != rightstr){
            break;
        }
        else{
            while(s[left+1] == leftstr && left < right){
                left++;
            }
            while(s[right-1] == rightstr && left < right){
                right--;
            }
        }
        left++;
        right--;
    }
    if(right < left){
        return 0;
    }
    return right-left+1;
}

int main(){
    char* s = "bbbbbbbbbbbbbbbbbbb";
    int result = minimumLength(s);
    printf("%d", result);
    return 0;
}