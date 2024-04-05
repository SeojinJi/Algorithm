#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int size = argc-2; // Size of array
    int arr[size];
    for(int i=0;i<size;i++){
        arr[i] = atoi(argv[i+1]);
    }
    int result[size]; // array you have to fill it
    int rotate = atoi(argv[size+1]); // number of rotation  

    /* Write your code here */
    for (int i = 0; i < size; i++){
        result[i] = arr[i];
    }
    for(int j = 0; j < rotate; j++){
        int temp = result[size - 1];
        for(int i = size - 2; i > -1; i--){
            result[i+1] = result[i];
        }
        result[0] = temp;
    } 
    

    // DO NOT MODIFY BELOW!!!
    for (int i=0; i<size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}