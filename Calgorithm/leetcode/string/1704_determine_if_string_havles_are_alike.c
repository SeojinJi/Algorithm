#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool halvesAreAlike(char* s) {
    int length = strlen(s); // 4
    int firstv = 0;
    int firstx = 0;
    int secondv = 0;
    int secondx = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vsize = sizeof(vowels) / sizeof(vowels[0]);
    for(int i = 0; i < length / 2; i++){
        int flag = 0;
        for(int j = 0; j < vsize; j++){
            if(s[i] == vowels[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            firstx++;
        }
        else{
            firstv++;
        }
    }

    for(int i = length / 2; i < length; i++){
        int flag = 0;
        for(int j = 0; j < vsize; j++){
            if(s[i] == vowels[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            secondx++;
        }
        else{
            secondv++;
        }
    }
    if(firstx == secondx && firstv == secondv){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char* s = "textbook";
    // int result = strlen(s);
    bool result = halvesAreAlike(s);
    printf("%d", result);
    return 0;
}