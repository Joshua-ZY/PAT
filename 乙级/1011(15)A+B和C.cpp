#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        long long a, b, c;
        scanf("%I64d%I64d%I64d", &a, &b, &c); // 在windows上输出long long用%I64d,linux下用%lld，因此提交时要换成%lld
        if (a + b > c)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}

//提交版
/*
#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a + b > c)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}
*/
