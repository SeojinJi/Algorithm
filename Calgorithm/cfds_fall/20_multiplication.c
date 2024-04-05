#include <stdio.h>

int main(void){
    int a, b;
    printf("Enter a number less than 1000 : ");
    scanf("%d", &a);
    printf("Enter a number less than 1000 : ");
    scanf("%d", &b);
    //////////////////////////////////////////
    // Write your code
    int num = b;
    while (num > 0){
        int num1 = num % 10;
        printf("%d\n", a * num1);
        num = num / 10;
    }
    printf("%d\n", a * b);


    //////////////////////////////////////////
    return 0;
}