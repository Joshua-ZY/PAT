#include <stdio.h>


int main(){
    int poly[2001] = {0}, power, coeff;
    char mark;
    do{
        scanf("%d%d%c", &coeff, &power, &mark);
        power += 1000;
        poly[power] = coeff;
    }while(mark != '\n');

    //输出
    int first_flag = 1;
    for(int i = 2000; i >= 0; i--){
        if (i == 1000) //常数项求导为0，不输出
            continue;
        else if (poly[i]){
            if (first_flag){
                printf("%d %d",poly[i] * (i - 1000),i - 1001);
                first_flag = 0;
            }
            else
                printf(" %d %d",poly[i] * (i - 1000),i - 1001);
        }
    }
    if (first_flag) //说明没输出过，结果是0多项式，应该输出0 0
        printf("0 0");
    printf("\n");
    return 0;
}
