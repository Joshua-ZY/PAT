#include <stdio.h>

/*思路：按照正反顺序遍历序列两次，从左到右的时候，记录最大值并不断更新，如果一个值成为过最大值，说明左边
的值都比它小，记录下这个点；从右到左时，记录最小值并不断更新，如果一个值成为过最小值，说明右边的值都比它大，
也记录下这个点。最后统计两个记录，如果一个点即成为过最小值，又成为过最大值，那就可能是主元。*/

#define MAXNUM 100000

int main() {
	int num, numarr[MAXNUM], isMin[MAXNUM] = { 0 }, isMax[MAXNUM] = { 0 };
	scanf("%d", &num);
	//读入数据以及正序遍历
	int maxleft = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &numarr[i]);
		if (numarr[i] > maxleft) {
			maxleft = numarr[i];
			isMax[i] = 1;
		}
	}

	//逆序遍历
	int minright = 1000000001;
	for (int i = num - 1; i >= 0; i--) {
		if (numarr[i] < minright) {
			minright = numarr[i];
			isMin[i] = 1;
		}
	}
	//统计个数，需要遍历一次
	int count = 0;
	for (int i = 0; i < num; i++) {
		if (isMax[i] && isMin[i])
			count++;
	}
	printf("%d\n", count);

	//输出既是max也是min的点
	int first_flag = 1;
	for (int i = 0; i < num; i++) {
		if (isMax[i] && isMin[i]) {
			if (first_flag) {
				printf("%d", numarr[i]);
				first_flag = 0;
			}
			else {
				printf(" %d", numarr[i]);
			}
		}
	}
	printf("\n");
	return 0;
}