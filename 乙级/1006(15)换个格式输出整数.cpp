#include <stdio.h>

int main(){
    int num, hunds, tens, ones;
    scanf("%d", &num);
    hunds = num / 100;
    tens = num % 100 / 10;
    ones = num % 10;
    for (int i = 0; i < hunds; i++)
        printf("B");
    for (int i = 0; i < tens; i++)
        printf("S");
    for (int i = 0; i < ones; i++)
         printf("%d", i + 1);
    printf("\n");
    return 0;
}
