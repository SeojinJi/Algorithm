#include <stdio.h>
#define SIZE 10   // Define constant

void selection_sort(int L[], int size);  // Remember declaration!!!!!!!!!!!!!!

int main(void){
    int L[SIZE] = {9, 8, 1, 6, 23, 4, 3, 11, 85, 0};
    
    printf("Before selection sort: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", L[i]);
    } 
    printf("\n");

    selection_sort(L, SIZE);

    printf("After selection sort: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", L[i]);
    } 
    printf("\n");

    return 0;
}

void selection_sort(int L[], int size){
    int smallest;
    int temp;
    /* Your code here*/
    for(int i = 0; i < size; i++){
        smallest = i;
        for(int j = i+1; j < size; j++){
            if(L[j] < L[smallest]){
                smallest = j;
            }
        }
        temp = L[i];
        L[i] = L[smallest];
        L[smallest] = temp;
    }
}

/*
<Test>
-> gcc p2.c -o p2
-> ./p2

<output>
Before selection sort: 9 8 1 6 23 4 3 11 85 0 
After selection sort: 0 1 3 4 6 8 9 11 23 85
*/

