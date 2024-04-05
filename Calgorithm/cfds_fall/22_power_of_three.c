#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int P1(int n) {
// Write your code below
  if(n == 0){
    return 0;
  }
  else if(n==1){
    return 1;
  }
  int power = 0;
  int number = n;
  while(number > 1){
    number = number / 2;
    power++;
  }
  int result = pow(2, power);

  return (pow(3,power)+P1(n-result));
}

// DO NOT MODIFY BELOW!
int main(int argc, char* argv[]) {
  int n = atoi(argv[1]);
  printf("%d", P1(n));
  return 0;
}