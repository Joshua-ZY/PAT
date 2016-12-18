#include <stdio.h>
#include <math.h>

int main(){
    int start, endd, prime[10000];
    scanf("%d%d", &start, &endd);

    int pos = 0;
    for(int i = 2; pos <= endd; i++){
        int maxx = sqrt(i), is_prime = 1;
        for(int j = 2; j <= maxx; j++){
            if (i % j == 0){
                is_prime = 0;
                break;
            }
        }
        if(is_prime){
            prime[pos] = i;
            pos++;
        }
    }

    for(int i = start - 1; i <endd; i++){
        if ((i - start + 1) % 10 == 9)
            printf("%d\n", prime[i]);
        else if (i == endd - 1)
            printf("%d\n", prime[i]);
        else
            printf("%d ", prime[i]);
    }
}
