#include <stdio.h>
#include <stdbool.h>

int main(void){
    /* Your Code Here */
    int number = 2;
    while(number < 100){
        bool result = true;
        for(int i = 2; i < number; i++){
            if(number % i == 0 && number != i){
                result = false;
                break;
            } 
        }
        if(result == true){
            printf("%d ",number);
        }
        number++;
    }
    return 0; 
}


