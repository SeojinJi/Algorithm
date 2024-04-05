#include <stdio.h>
#include <string.h>

int main (void){
    /* Write your code here */
    // hint1) You should use strcmp(str1, str2) and it returns 0 if they match. '==' doesn't work to compare strings.
    // hint2) To print 1 => 01 and 11 => 11, use '%02d' instead of '%d'.
	int hour, minute;
    char indicator[3];
    printf("Enter a time in 12-hour clock : ");
    scanf("%d:%d %s", &hour, &minute, &indicator);

    if((hour >= 1 && hour <= 12) && (minute >= 0 && minute <=59) && (!strcmp(indicator, "AM") || !strcmp(indicator, "PM"))){
        if(!strcmp(indicator,"AM") && hour == 12){
            hour = 0;
        }
        else if(!strcmp(indicator, "PM") && hour != 12){
            hour += 12;
        }
        printf("Time converted in 24-hour clock : %02d:%02d\n", hour, minute);
    }
    else{
        printf("Invalid Time! \n");
    }
	return 0 ;
}
