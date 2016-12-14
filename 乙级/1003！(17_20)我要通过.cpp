#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    scanf(" "); //吃掉输入n时的回车符
    char arr[101];
    for(int i = 0; i < n; i++){
        gets(arr);
        int leftA = 0, midA = 0, rightA = 0;
        int positionA = 0; //A的位置，0表示在P左边（left），1表示在PT之间（mid），2表示在T的右边(right)。
        for(int j = 0; j < 100; j++){
            if (arr[j] == '\0'){
                if (midA == 0){
                    printf("NO\n");
                    break;
                }
                else if (midA >= 1 && leftA == 0 && rightA == 0){
                    printf("YES\n");
                    break;
                }
                else if (rightA == leftA * midA){
                    printf("YES\n");
                    break;
                }
                else{
                    printf("NO\n");
                    break;
                }
            }
            else if (arr[j] != 'P' && arr[j] != 'A' && arr[j] != 'T'){
                printf("NO\n");
                break;
            }
            else if (arr[j] == 'A'){
                if (positionA == 0)
                    leftA++;
                else if (positionA == 1)
                    midA++;
                else if(positionA == 2)
                    rightA++;
            }
            else if (arr[j] == 'P'){
                if (positionA == 0){
                    positionA = 1;
                }
                else{
                    printf("NO\n");
                    break;
                }
            }
            else if (arr[j] == 'T'){
                if (positionA == 1){
                    positionA = 2;
                }
                else{
                    printf("NO\n");
                    break;
                }
            }
        }
    }
    return 0;
}
