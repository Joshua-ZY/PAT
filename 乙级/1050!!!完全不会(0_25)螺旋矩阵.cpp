#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

/*思路：先求矩阵的m、n，再填充矩阵*/

#define MAXNUM 10000

int numarr[MAXNUM], ansarr[MAXNUM][MAXNUM] = { 0 }; //！！！注意，ansarr数组放在int main里是一定会挂的，因为栈上空间肯定不足以放这个数组。但是全局变量可以申请的空间大很多，所以用全局变量就可以

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N;
	scanf("%d", &N);

	//计算螺旋矩阵size
	int row = N, col = 1; //这是数字N差距最大的两个因子
	for (int i = 2; i < sqrt(N); i++) { //最大不用超过N的平方根，再大col就要超过row了
		if (N % i == 0) {
			if (N / i - i < row - col) {
				row = N / i;
				col = i;
			}
		}
	}

	//读入数列并排序
	for (int i = 0; i < N; i++) 
		scanf("%d", &numarr[i]);
	sort(numarr, numarr + N, cmp); //按照降序排序

	//填充矩阵
	int k = 0; //记录在numarr中的点的位置
	int i = 0; //ansarr中的列坐标
	int j = 0; //ansarr中的行坐标
	int col_reduce = 0, row_reduce = 0;
	while (k < N) {
		for (; i < col - col_reduce; i++) {
			ansarr[j][i] = numarr[k];
			k++;
		}
		for (; j < row - row_reduce; j++) {
			ansarr[j][i] = numarr[k];
			k++;
		}
		for (; i >= col_reduce; i--) {
			ansarr[j][i] = numarr[k];
			k++;
		}
		for (; j >= row_reduce; j--) {
			ansarr[j][i] = numarr[k];
			k++;
		}
		col_reduce++; row_reduce++;
	}

	//打印
	for (int idx1 = 0; idx1 < row; idx1++) {
		for (int idx2 = 0; idx2 < col; idx2++) {
			if (idx2 == 0)
				printf("%d", ansarr[idx1][idx2]);
			else
				printf(" %d", ansarr[idx1][idx2]);
		}
		printf("\n");
	}
	return 0;
}