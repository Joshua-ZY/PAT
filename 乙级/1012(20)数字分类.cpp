#include <stdio.h>

int main(){
    int n, a1 = 0, a2 = 0, a2_flag = 1, a3 = 0, a4_sum = 0, a4_n = 0, a5 = 0;
    int num, have_a1 = 0, have_a2 = 0, have_a3 = 0, have_a4 = 0, have_a5 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if (num % 5 == 0){
            if (num % 2 == 0){
                a1 += num;
                have_a1 = 1;
            }

        }
        else if (num % 5 == 1){
            have_a2 = 1;
            if (a2_flag){
                a2 += num;
                a2_flag = 0;
            }
            else{
                a2 -= num;
                a2_flag = 1;
            }
        }
        else if(num % 5 == 2){
            a3++;
            have_a3 = 1;
        }
        else if(num % 5 == 3){
            a4_sum += num;
            a4_n++;
            have_a4 = 1;
        }
        else{
            have_a5 = 1;
            if (num > a5)
                a5 = num;
        }
    }

    float a4 = ((float) a4_sum) / a4_n;

    if (have_a1)
        printf("%d", a1);
    else
        printf("N");

    if (have_a2)
        printf(" %d", a2);
    else
        printf(" N");

    if (have_a3)
        printf(" %d", a3);
    else
        printf(" N");

    if (have_a4)
        printf(" %.1f", a4);
    else
        printf(" N");

    if (have_a5)
        printf(" %d", a5);
    else
        printf(" N");

    printf("\n");
    return 0;
}
