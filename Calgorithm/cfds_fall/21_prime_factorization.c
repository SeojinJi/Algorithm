#include <stdio.h>

int main(void){
    int num;
    printf("Enter the number to be factorized: ");
    scanf("%d", &num);
    /* Your Code Here */
    int number = 2;
    while(num > 1){
        int result = 0;
        if(num % number == 0){
            while(num % number == 0){
                num = num / number;
                result += 1;
            }
            printf("(%d, %d)", number, result);
        }
        number++;
    }
    return 0;
}

