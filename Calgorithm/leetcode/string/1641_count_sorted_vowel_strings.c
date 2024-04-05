#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countVowelStrings(int n) {
    int result[5] = {1, 1, 1, 1, 1};
    int sumresult = 0;
    if(n == 1){
        sumresult = 5;
        return sumresult;
    }
    else{
        for(int i = 1; i < n; i++){
            int final[5] = {0};
            for(int j = 0; j < 5; j++){
                int number = 0;
                for(int k = j; k < 5; k++){
                    number += result[k];
                }
                final[j] = number;
            }
            for(int j = 0; j < 5; j++){
                result[j] = final[j];
            }
        }
    }
    for(int i = 0; i < 5; i++){
        sumresult += result[i];
    }
    return sumresult;
}

int main(){
    int n = 33;
    int result = countVowelStrings(n);
    printf("%d", result);
    return 0;
}