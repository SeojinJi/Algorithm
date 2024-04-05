#include <stdio.h>

int largestAltitude(int* gain, int gainSize) {
    int largest = 0;
    int altitude = 0;

    for(int i = 0; i < gainSize; i++){
        altitude += gain[i];
        if(largest < altitude){
            largest = altitude;
        }
    }
    return largest;
}

int main(){
    int gain[] = {-4,-3,-2,-1,4,3,2};
    int gainSize = sizeof(gain) / sizeof(gain[0]);

    printf("%d", largestAltitude(gain, gainSize));

    return 0;
}