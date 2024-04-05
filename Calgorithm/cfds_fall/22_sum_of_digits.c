#include <stdio.h>
#include <stdlib.h>

// Implement P2 
// You can define other function, but P2 must return answer.

int P2(int n){
// write your code below
    int result = 0;
    while(n > 1){
        result += n % 10;
        n = n / 10;
    }
    return result;
}


// DO NOT MODIFY BELOW!
int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int ans = P2(n);

    printf("%d\n", ans);

    return 0;
}