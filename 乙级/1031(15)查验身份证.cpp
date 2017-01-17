#include <stdio.h>

#define MAXNUM 100

int main() {
	int num, weights[17] = { 7, 9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 }, is_correct[MAXNUM] = { 0 };
	int z_m[11] = { 1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2 };
	char idarr[MAXNUM][19], enter[2];
	scanf("%d", &num); 
	gets_s(enter); //吃掉输入num后面的回车键
	for (int i = 0; i < num; i++) {
		gets_s(idarr[i]);
	}

	int count_wrong = 0;
	for (int i = 0; i < num; i++) {//每个身份证号检查
		int sum = 0, first17_flag = 1;
		for (int j = 0; j < 17; j++) {
			if (idarr[i][j] < '0' || idarr[i][j] > '9') {
				first17_flag = 0;
				count_wrong++;
				break;
			}
			sum += (idarr[i][j] - '0') * weights[j];
		}
		if (first17_flag) {
			if ((z_m[sum % 11]) == (idarr[i][17] - '0') || (z_m[sum % 11]) == 10 && idarr[i][17] == 'X')
				is_correct[i] = 1;
			else
				count_wrong++;
		}
	}
	
	if (count_wrong == 0)
		printf("All passed\n");
	else {
		for (int i = 0; i < num; i++) {
			if (!is_correct[i])
				printf("%s\n", idarr[i]);
		}
	}
	return 0;
}