#include <stdio.h>
#include <stdlib.h>

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    int* result = (int *) malloc((deckSize) * sizeof(int));
    *returnSize = deckSize;

    if(deckSize == 1){
        result[0] = deck[0];
        return result;
    }

    for(int i = 0; i < deckSize; i++){
        int largest = i;
        for(int j = i+1; j < deckSize; j++){
            if(deck[largest] < deck[j]){
                largest = j;
            }
        }
        int temp = deck[i];
        deck[i] = deck[largest];
        deck[largest] = temp; 
    } // sorting

    return deck;

    result[0] = deck[0];
    result[1] = deck[1];
    int length = 2;
    while(length < deckSize){
        int temp = result[0];
        for(int i = 1; i < length; i++){
            result[i-1] = result[i];
        }
        result[length - 1] = temp;
        result[length] = deck[length];
        length++;
    }

    for(int i = 0; i < deckSize / 2; i++){
        int temp = result[i];
        result[i] = result[deckSize - i - 1];
        result[deckSize - i - 1] = temp; 
    }

    return result;

}

int main(){

    int deck[] = {17,13,11,2,3,5,7};
    int deckSize = sizeof(deck) / sizeof(deck[0]);
    int returnSize = 0;

    int* result = deckRevealedIncreasing(deck, deckSize, &returnSize);

    for(int i = 0; i < returnSize; i++){
        printf("%d, ", result[i]);
    }

    return 0;
}