#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc == 1 || argc > 3){ printf("Invalid Command!\n"); }
    else{
        /* Write your code here */
        FILE *file;
        int charNum = 0; int wordNum = 0;
        char ch;

        file = fopen(argv[1], "r");
        if(!file){
            printf("File does not exist!\n");
        }
        else{
            while((ch = fgetc(file)) != EOF){
                if(ch==' ' || ch == '\t' || ch == '\n' || ch == '\0'){
                    wordNum++;
                }
                else{
                    charNum++;
                }
            }
            if(charNum > 0){
                wordNum++;
            }
            printf("Total characters = %d\n", charNum);
            printf("Total words = %d\n", wordNum);
            
            fclose(file);
        }

    }
    return 0;
}