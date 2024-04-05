#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char* s){
    int length = strlen(s) + 1;
    char* output = (char *)malloc(length * sizeof(char));
    int index = 0;
    for(int i = 0; i < length-1; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            output[index] = s[i]+32;
            index++;
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            output[index] = s[i];
            index++;
        }
        if(s[i] >= '0' && s[i] <= '9'){
            output[index] = s[i];
            index++;
        }
    }
    output[index] = '\0';
    int outputlength = strlen(output);
    for(int i = 0; i < outputlength; i++){
        if(output[i] != output[outputlength-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    char* s = "A man, a plan, a canal: Panama";
    bool result = isPalindrome(s);
    printf("%d", result);
    return 0;
}