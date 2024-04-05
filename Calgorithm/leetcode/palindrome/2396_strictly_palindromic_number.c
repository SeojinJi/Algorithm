#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isStrictlyPalindromic(int n) {
    for(int i = 2; i < n - 1; i++){
        int number = n;
        int* mcimal = (int *) malloc(18 * sizeof(int));
        int index = 0;
        while(number > 0){
            mcimal[index] = number % i;
            number = number / i;
            index++;
        }
        for(int j = 0; j < index / 2; j++){
            if(mcimal[j] != mcimal[index - 1 - j]){
                return false;
            }
        }
        free(mcimal);
    }
    return true;
}

int main(){
    int n = 9;
    bool result = isStrictlyPalindromic(n);
    printf("%d", result);
    return 0;
}