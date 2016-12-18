#include <stdio.h>
#define N 100

//长度为m的数组循环右移n位，相当于把数组的后n位和前面的m-n位各自反转，再把整个数组反转

void myreverse(int arr[], int start, int endd){
    int temp;
    for(; start < endd; start++, endd--){
        temp = arr[start];
        arr[start] = arr[endd];
        arr[endd] = temp;
    }
}

int main(){

    int arrlen, m, arr[N];
    scanf("%d%d", &arrlen, &m);
    for(int i = 0; i < arrlen; i++){
        scanf("%d", &arr[i]);
    }

    m %= arrlen; //防止移动位数比序列总数还长

    myreverse(arr, 0, arrlen - m - 1);
    myreverse(arr, arrlen - m, arrlen - 1);
    myreverse(arr, 0, arrlen - 1);

    for(int i = 0; i < arrlen; i++){
        if (i == 0)
            printf("%d", arr[i]);
        else
            printf(" %d", arr[i]);
    }
    printf("\n");
    return 0;
}
