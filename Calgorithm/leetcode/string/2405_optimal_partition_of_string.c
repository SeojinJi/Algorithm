#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct palchar{
    char c;
    int number;
} palchar;

int partitionString(char* s) {
    int length = strlen(s);
    palchar* nodechar = (palchar*)malloc(55*sizeof(nodechar));
    // palchar nodechar[55];
    int num = 1;
    int index = 0;
    for(int i = 0; i < length; i++){
        int boolean = 0;
        for(int j = 0; j <index; j++){
            if(nodechar[j].c == s[i]){
                boolean = 1;
                break;
            }
        }
        // printf("%d, %c\n", boolean, s[i]);   
        if(boolean == 0){
            nodechar[index].c = s[i];
            nodechar[index].number = 1;
            index++;
        }
        else{
            free(nodechar);
            palchar* nodechar = (palchar*)malloc(55*sizeof(nodechar));
            nodechar[0].c = s[i];
            nodechar[0].number = 1;
            index = 1;
            num++;
        }           
    }
    return num;
}

int main(){
    char* s = "fxuyyriftuhxnsx";
    int result = partitionString(s);
    printf("%d", result);
    return 0;
}