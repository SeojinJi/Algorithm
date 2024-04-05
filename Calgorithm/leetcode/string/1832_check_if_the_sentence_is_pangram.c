#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkIfPangram(char* sentence) {
    int alphabet[26] = {0};
    int len = strlen(sentence);
    for(int i = 0; i < len; i++){
        alphabet[sentence[i] - 97]++;
    }
    for(int i = 0; i < 26; i++){
        if(alphabet[i] == 0){
            return false;
        }
    }
    return true;
}

int main(){
    char* sentence = "leetcode";
    bool result = checkIfPangram(sentence);
    printf("%d", result);
    return 0;
}
