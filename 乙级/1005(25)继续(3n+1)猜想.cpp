#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int k, nums[100], is_key[100];
    scanf("%d", &k);
    for(int i =0; i < k; i++){
        scanf("%d", &nums[i]);
        is_key[i] = 1;
    }

    for(int i = 0; i < k; i++){
        if (is_key[i]){
            int num = nums[i];
            while (num != 1){
                if (num % 2 == 0)
                    num /= 2;
                else
                    num = (3 * num + 1) / 2;
                //printf("mid%d\n", num);
                for(int j = 0; j < k; j++){
                    if (num == nums[j]){
                        //printf("==loc%d,value%d\n", j, nums[j]);
                        is_key[j] = 0;
                    }
                }
            }
        }
    }

    //把剩下的数字（关键数）挑出来
    int ans[100], ansnum = 0;
    for(int i = 0; i < k; i++){
        if (is_key[i]){
            ans[ansnum] = nums[i];
            ansnum++;
        }
    }

    sort(ans, ans + ansnum);

    for(int i = ansnum - 1; i >= 0; i--){
        if (i == ansnum - 1)
            printf("%d", ans[i]);
        else
            printf(" %d", ans[i]);
    }
    return 0;
}
