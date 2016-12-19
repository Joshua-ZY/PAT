#include <stdio.h>

//这个题的论述似乎有点问题，在和其他同学交流的时候也有很多人吐槽这个题，所以做的必要性不大

int main(){
    char str1[60], str2[60], str3[60], str4[60];
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    scanf("%s", str4);

    int found_first = 0;
    for(int i = 0; i < 60; i++){
        //找第一对相同的大写字母
        if (str1[i] == str2[i] && str1[i] >= 'A'&& str1[i] <= 'Z' && !found_first){
            int day = str1[i] - 'A' + 1;
            switch(day){
                case(1):printf("MON ");break;
                case(2):printf("TUE ");break;
                case(3):printf("WED ");break;
                case(4):printf("THU ");break;
                case(5):printf("FRI ");break;
                case(6):printf("SAT ");break;
                case(7):printf("SUN ");break;
            }
            found_first = 1;
        }
        //找第二对相同的字符
        else if (str1[i] == str2[i] && found_first){
            int hour;
            if (str1[i] >= '0' && str1[i] <= '9')
                hour = str1[i] - '0';
            else
                hour = str1[i] - 'A' + 10;
            printf("%02d:", hour);
            break;
        }
    }

    for(int i = 0; i < 60; i++){
        if (str3[i] == str4[i] && ((str3[i] >= 'A'&& str3[i] <= 'Z') || (str3[i] >= 'a'&& str3[i] <= 'z'))){
             printf("%02d", i);
             break;
        }
    }
    printf("\n");
    return 0;
}
