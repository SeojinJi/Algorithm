#include <stdio.h>

int main(void){
    float a;
    printf("Enter a decimal : ");
    scanf("%f", &a);
    //////////////////////////////////////////
    // Write your code
    if(a > 0){
        int int_a = (int)a;
        float result = a - int_a;
        if(result < 0.5){
            printf("%d", int_a);
        }
        else{
            printf("%d", int_a+1);
        }
    }
    else{
        int int_a = (int)a;
        float result = int_a - a;
        if(result > 0.5){
            printf("%d", int_a-1);
        }
        else{
            printf("%d", int_a);
        }
    }
    //////////////////////////////////////////
    return 0;
}