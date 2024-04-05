#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool judgeCircle(char* moves) {
    int length = strlen(moves);
    int x = 0;
    int y = 0;
    for(int i = 0; i < length; i++){
        if(moves[i] == 'U'){
            y++;
        }
        else if(moves[i] == 'D'){
            y--;
        }
        else if(moves[i] == 'L'){
            x--;
        }
        else if(moves[i] == 'R'){
            x++;
        }
    }
    if(x==0 && y == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char* moves = "LL";
    bool result = judgeCircle(moves);
    printf("%d", result);
    return 0;
}