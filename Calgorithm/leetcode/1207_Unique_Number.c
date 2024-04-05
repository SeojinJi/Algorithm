#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 2001

bool uniqueOccurences(int *arr, int arrSize){
    int count[MAX_SIZE] = {0};
    bool seen[MAX_SIZE] = {false};

    for(int i = 0 ; i < arrSize; i++){
        count[arr[i] + 1000] += 1;
    }
    for(int i = 0; i < MAX_SIZE; i++){
        if(count[i] != 0){
            if(seen[count[i]] != false){
                return false;
            }
            else{
                seen[count[i]] = true;
            }
        }
    }

    return true;
}

int main(){
    int arr[] = {-3,0,1,-3,1,1,1,-3,10,0};
    int arrSize = arrSize = sizeof(arr) / sizeof(arr[0]);

    bool result = uniqueOccurences(arr, arrSize);
    printf("%d", result);

    return 0;
}