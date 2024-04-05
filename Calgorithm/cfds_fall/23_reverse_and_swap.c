#include <stdio.h>
#include <stdlib.h> // for atoi()
 
void swap(int *firstVal, int *secondVal);  // Remember declaration!
void reverse_dig(int *val);                // Remember declaration!

int main(int argc, char* argv[]){ // argc: 입력된 문자열 갯수, argv: 입력된 문자열 
    int a = atoi(argv[1]); // argv[1]: 처음 입력된 문자열
    int b = atoi(argv[2]); // argv[2]: 두번째로 입력된 문자열

    printf("Before Reverse: a = %d, b = %d\n", a, b);
    reverse_dig(&a);
    reverse_dig(&b);
    printf("After Reverse: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After Swap: a = %d, b = %d\n", a, b);

    return 0;
}

void reverse_dig(int *val){
    int temp = *val;
    int ans = 0;
    int re = 0; // 나머지

    /* Your code here*/
    while(temp > 0){
        re = temp % 10;
        ans = ans*10 + re;
        temp = temp / 10;
    }
    *val = ans;
}


void swap(int *firstVal, int *secondVal){
    int tempVal;

    /* Your code here*/
    tempVal = *firstVal;
    *firstVal = *secondVal;
    *secondVal = tempVal;
}

/*
<Test>
-> gcc p1.c -o p1
-> ./p1 1234 7890

<output>
Before Reverse: a = 1234, b = 7890
After Reverse: a = 4321, b = 987
After Swap: a = 987, b = 4321

*/