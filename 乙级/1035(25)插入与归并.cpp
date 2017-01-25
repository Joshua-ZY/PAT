#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXNUM 100

int if_merge(int originarr[], int midarr[], int len, int num) {
	int part = num / len;
	int last_flag = 0; //如果最后剩下长度不够的一部分，这一部分也要是排序好的
	if (num % len)
		last_flag = 1;
	/*利用merge sort的特点，每一小段都是排序好的。因此最初的想法是查看是不是每一小段的前面的值都比后面的值小
	如果是，那就是merge sort，如果不是，那就是insertion sort。但是这个想法有误判的可能。比如原始的数列是
	5 4 3 2 1 6 7 8，经过insertion sort插入4次后，答案为1 2 3 4 5 6 7 8，但是这个答案会被判断为是merge 
	sort的结果，因为符合每个小段4个点（1 2 3 4和5 6 7 8）的情况。但是这很明显不是merge sort，因为每个小段
	里的值和最初小段里的值是不同的，如果是merge sort的话，进行到这一步的时候，前面小段的四个点还是最初的5 4 3 2
	四个点，只是顺序变成了2 3 4 5而已。这也说明，题目告诉你最初序列并不是没用的！每个条件都是有用的！因此修改
	判定方法，改成利用merge sort的思路在对应的每一个小段里对最初序列排序，如果的某一步和题目给出的中间序列完全
	一样，那就确定一定是merge sort无疑。*/
	for (int i = 0; i < part; i++) {
		sort(originarr + i * len, originarr + (i + 1) * len);
		for (int j = i * len + 1; j < (i + 1) * len; j++) {
			if (midarr[j] != originarr[j])
				return 0;
		}
	}
	if (last_flag) {
		sort(midarr + part * len, midarr + num);
		for (int j = part * len + 1; j < num; j++) {
			if (midarr[j] != originarr[j])
				return 0;
		}
	}
	return len;
}

void mergeOneMore(int midarr[], int len, int num) {
	len *= 2;
	int part = num / len;
	int last_flag = 0; //如果最后剩下长度不够的一部分，这一部分也要是排序好的
	if (num % len)
		last_flag = 1;
	for (int i = 0; i < part; i++) 
		sort(midarr + i * len, midarr + (i + 1) * len);
	if (last_flag)
		sort(midarr + part * len, midarr + num);
}

void insertOneMore(int midarr[], int num) {
	for (int i = 1; i < num; i++) {
		if (midarr[i - 1] > midarr[i]) {
			int temp = midarr[i];
			for (int j = 0; j < i; j++) {
				if (midarr[j] > temp) {//第一个比temp大的值的位置就是temp的位置
					//从j开始，向后移动一个位置
					for (int p = i; p > j; p--) {
						midarr[p] = midarr[p - 1];
					}
					midarr[j] = temp;
					return;
				}
			}
		}
	}
}

int main() {
	int num, arr[MAXNUM], midarr[MAXNUM];
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < num; i++)
		scanf("%d", &midarr[i]);

	int insert_len;
	for (int len = 2; len < num; len *= 2) {
		insert_len = if_merge(arr, midarr, len, num);
		if (insert_len) {
			printf("Merge Sort\n");
			mergeOneMore(midarr, insert_len, num);
			printf("%d", midarr[0]);
			for (int i = 1; i < num; i++)
				printf(" %d", midarr[i]);
			printf("\n");
			return 0;
		}
	}
	printf("Insertion Sort\n");
	insertOneMore(midarr, num);
	printf("%d", midarr[0]);
	for (int i = 1; i < num; i++)
		printf(" %d", midarr[i]);
	printf("\n");
	return 0;
}