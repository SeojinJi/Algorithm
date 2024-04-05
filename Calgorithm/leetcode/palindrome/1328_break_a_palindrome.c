#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* breakPalindrome(char* palindrome) {
    int length = strlen(palindrome);
    if(length == 1){
        return "";
    }
    char* result = (char*)malloc((length+1) * sizeof(char));
    int flag = 0;
    for(int i = 0; i < length; i++){
        if(palindrome[i] != 'a' && flag == 0 && i != length / 2){
            result[i] = 'a';
            flag = 1;
        }
        else{
            result[i] = palindrome[i];
        }
    }
    if(flag == 0){
        result[length-1] = 'b';
    }
    result[length] = '\0';
    return result;
}

int main(){
    char* palindrome = "aba";
    char* result = breakPalindrome(palindrome);
    printf("%s", result);
    return 0;
}