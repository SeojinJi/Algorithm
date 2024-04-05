#include <stdio.h>
#include <stdlib.h>

// Implement P1 
// You can define other function, but P1 must return answer.

int P1(int n){ 
// write your code below
    if(n == 1){
        return 1;
    }
    else{
        return (P1(n-1)*2 +1);
    }
}


// DO NOT MODIFY BELOW!
int main(int argc, char* argv[]){ 
    int n = atoi(argv[1]);
    int ans = P1(n);

    printf("%d\n", ans);

    return 0;
}