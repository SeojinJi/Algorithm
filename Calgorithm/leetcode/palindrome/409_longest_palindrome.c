#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct palchar{
    char c;
    int number;
} palchar;

int longestPalindrome(char* s) {
    int length = strlen(s);
    palchar nodechar[55];
    int index = 0;
    for(int i = 0; i < length; i++){
        if(index == 0){
            nodechar[index].c = s[i];
            nodechar[index].number = 1;
            index++;
        }
        else{
            int boolean = 0;
            for(int j = 0; j <index; j++){
                if(nodechar[j].c == s[i]){
                    nodechar[j].number += 1;
                    boolean = 1;
                }
            }
            if(boolean == 0){
                nodechar[index].c = s[i];
                nodechar[index].number = 1;
                index++;
            }           
        }
    }
    int flag = 0;
    int result = 0;
    for(int i = 0; i < index; i++){
        if((nodechar[i].number % 2 == 1)){
            flag = 1;
            result += (nodechar[i].number - 1);         
        }
        else if(nodechar[i].number %2 == 0){
            result += nodechar[i].number;
        }
    }
    if(flag == 1){
        result += 1;
    }
    return result;
}

int main(){
    char* s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    int result = longestPalindrome(s);
    printf("%d", result);
    return 0;
}

/* Solution */
int longestPalindrome(char* s) {
    int mylist[125]={0};
    for (int i=0; i<strlen(s); i++){
        mylist[s[i]]++;
    }
    int answer=0;
    int holsoo=0;
    for (int i=0; i<125; i++){
        if (mylist[i]>0){
            answer= answer + 2*(mylist[i]/2);
        }
        if (mylist[i]%2==1){
            holsoo=1;
        }
    }
    answer=answer+holsoo;
    return answer;


}
