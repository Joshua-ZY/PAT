#include <stdio.h>

void myprint(int num){
    switch(num){
        case(0):printf("ling");break;
        case(1):printf("yi"); break;
        case(2):printf("er"); break;
        case(3):printf("san"); break;
        case(4):printf("si"); break;
        case(5):printf("wu"); break;
        case(6):printf("liu"); break;
        case(7):printf("qi"); break;
        case(8):printf("ba"); break;
        case(9):printf("jiu"); break;
    }
    return;
}

int main(){
    char arr[101];
    gets(arr);

    int sum = 0;
    int idx = 0;
    while(arr[idx]){
        sum += (arr[idx] - '0');
        idx++;
    }

    int hundreds = sum / 100;
    int tens = sum % 100 / 10;
    int ones = sum %10;

    if (hundreds){
        myprint(hundreds);
        printf(" ");
        myprint(tens);
        printf(" ");
        myprint(ones);
        printf("\n");
    }
    else if (tens){
        myprint(tens);
        printf(" ");
        myprint(ones);
        printf("\n");
    }
    else{
        myprint(ones);
        printf("\n");
    }
    return 0;
}
